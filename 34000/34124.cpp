#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
const int mod=1e9+7, MOD=998244353, inf=2e18;

signed main() {
    fastio;

    int t; cin >> t;
    while (t--) {
        int n, a; cin >>  n >> a;
        if (n==2 && a==2) cout << "O\n";
        else cout << (n%2?"O\n":"I\n");
    }

    return 0;
}
