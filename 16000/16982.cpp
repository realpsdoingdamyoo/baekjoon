#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
const int mod=1e9+7, inf=2e9;

int N, A[440], G[3], L[3][440], F[440][3], DP[401][401][401][3];

signed main() {
    fastio;

    cin >> N;
    for (int i=1; i<=N; i++) {
        char x; cin >> x; A[i]=(x>='R')+(x>='Y');
        L[A[i]][++G[A[i]]]=i; memcpy(F[i], G, 12);
    }

    for (int i=0; i<=N; i++) for (int j=0; j<=N; j++) for (int k=0; k<=N; k++) for (int l=0; l<3; l++) DP[i][j][k][l]=inf;
    for (int i=N; i>=1; i--) {if (A[i]==0) DP[1][0][0][0]=i-1; if (A[i]==1) DP[0][1][0][1]=i-1; if (A[i]==2) DP[0][0][1][2]=i-1;}

    for (int i=0; i<=G[0]; i++) for (int j=0; j<=G[1]; j++) for (int k=0; k<=G[2]; k++) if (i+j+k>=2) {
        if (i) DP[i][j][k][0]=min(DP[i-1][j][k][1], DP[i-1][j][k][2])+max(F[L[0][i]][1]-j, 0)+max(F[L[0][i]][2]-k, 0);
        if (j) DP[i][j][k][1]=min(DP[i][j-1][k][2], DP[i][j-1][k][0])+max(F[L[1][j]][2]-k, 0)+max(F[L[1][j]][0]-i, 0);
        if (k) DP[i][j][k][2]=min(DP[i][j][k-1][0], DP[i][j][k-1][1])+max(F[L[2][k]][0]-i, 0)+max(F[L[2][k]][1]-j, 0);
    }

    int ans=min({DP[G[0]][G[1]][G[2]][0], DP[G[0]][G[1]][G[2]][1], DP[G[0]][G[1]][G[2]][2]});
    if (ans>=inf) cout << -1; else cout << ans;

    return 0;
}
