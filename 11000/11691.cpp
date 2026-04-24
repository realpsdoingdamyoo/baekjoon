#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
const int mod=1e9+7, MOD=998244353, inf=2e17;

int N;
int P[1010101], ep[1010101], dp[1010101], R;

signed main() {
    fastio;

    cin >> N;
    for (int i=1; i<=N; i++) P[i]=i, ep[i]=1;
    for (int i=2; i<=N; i++) if (P[i]==i) for (int j=i; j<=N; j+=i) P[j]=min(P[j], i), ep[j]*=i-1;
    for (int i=2; i<=N; i++) dp[i]=dp[i/P[i]]+!!(i/P[i]%P[i]);
    for (int d=1; d<=N; d++) {
        int A=(d*(N/d)*(N/d+1)/2%mod)*((N/d)*(N/d+1)/2%mod)%mod*ep[d]%mod;
        R+=A*(dp[d]%2?-1:1);
    }
    R-=N*(N+1)/2;
    if (R%2) R+=mod;
    R/=2;
    cout << (R%mod+mod)%mod;


    return 0;
}
