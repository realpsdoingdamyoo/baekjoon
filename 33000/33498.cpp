#include <bits/stdc++.h>
using namespace std;
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

int N;
int C[777][777];
int DP[777][777];
int S[777][777];

signed main(){
    fastio;

    cin >> N;
    for (int i=2; i<=N; i++) for (int j=1; j<i; j++) cin >> C[j][i];
    for (int i=1; i<=N; i++) for (int j=1; j<=N; j++) S[i][j]=S[i][j-1]+S[i-1][j]-S[i-1][j-1]+max(0, -C[i][j]);

    for (int i=N; i>=1; i--) for (int j=i+1; j<=N; j++) {
        DP[i][j]=2147483647;
        for (int k=i; k<j; k++) {
            int R=DP[i][k]+DP[k+1][j]+max(0, C[i][k+1]);
            R+=S[k][j]-S[k][k]-S[i][j]+S[i][k];
            DP[i][j]=min(DP[i][j], R);
        }
    }
    cout << DP[1][N] << "\n";


    return 0;
}
