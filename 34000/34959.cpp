#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;

int N, M;
vector<int> lnk[202020];

int DP[202020], S[202020], R[202020];

int fac[202020]={1};

int inv(int x) {
    int r=1, p=mod-2;
    while (p) {
        if (p&1) r=r*x%mod;
        x=x*x%mod; p>>=1;
    } return r;
}


void dfs(int p, int x) {
    S[p]=1; DP[p]=1;
    for (int i : lnk[p]) if (i!=x) {
        dfs(i, p); S[p]+=S[i]; DP[p]=DP[p]*DP[i]%mod*S[i]%mod;
    }
}

void rrt(int p, int x) {
    int RP=R[p];
    for (int i : lnk[p]) if (i!=x) RP=RP*DP[i]%mod*S[i]%mod;
    for (int i : lnk[p]) if (i!=x) {
        R[i]=RP*(N-S[i])%mod*inv(DP[i]*S[i]%mod)%mod;
        rrt(i, p);
    }
}

signed main(){
    fastio;

    cin >> N >> M;
    for (int i=1; i<=200000; i++) fac[i]=fac[i-1]*i%mod;
    if (M>=N) {cout << "0"; return 0;}

    for (int i=1; i<=M; i++) {
        int a, b; cin >> a >> b;
        lnk[a].push_back(b);
        lnk[b].push_back(a);
    }

    dfs(1, 0);
    R[1]=1; rrt(1, 0);

    int ans=0;
    for (int i=1; i<=N; i++) {
        ans+=fac[N-1]*inv(DP[i]*R[i]%mod)%mod;
    }
    cout << ans%mod;

    return 0;
}
