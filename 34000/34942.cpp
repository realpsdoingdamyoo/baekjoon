#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e17;

int N, A[1010101], B[1010101], S=1, P[1010101];

int mpw(int x, int y) {
    int r=1;
    while (y) {
        if (y&1) r=r*x%MOD;
        x=x*x%MOD; y>>=1;
    } return r;
}
int inv(int x){return mpw(x, MOD-2);}

signed main() {
    fastio;

    cin >> N;
    for (int i=1; i<=N; i++) cin >> A[i], B[i]=A[i], S=S*A[i]%MOD;
    sort(B+1, B+N+1);

    for (int i=1; i<=N; i++) {
        int v=mpw(B[i], N-i+1)*inv(S*(N-i+1)%MOD)%MOD;
        int l=B[i-1]*inv(B[i])%MOD;
        P[i]=v*(1-mpw(l, N-i+1)+MOD)%MOD;
        P[i]=(P[i-1]+P[i])%MOD;
        S=S*inv(B[i])%MOD;
    }

    for (int i=1; i<=N; i++) {
        int x=lower_bound(B+1, B+N+1, A[i])-B;
        cout << P[x] << "\n";
    }

    return 0;
}
