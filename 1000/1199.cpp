#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=1e18;

int n;
vector<int> lnk[1010];
int out[1010][1010];

void solve(int p) {
	while (lnk[p].size()) {
		int x=lnk[p].back();
		if (out[p][x]) {out[p][x]--; lnk[p].pop_back();}
		else {out[p][x]++; out[x][p]++; solve(x);}
	}
	cout << p << " ";
}

signed main() {
	fastio;

	cin >> n;
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=n; j++) {
			int a; cin >> a;
			while (a--) lnk[i].push_back(j);
		}
		if (lnk[i].size()%2){cout << "-1"; return 0;}
	}

	solve(1);

	return 0;
}
