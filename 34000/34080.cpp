#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e14;

signed main() {
    fastio;

    int T; cin >> T;
    while (T--) {
        int n, x, y; cin >> n >> x >> y;
        if (n*y%(x+y)) cout << "2\n" << n*y/(x+y) << " " << x+y-n*y%(x+y) << "\n" << n*y/(x+y)+1 << " " << n*y%(x+y) << "\n";
        else cout << "1\n" << n*y/(x+y) << " " << x+y << "\n";
    }

    return 0;
}
