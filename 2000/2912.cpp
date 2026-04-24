#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=1e18;

int n, c, m;
int v[303030];
vector<int> col[10101];

signed main() {
	fastio;
	srand(1557);

	cin >> n >> c;
	for (int i=1; i<=n; i++) {cin >> v[i]; col[v[i]].push_back(i);}
	cin >> m;
	for (int i=1; i<=m; i++) {
		int a, b; cin >> a >> b;
		int ans=-1;
		for (int j=0; j<100; j++) {
			int x=v[rand()%(b-a+1)+a];
			if (upper_bound(col[x].begin(), col[x].end(), b)-lower_bound(col[x].begin(), col[x].end(), a)>(b-a+1)/2) ans=x;
		}
		if (ans==-1) cout << "no\n";
		else cout << "yes " << ans << "\n";
	}


	return 0;
}
