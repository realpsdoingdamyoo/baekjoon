#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;

int N, M, K;
int A[53][53], B[53][53];
int R=inf;
array<int, 3> V[10];

void rtt(int R, int C, int S) {
    if (S==0) return;
    for (int i=R-S+1; i<=R+S; i++) swap(B[i][C-S], B[i-1][C-S]);
    for (int j=C-S+1; j<=C+S; j++) swap(B[R+S][j], B[R+S][j-1]);
    for (int i=R+S-1; i>=R-S; i--) swap(B[i][C+S], B[i+1][C+S]);
    for (int j=C+S-1; j>C-S; j--) swap(B[R-S][j], B[R-S][j+1]);
    rtt(R, C, S-1);
}

signed main(){
    fastio;

    cin >> N >> M >> K;
    for (int i=1; i<=N; i++) for (int j=1; j<=M; j++) cin >> A[i][j];
    for (int i=1; i<=K; i++) cin >> V[i][0] >> V[i][1] >> V[i][2];
    sort(V+1, V+K+1);

    do {
        memcpy(B, A, sizeof B);
        for (int i=1; i<=K; i++) rtt(V[i][0], V[i][1], V[i][2]);
        for (int i=1; i<=N; i++) {
            int S=0;
            for (int j=1; j<=M; j++) S+=B[i][j];
            R=min(R, S);
        }
    } while (next_permutation(V+1, V+K+1));
    cout << R;

    return 0;
}
