#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=998244353, inf=1e12;

int M, N, cnt;
char S[70707];
int A[70707], U[70707];
int F[70707][11], G[70707][11][11];
void chmin(int& x, int y, int z=inf){x=min({x, y, z});}

signed main() {
    fastio;

    cin >> M;
    for (int i=1, b=1; i<=M; i++) {
        cin >> S[i];
        if (S[i]=='e') cnt+=2, b=1;
        else ++N, U[N]=b, b=0, A[N]=S[i]-'a';
    }

    for (int i=0; i<=10; i++) for (int j=0; j<=10; j++) F[0][i]=G[0][i][j]=inf;
    F[0][A[1]]=0;

    for (int i=1; i<=N; i++) for (int j=0; j<=10; j++) {
        F[i][j]=inf;
        if (j!=A[i] && !U[i]) chmin(F[i][j], F[i-1][j]);
        if (j!=A[i]) chmin(F[i][j], G[i-1][A[i]][j]);
        chmin(F[i][j], F[i-1][A[i]]+2, G[i-1][A[i]][A[i]]+2);

        for (int k=0; k<=10; k++) {
            G[i][j][k]=inf;
            if (j!=A[i] && k!=A[i]) chmin(G[i][j][k], G[i-1][j][k]+1);
            if (j!=A[i]) chmin(G[i][j][k], F[i-1][j]+3, G[i-1][j][A[i]]+3);
            if (k!=A[i]) chmin(G[i][j][k], G[i-1][A[i]][k]+3);
            chmin(G[i][j][k], F[i-1][A[i]]+5, G[i-1][A[i]][A[i]]+5);
        }
    }
    cout << F[N][10]+cnt-2;

    return 0;
}
