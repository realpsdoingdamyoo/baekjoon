#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=998244353, inf=4e18;

int N, M, ans;
int A[3030], B[110];

int DP[2][110][110][2];
void chmax(int& x, int y){x=max(x, y);}

signed main() {
    fastio;

    cin >> N;
    for (int i=1; i<=N; i++) cin >> A[i];
    N++;

    cin >> M;
    for (int i=1; i<=M; i++) cin >> B[i];

    for (int i=0; i<=1; i++) for (int j=0; j<=M; j++) for (int k=0; k<=M; k++)
        DP[i][j][k][0]=DP[i][j][k][1]=-inf;
    DP[0][0][0][0]=0;

    for (int i=1; i<=N; i++) {
        for (int j=0; j<=M; j++) for (int k=0; k<=M; k++) {
            chmax(DP[1][j][min(k+1, M)][0], DP[0][j][k][0]);
            chmax(DP[1][j][k][1], DP[0][j][k][0]+A[i]);
            chmax(DP[1][j][k][0], DP[0][j][k][1]);
            chmax(DP[1][j+1][k][1], DP[0][j][k][1]+A[i]);
        }

        swap(DP[0], DP[1]);
        for (int j=0; j<=M; j++) for (int k=0; k<=M; k++) DP[1][j][k][0]=DP[1][j][k][1]=-inf;
    }

    sort(B+1, B+M+1); reverse(B+1, B+M+1);
    for (int i=1; i<=M; i++) B[i]+=B[i-1];

    for (int i=0; i<=M; i++) for (int j=0; j<=M; j++) {
        int S;
        if (j<M-i) S=j+(M-i-j)/2; else S=M-i;
        ans=max(ans, max(DP[0][i][j][0], DP[0][i][j][1])+B[S]);
    }

    cout << ans;

    return 0;
}
