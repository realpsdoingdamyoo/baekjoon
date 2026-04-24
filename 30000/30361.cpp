#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=998244353, inf=4e18;

int fac[101010]={1};

int inv(int x) {
    int r=1, p=mod-2;
    while (p) {
        if (p&1) r=r*x%mod;
        p>>=1; x=x*x%mod;
    }
    return r;
}

int ncr(int n, int r) {
    return fac[n]*inv(fac[r]*fac[n-r]%mod)%mod;
}

void solve() {
    int N, K; cin >> N >> K;
    int X=(int)((N+1-sqrt((N+1)*(N+1)-4*K))/2);
    if (X*(N+1-X)==K) {
        int ans=ncr(N+1, X);
        if (N+1-X==X) ans=ans*inv(2)%mod;
        cout << ans << "\n";
    }
    else cout << "0\n";
}

signed main(){
    fastio;

    for (int i=1; i<=101000; i++) fac[i]=fac[i-1]*i%mod;

    int T; cin >> T;
    while (T--) solve();

    return 0;
}
