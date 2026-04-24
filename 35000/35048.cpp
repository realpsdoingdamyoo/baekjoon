#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e9;
 
int N, K;
double P[101010][35], RP[101010][35];
double F[35][35];
double DP[35][35][35];
 
void fil(int x, int y) {
    double S=0, E=0;
    for (int i=1; i<=N; i++) S+=P[i][y]*RP[i][x-y];
    if (S==0) return;
    for (int i=1; i<=N; i++) E+=P[i][y]*RP[i][x-y]/S*P[i][1];
    F[x][y]=E;
}
 
signed main() {
    fastio;
 
    cin >> N >> K;
    for (int i=1; i<=N; i++) cin >> P[i][1], P[i][1]/=100, P[i][0]=RP[i][0]=1, RP[i][1]=1-P[i][1];
    for (int i=1; i<=N; i++) for (int j=2; j<=K; j++) P[i][j]=P[i][j-1]*P[i][1], RP[i][j]=RP[i][j-1]*RP[i][1];
    for (int i=0; i<=K; i++) for (int j=0; j<=i; j++) fil(i, j);
 
    DP[0][0][0]=1;
    for (int j=0; j<=K; j++) for (int k=0; k<=K; k++) DP[K][j][k]=1LL<<k;
    for (int i=K-1; i>=0; i--) for (int j=0; j<=i; j++) for (int k=0; k<=i; k++)
        DP[i][j][k]=max(DP[i+1][j+1][k+1]*F[i][j],DP[i+1][j+1][k]*F[i][j]+DP[i+1][j][k]*(1-F[i][j]));
 
 
    cout.precision(15);
    cout << (DP[0][0][0]-1)*1000 << "\n";
 
 
    return 0;
}
