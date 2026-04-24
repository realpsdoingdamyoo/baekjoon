#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=1e15;

int n, m;
vector<array<int, 2>> lnk[202020];
int vis[202020], par[202020], prn[202020], dep[202020];
array<int, 3> e;

void dfs(int p) {
	vis[p]=1;
	for (array<int, 2> i : lnk[p]) if (!vis[i[0]])
		par[i[0]]=p, prn[i[0]]=i[1], dep[i[0]]=dep[p]+1, dfs(i[0]);
}

signed main() {
	fastio;

	cin >> n >> m;
	for (int i=1; i<=m; i++) {
		int a, b; cin >> a >> b;
		lnk[a].push_back({b, i});
		lnk[b].push_back({a, i});
	}
	dfs(1);
	for (int i=1; i<=n; i++) for (array<int, 2> j : lnk[i]) if (dep[i]<dep[j[0]] && par[j[0]]!=i)
		e=max(e, {min(dep[i], dep[j[0]]), i, j[0]});

	cout << dep[e[2]]-dep[e[1]]+1 << "\n";
	for (array<int, 2> i : lnk[e[1]]) if (i[0]==e[2]) cout << i[1] << " ";
	while (e[2]!=e[1]){cout << prn[e[2]] << " "; e[2]=par[e[2]];}

	return 0;
}
