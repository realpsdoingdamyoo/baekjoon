#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=1e18;

int k, m, r=1, c;
int lnk[10101010], sp[10101010];

void solve(int p) {
	while (sp[p]<k) {
		int x=(p*k+sp[p])%r; sp[p]++;
		solve(x);
	}
	if (c++<k*r) cout << p%k << " ";
}

signed main() {
	fastio;

	cin >> k >> m;
	if (m==1) {
		for (int i=0; i<k; i++) cout << i << " ";
		return 0;
	}
	for (int i=1; i<m; i++) r*=k;
	for (int i=0; i<r*k; i++) lnk[i]=1;
	solve(0);

	return 0;
}
