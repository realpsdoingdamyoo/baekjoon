#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ULL unsigned long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e14;

int n;
int S[160];
bitset<1234567> v[160];

signed main() {
    fastio;

    cin >> n;
    for (int i=1; i<=n; i++) cin >> S[i];
    v[0].set(0, 1);

    for (int i=1; i<=n+1; i++) {
        int ad=0;
        for (int j=i-1; j>=0; j--) {
            v[i]|=v[j]<<ad;
            ad+=S[j]*(i-j);
        }
    }

    int k; cin >> k;
    if (1234567<=k) cout << k;
    else {
        for (int j=k; j<1234567; j++) {
            if (v[n+1][j]==0) {
                cout << j; return 0;
            }
        }
    }

    return 0;
}
