#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;

int inv(int x) {
    int r=1, p=mod-2;
    while (p) {
        if (p&1) r=r*x%mod;
        x=x*x%mod; p>>=1;
    } return r;
}

int fac[1010101]={1}, ifac[1010101];

int NCR(int N, int R) {
    return fac[N]*ifac[R]%mod*ifac[N-R]%mod;
}
int NPR(int N, int R) {
    return fac[N]*ifac[N-R]%mod;
}

signed main(){
    fastio;

    int N; cin >> N;

    for (int i=1; i<=N; i++) fac[i]=fac[i-1]*i%mod;
    ifac[N]=inv(fac[N]);
    for (int i=N-1; i>=0; i--) ifac[i]=ifac[i+1]*(i+1)%mod;

    int ans=0;
    for (int K=1; K<=N; K++) ans+=inv(N)*NCR(N, K)%mod*NCR(N, K-1)%mod*NPR(N, K)%mod;
    cout << ans%mod;


    return 0;
}
