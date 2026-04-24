#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e17;

int ans[22]={0, 1, 2, 4, 10, 32, 122, 544, 2770, 15872, 101042, 707584, 5405530, 44736512, 398721962, 3807514624, 38783024290, 419730685952, 4809759350882, 58177770225664, 740742376475050};

signed main(){
    fastio;

    int t; cin >> t;
    while (t--) {
        int N; cin >> N;
        cout << ans[N] << "\n";
    }

    return 0;
}
