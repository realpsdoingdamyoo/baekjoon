#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e17;

int n, k, ans=1;
int v[101010];
int MX=1e9;

int mpw(int x, int p) {
    int ret=1;
    while (p) {
        if (p&1) ret=ret*x%mod;
        x=x*x%mod; p>>=1;
    } return ret;
}

int DP[101010], DPS[101010];
int cal(int N, int X) {
    if (X==1) return 1;
    for (int i=0; i<=N+1; i++) DP[i]=0, DPS[i]=1; DP[0]=1;
    for (int i=1; i<=N+1; i++) {
        DP[i]=(DPS[i-1]-(i-k-1<0?0:DPS[i-k-1])+mod)%mod;
        DP[i]=DP[i]*mpw(X-1, i-1)%mod;
        DPS[i]=(DPS[i-1]+DP[i]*mpw(mpw(X-1, mod-2), i))%mod;
    }
    return DP[N+1];
}

signed main() {
    fastio;

    cin >> n >> k;
    for (int i=1; i<=n-k+1; i++) cin >> v[i];
    if (k==1){cout << "1"; return 0;}

    for (int i=1, j=1; i<=n-k+1; i=j+1) {
        while (j<=n-k && v[i]==v[j+1]) j++;
        int d=k+j-i;
        if (v[i-1]>v[i]) d-=k;
        if (v[j+1]>v[i]) d-=k;
        ans=ans*cal(d, MX-v[i]+1)%mod;
    }
    cout << ans;


    return 0;
}
