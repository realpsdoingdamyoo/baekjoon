#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;

int F1=1, F2=1, F4=1;

int pw(int m, int p){
    int ret=1;
    while(p){
        if(p&1) ret=ret*m%mod;
        m=m*m%mod; p>>=1;
    } return ret;
}

int NCK(int a, int b) {
    return a*pw(b, mod-2)%mod*pw(b, mod-2)%mod;
}

signed main() {
    fastio;

    int N; cin >> N;

    for (int i=1; i<=N/2; i++) F1=F1*i%mod;
    for (int i=1; i<=N; i++) F2=F2*i%mod;
    for (int i=1; i<=N*2; i++) F4=F4*i%mod;

    if (N%2==0) cout << (NCK(F4, F2)-NCK(F2, F1)+mod)*pw(2, mod-2)%mod;
    else cout << NCK(F4, F2)*pw(2, mod-2)%mod;

    return 0;
}
