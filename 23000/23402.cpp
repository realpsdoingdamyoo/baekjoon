#include "bits/stdc++.h"
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=998244353, inf=1e18;

int N, K, G[400][400], DP[400][400][400];
char S[400];

int dp(int i, int j, int k) {
    if (DP[i][j][k]) return DP[i][j][k];
    if (k+(S[i]=='C')<K && dp(i+1, j, G[i][j]-k)==-1) return DP[i][j][k]=1;
    if (k+(S[j]=='C')<K && dp(i, j-1, G[i][j]-k)==-1) return DP[i][j][k]=1;
    return DP[i][j][k]=-1;
}

signed main(){
    fastio;

    cin >> N >> K;
    for (int i=1; i<=N; i++) cin >> S[i];
    for (int i=1; i<=N; i++) for (int j=i; j<=N; j++) for (int k=1; k<=N; k++)
        if (k<i || k>j) G[i][j]+=(S[k]=='C');
    cout << (dp(1, N, 0)==1?"DA":"NE");

    return 0;
}
