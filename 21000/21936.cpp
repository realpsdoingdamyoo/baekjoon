#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
const int mod=1e9+7, MOD=998244353, inf=2e17;

int N, M;
char C[2020];
int E[2020];
int S[2020][2020], DP[2020][2020];

signed main() {
    fastio;

    string s; cin >> s;
    N=s.length();
    for (int i=1; i<=N; i++) C[i]=s[i-1];
    cin >> M;

    for (int i=1; i<=N; i++) for (int j=0; i+j<=N; j++) {
        S[j+1][i+j]=S[j][i+j-1]+(C[j+1]==C[i+j] && S[j][i+j-1]==j);
        if (S[j+1][i+j]==j+1 && i!=1) E[i+j]=max(E[i+j], j+1);
    }
    for (int i=1; i<=N; i++) for (int j=1; j<=N; j++) S[i][j]+=S[i-1][j];


    for (int i=1; i<=M; i++) {
        for (int j=1; j<=i; j++) DP[i][j]=DP[i-j+E[j]][E[j]]+(S[j][j]-S[E[j]][j]);
        for (int j=N; j>=0; j--) DP[i][j]=max(DP[i][j], DP[i][j+1]);
    }
    cout << DP[M][0];

    return 0;
}
