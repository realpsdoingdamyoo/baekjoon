#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
const int mod=1e9+7, inf=2e18;

int N, M, ans;
int A[101010], F[101010]={1};
int C[1<<20], DP[1<<20]={}, S[1<<20]={};

int g(int K) {
    int r=0, c=1;
    for (int i=K; i>=1; i--) c=c*i%mod, r+=c;
    return r%mod;
}

signed main() {
    fastio;

    cin >> N >> M;
    for (int i=0; i<M; i++) {
        for (int j=1; j<=N; j++) {
            char c; cin >> c;
            if (c=='H') A[j]^=1<<i;
        }
    }
    for (int i=1; i<=N; i++) C[A[i]]++;

    for (int i=1; i<=N; i++) F[i]=F[i-1]*i%mod;

    for (int k=0; k<=M; k++) {
        for (int i=0; i<1<<M; i++) if (__popcount(i)<k) S[i]=DP[i]; else S[i]=0;
        for (int j=0; j<M; j++) for (int i=0; i<1<<M; i++) if (i&1<<j) S[i]=(S[i]+S[i^(1<<j)])%mod;
        for (int i=0; i<1<<M; i++) if (__popcount(i)==k) ans+=DP[i]=(S[i]+1)*g(C[i])%mod;
    }
    cout << ans%mod;

    return 0;
}
