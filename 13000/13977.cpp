#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;

int fac[4040404]={1}, ifac[4040404];

signed main(){
    fastio;

    for (int i=1; i<=4040400; i++) fac[i]=fac[i-1]*i%mod;
    ifac[4040400]=844537597; for (int i=4040399; i>=0; i--) ifac[i]=ifac[i+1]*(i+1)%mod;

    int T; cin >> T;
    while (T--) {
        int n, k; cin >> n >> k;
        cout << fac[n]*ifac[n-k]%mod*ifac[k]%mod << "\n";
    }

    return 0;
}
