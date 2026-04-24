#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=1e15;

int n;
string s;
int sp[101010][20], sa[101010], u[101010];
array<int, 2> ssp[101010][20];

void comp(int x) {
	vector<int> cmp={0};
	for (int i=1; i<=n; i++) cmp.push_back(sp[i][x]);
	sort(cmp.begin(), cmp.end());
	cmp.erase(unique(cmp.begin(), cmp.end()), cmp.end());
	for (int i=1; i<=n; i++) sp[i][x]=lower_bound(cmp.begin(), cmp.end(), sp[i][x])-cmp.begin();
}

int ovp(int x, int y) {
	int ret=0;
	for (int i=19; i>=0; i--) {
		if (max(x, y)+(1<<i)-1>n) continue;
		if (sp[x][i]==sp[y][i]) x+=1<<i, y+=1<<i, ret+=1<<i;
	}
	return ret;
}

int Min(int s, int e) {
	int w = 31-__builtin_clz(e-s+1);
	array<int, 2> ret=min(ssp[s][w], ssp[e-(1<<w)+1][w]);
	return ret[1];
}

int slv(int s, int e) {
	if (s>e) return 0;
	int p=Min(s, e);
	return max(max(slv(s, p-1), slv(p+1, e)), sa[p]*(e-s+2));
}

signed main() {
	fastio;

	cin >> s; n=s.length(); s=" "+s;
	for (int i=1; i<=n; i++) sp[i][0]=s[i], u[i]=i;
	comp(0);

	for (int j=1; j<20; j++) {
		for (int i=1; i<=n; i++) sp[i][j]=sp[i][j-1]*mod+(i+(1<<j-1)>n?0:sp[i+(1<<j-1)][j-1]);
		comp(j);
	}

	sort(u+1, u+n+1, [&](int a, int b){return sp[a][19]<sp[b][19];});
	for (int i=1; i<n; i++) sa[i]=ovp(u[i], u[i+1]);
	for (int i=1; i<=n; i++) ssp[i][0]={sa[i], i};
	for (int j=1; j<20; j++) for (int i=1; i<=n-(1<<j-1); i++) ssp[i][j]=min(ssp[i][j-1], ssp[i+(1<<j-1)][j-1]);
	cout << max(slv(1, n), n);

	return 0;
}
