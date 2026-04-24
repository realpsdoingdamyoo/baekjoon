#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e9;

signed main() {
    fastio;

    int T; cin >> T;
    while (T--) {
        int N; cin >> N;
        char x, y, z; cin >> x;
        for (int i=1; i<=N; i++) {
            cin >> y >> z;
            if (z=='!' || x=='!' || x+z-2*'0'>9) x='!';
            else x+=z-'0';
        }
        cout << x << "\n";
    }

    return 0;
}
