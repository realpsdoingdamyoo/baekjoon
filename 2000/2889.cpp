#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=1e18;

int n, m, c;
set<int> lnk[101010];
vector<int> tr;
map<array<int, 2>, int> mp;
int ans[101010];

int vis[101010];
vector<int> cmp; int ec;
void dfs(int p) {
	cmp.push_back(p); vis[p]=1;
	for (int i : lnk[p]) if (!vis[i]) dfs(i);
}

void Find(int p) {
	while (lnk[p].size()) {
		int x=*lnk[p].begin();
		lnk[p].erase(lnk[p].find(x)); lnk[x].erase(lnk[x].find(p));
		Find(x);
	}
	tr.push_back(p);
}

signed main() {
	fastio;

	cin >> n >> m;
	for (int i=1; i<=m; i++) {
		int a, b; cin >> a >> b;
		lnk[a].insert(b); lnk[b].insert(a);
		mp[{min(a, b), max(a, b)}]=i;
	}

	for (int i=1; i<=n; i++) if (!vis[i]) {
		cmp.clear();
		dfs(i); ec=0;
		for (int j : cmp) ec+=(lnk[j].size()!=2);

		if (cmp.size()%2 && ec==0) {cout << "0"; return 0;}
		for (int j : cmp) if (lnk[j].size()%2) {
			lnk[0].insert(j); lnk[j].insert(0);
		}
		tr.clear();
		int x=0;
		for (int j : cmp) if (lnk[j].size()>lnk[x].size()) x=j;
		Find(x);

		for (int j=0; j<tr.size()-1; j++) {
			ans[mp[{min(tr[j], tr[j+1]), max(tr[j], tr[j+1])}]]=c+1; c^=1;
		}
	}

	for (int i=1; i<=m; i++) cout << ans[i] << "\n";

	return 0;
}
