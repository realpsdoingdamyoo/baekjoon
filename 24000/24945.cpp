#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
const int mod=1e9+7, inf=2e18;
const int MX=2525;

int N, A, B, C;
char S[MX];
int E[MX][MX], P[MX][MX], DP[MX][MX];

signed main() {
    fastio;

    cin >> N;
    for (int i=1; i<=N; i++) cin >> S[i];
    cin >> A >> B >> C;

    for (int i=N; i>=1; i--) {
        for (int j=i-1; j>=1; j--) {
            if (S[i]==S[j]) E[i][j]=min(E[i+1][j+1]+1, i-j);
            P[i][E[i][j]]=max(P[i][E[i][j]], j);
        }
        for (int j=N; j>=1; j--) P[i][j]=max(P[i][j], P[i][j+1]);
    }

    for (int i=0; i<=N; i++) for (int j=0; j<=N; j++) DP[i][j]=inf;
    for (int i=1; i<=N; i++) DP[i][i]=A;

    for (int D=1; D<N; D++) for (int i=1, j=D; j<=N; i++, j++) {
        DP[i-1][j]=min(DP[i-1][j], DP[i][j]+A);
        DP[i][j+1]=min(DP[i][j+1], DP[i][j]+A);
        int p=i;
        for (int k=1; p=P[p][D]; k++) {
            if (j-p+1-D*(k+1)<0) break;
            DP[p][j]=min(DP[p][j], DP[i][j]+B+C*(k+1)+(j-p+1-D*(k+1))*A);
        }
    }
    cout << DP[1][N];


    return 0;
}
