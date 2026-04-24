#include <bits/stdc++.h>
using namespace std;

int n, q;
int v[101010], c[101010], ans[101010];
int u[202020], col[1010101], r;
int sp[101010][20], dep[101010];
vector<int> lnk[101010];
int pv, in[101010], out[101010];
array<int, 4> qry[101010];

void dfs(int p, int pre) {
	u[++pv]=p; in[p]=pv;
	for (int i : lnk[p]) if (i!=pre) sp[i][0]=p, dep[i]=dep[p]+1, dfs(i, p);
	u[++pv]=p; out[p]=pv;
}

void update(int p) {
	r-=!!col[v[p]];
	if (c[p]) col[v[p]]--; else col[v[p]]++;
	r+=!!col[v[p]]; c[p]^=1;
}

int lca(int a, int b) {
	if (dep[a]<dep[b]) swap(a, b);
	for (int i=19; i>=0; i--) if (dep[a]-dep[b]&(1<<i)) a=sp[a][i];
	if (a==b) return a;
	for (int i=19; i>=0; i--) if (sp[a][i]!=sp[b][i]) a=sp[a][i], b=sp[b][i];
	return sp[a][0];
}

signed main() {
	cin >> n;
	for (int i=1; i<=n; i++) cin >> v[i];
	for (int i=1, a, b; i<n; i++) {
		cin >> a >> b;
		lnk[a].push_back(b);
		lnk[b].push_back(a);
	}

	dfs(1, 0);

	for (int j=1; j<20; j++) for (int i=1; i<=n; i++) sp[i][j]=sp[sp[i][j-1]][j-1];

	cin >> q;
	for (int i=1, a, b; i<=q; i++) {
		cin >> a >> b; if (in[a]>in[b]) swap(a, b);
		if (lca(a, b)==a) qry[i]={in[a], in[b], 0, i};
		else qry[i]={out[a], in[b], lca(a, b), i};
	}

	int X=300;
	sort(qry+1, qry+q+1, [&](array<int, 4> a, array<int, 4> b) {return a[0]/X*1e9+a[1]<b[0]/X*1e9+b[1];});

	int s=1, e=0;
	for (int i=1; i<=q; i++) {
		while (s<qry[i][0]) update(u[s++]);
		while (s>qry[i][0]) update(u[--s]);
		while (e<qry[i][1]) update(u[++e]);
		while (e>qry[i][1]) update(u[e--]);
		if (qry[i][2]) update(qry[i][2]);
		ans[qry[i][3]]=r;
		if (qry[i][2]) update(qry[i][2]);
	}

	for (int i=1; i<=q; i++) cout << ans[i] << "\n";

	return 0;
}
