#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e9;

int L, N, M;
int C[3030], D[3030], fac[3030]={1};

int inv(int x, int y=mod-2) {
    int r=1;
    while (y) {
        if (y&1) r=r*x%mod;
        x=x*x%mod; y>>=1;
    } return r;
}

int DP[3030][3030];

int getdp(int K) {
    DP[1][1]=1;
    for (int i=2; i<=K; i++) {
        for (int j=1; j<=i; j++) {
            if (i%2==0) DP[i][j]=DP[i-1][j-1];
            else DP[i][j]=(DP[i-1][i-1]-DP[i-1][j-1]+mod)%mod;
            DP[i][j]=(DP[i][j]+DP[i][j-1])%mod;
        }
    }
    return DP[K][K];
}

signed main() {
    fastio;

    cin >> L;
    for (int i=1; i<=L; i++) fac[i]=fac[i-1]*i%mod;
    cin >> N;
    for (int i=1, p=1; i<=N; i++) {
        int x; cin >> x;
        C[p]=1; p+=x;
    }
    cin >> M;
    for (int i=1, p=1; i<=M; i++) {
        int x; cin >> x;
        D[p]=1; p+=x;
    }

    for (int i=1; i<=L; i++) C[i]=(C[i]^D[i])*(1+C[i-1]);
    int ans=1, sum=0;
    for (int i=1; i<=L; i++) if (C[i] && !C[i+1]) ans=ans*getdp(C[i])%mod*inv(fac[C[i]])%mod, sum+=C[i];
    ans=ans*fac[sum]%mod;
    cout << sum << " " << ans;

    return 0;
}
