#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
const int mod=1e9+7, MOD=998244353, inf=2e17;

int N, V[10101], C[5050], M, U[10101], X=6000;
int DP[10101][5050];

signed main() {
    fastio;

    cin >> N;
    for (int i=1; i<=2*N; i++) {
        char c; cin >> c >> V[i];
        C[V[i]]++; if (c=='O') V[i]+=X;
    }
    for (int i=1, j=0; i<=2*N; i++)
        if (V[i]%X==0 || C[V[i]%X]<2) U[++j]=V[i], M+=V[i]<X;


    DP[0][0]=1;
    int P=M;
    for (int i=1, s=0; i<=M*2; i++) {
        if (U[i]==0) {
            for (int j=0; j<=M; j++) DP[i][j]=DP[i-1][j];
            s++;
        }
        else if (U[i]<X) {
            P--;
            for (int j=1; j<=M; j++) DP[i][j]=DP[i-1][j-1];
            s++;
        }
        else if (U[i]==X) {
            for (int j=0; j<=M; j++) DP[i][j]=(DP[i-1][j]*(s-j)+DP[i-1][j+1]*(j+1))%mod;
            s--;
        }
        else {
            P--;
            for (int j=0; j<M; j++) DP[i][j]=DP[i-1][j]*(s-j)%mod;
            s--;
        }
    }
    int R=DP[M*2][0];
    while (P) R=R*P--%mod;
    cout << R;

    return 0;
}
