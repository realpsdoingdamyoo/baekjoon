#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=1e18;

int n, m, s, e;
vector<int> lnk[101010];

int uf[101010];
vector<int> unn[101010];
set<int> tpc[101010];

void Union(int a, int b) {
	a=uf[a]; b=uf[b];
	if (a==b) return;
	if (unn[a].size()<unn[b].size()) swap(a, b);
	while (unn[b].size()) {
		int p=unn[b].back();
		unn[a].push_back(p); uf[p]=a;
		unn[b].pop_back();
	}
	while (tpc[b].size()) {
		int p=*tpc[b].begin();
		tpc[a].insert(p);
		tpc[b].erase(tpc[b].begin());
	}
}

int tp[101010], tpd[101010];
vector<int> tptree[101010];
int sp[101010][20], dep[101010];
int pv=0, in[101010], out[101010];
int sz[101010], ct[101010];

void dfs(int p) {
	sz[p]=1;
	for (int& i : tptree[p]) {
		dfs(i), sz[p]+=sz[i];
		if (sz[i]>sz[tptree[p][0]]) swap(i, tptree[p][0]);
	}
}

void dfs2(int p) {
	in[p]=++pv;
	for (int i : tptree[p]) {
		if (i==tptree[p][0]) ct[i]=ct[p]; else ct[i]=i;
		dfs2(i);
	}
	out[p]=pv;
}

int gpr(int p, int x) {
	for (int i=0; i<20; i++) if (x&(1<<i)) p=sp[p][i];
	return p;
}

int lca(int a, int b) {
	if (dep[a]<dep[b]) swap(a, b);
	for (int i=19; i>=0; i--) if (dep[a]-dep[b]&(1<<i)) a=sp[a][i];
	if (a==b) return a;
	for (int i=19; i>=0; i--) if (sp[a][i]!=sp[b][i]) a=sp[a][i], b=sp[b][i];
	return sp[a][0];
}

const int X=18;
int seg[1<<X+1];
void update(int p, int x) {
	p+=1<<X;
	while (p) seg[p]=min(seg[p]+x, inf), p>>=1;
}
int sum(int s, int e) {
	s+=1<<X; e+=1<<X; int r=0;
	while (s<=e) {
		if (s&1) r=min(r+seg[s], inf); ++s>>=1;
		if (~e&1) r=min(r+seg[e], inf); --e>>=1;
	}
	return r;
}

void Update(int p, int x) {update(in[p], x);}
int Sum(int a, int b) {
	int r=0;
	if (dep[a]>dep[b]) swap(a, b);
	while (ct[a]!=ct[b]) {
		r=min(r+sum(in[ct[b]], in[b]), inf);
		b=tp[ct[b]];
	}
	r=min(r+sum(in[a]+1, in[b]), inf);
	return r;
}

int cpdp[101010];
vector<array<int, 2>> cptree[101010];

void cp_dfs(int p) {
	for (array<int, 2> i : cptree[p]) {
		cp_dfs(i[0]);
		cpdp[p]=max(cpdp[p], cpdp[i[0]]+i[1]);
	}
	cpdp[p]=min(cpdp[p], inf);
}

bool cmp(int a, int b){return in[a]<in[b];}
void comptree(int p, vector<int> st, vector<int> en) {
	if (en.size()==0) return;
	vector<int> mg;
	for (int i : st) mg.push_back(i);
	for (int i : en) mg.push_back(i);

	sort(mg.begin(), mg.end(), cmp);
	for (int i=mg.size()-2; i>=0; i--) mg.push_back(lca(mg[i], mg[i+1]));
	sort(mg.begin(), mg.end(), cmp);
	mg.erase(unique(mg.begin(), mg.end()), mg.end());

	for (int i=1; i<mg.size(); i++) {
		int x=mg[i], y=lca(mg[i], mg[i-1]);
		cptree[y].push_back({x, Sum(x, y)});
	}

	cp_dfs(mg[0]);

	for (int i : en) tpd[i]=cpdp[i]+1, Update(i, tpd[i]);
	for (int i : mg) cpdp[i]=0, cptree[i].clear();
}

int Move(int p, int x) {
	if (p>x) {
		int ret=-2;
		for (int i : lnk[p]) if (i<=x) ret=max(ret, Move(i, x));
		return ret+1;
	}
	if (gpr(p, dep[p]-dep[x])!=x) return -1;
	return Sum(p, x);
}

signed main() {
	fastio;

	cin >> n >> m >> s >> e;
	for (int i=1; i<=m; i++) {
		int a, b; cin >> a >> b;
		lnk[a].push_back(b);
		lnk[b].push_back(a);
	}

	for (int i=1; i<=n; i++) {
		uf[i]=i, unn[i].push_back(i);
		for (int j : lnk[i]) tpc[i].insert(j);
	}
	for (int i=1; i<n; i++) {
		for (int j : lnk[i]) if (j<i) Union(i, j);
		tp[i]=*tpc[uf[i]].upper_bound(i);
		tptree[tp[i]].push_back(i);
	}

	for (int i=n-1; i>=1; i--) {
		sp[i][0]=tp[i]; dep[i]=dep[tp[i]]+1;
		for (int j=1; j<20; j++) sp[i][j]=sp[sp[i][j-1]][j-1];
	}
	dfs(n); ct[n]=n; dfs2(n);

	for (int i=1; i<=n; i++) {
		vector<int> Lnk;
		for (int j : lnk[i]) if (j<i) Lnk.push_back(j);
		comptree(i, Lnk, tptree[i]);

	}

	int k, ans=0, imp=0; cin >> k;

	for (int i=1; i<=k; i++) {
		int a; cin >> a;
		if (i==1 && a<s) imp=1;
		int sa=Move(s, a);
		if (sa==-1) imp=1;
		ans=min(ans+sa, inf);
		s=a;
	}
	if (imp) cout << "impossible";
	else if (ans==inf) cout << "eternity";
	else cout << ans;



	return 0;
}
