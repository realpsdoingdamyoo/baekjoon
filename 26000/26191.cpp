#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;

mt19937 rd(6969);

int N, M, K;
int C[4][2][1000000], P[2][1000000];
string S[1000000];

inline int g(char x) {
    if (x=='A') return 0;
    if (x=='B') return 1;
    if (x=='C') return 2;
    return 3;
}

signed main() {
    fastio;

    cin >> N >> M >> K;
    int S0=0, S1=0;
    for (int i=0; i<N; i++) {
        P[0][i]=rd(); P[1][i]=rd();
        cin >> S[i];
        for (int j=0; j<M; j++) {
            C[g(S[i][j])][0][j]+=P[0][i];
            C[g(S[i][j])][1][j]+=P[1][i];
        }
        S0+=P[0][i]; S1+=P[1][i];
    }

    for (int i=0; i<N; i++) {
        int V0=0, V1=0;
        for (int j=0; j<M; j++) {
            V0+=C[g(S[i][j])][0][j]-P[0][i];
            V1+=C[g(S[i][j])][1][j]-P[1][i];
        }
        if (V0==(S0-P[0][i])*(M-K) && V1==(S1-P[1][i])*(M-K)) cout << i+1 << "\n";
    }

    return 0;
}
