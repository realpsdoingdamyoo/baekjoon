#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
const int mod=1e9+7, MOD=998244353, inf=2e17;

int N, D[110][2], DP[110][110], A[110];
char C[110];

int H, W;
void update(int x, int y, int z=0) {
    if (x<0 || x>H || y<0 || y>W || x+y==0 || x+y==N) return;
    if (DP[x][y]) return;
    if (z) {
        DP[x][y]=1;
        update(x+1, y); update(x, y+1);
        update(x-1, y); update(x, y-1);
        return;
    }
    if ((x==0 || DP[x-1][y]) && (y==0 || DP[x][y-1])) {
        DP[x][y]=1;
        update(x+1, y); update(x, y+1);
    }
    if ((x==H || DP[x+1][y]) && (y==W || DP[x][y+1])) {
        DP[x][y]=1;
        update(x-1, y); update(x, y-1);
    }
}

void solve() {
    cin >> N;
    for (int i=1; i<=N; i++) cin >> C[i];
    for (int i=1; i<=N; i++) D[i][0]=D[i-1][0]+(C[i]=='R'), D[i][1]=D[i-1][1]+(C[i]=='B');
    for (int i=0; i<=N+1; i++) for (int j=0; j<=N+1; j++) DP[i][j]=0;
    for (int i=1; i<=N; i++) A[i]=0;
    H=D[N][0]; W=D[N][1];
    for (int t=1; t<=N; t++) {
        for (int i=1; i<=N; i++) if (A[i]==0) {
            int x=D[i-1][0], y=D[i-1][1];
            if ((x==H || DP[x+1][y]) || (y==W || DP[x][y+1])) A[i]=1;
        }
        for (int i=0; i<=H; i++) for (int j=0; j<=W; j++) if (!DP[i][j]) {
            if (A[i+j+1]) {if (!((i==H || DP[i+1][j]) ^ (j==W || DP[i][j+1]))) update(i, j, 1);}
            else {if ((i==H || DP[i+1][j]) || (j==W || DP[i][j+1])) update(i, j, 1);}
        }
    }
    for (int i=1; i<=N; i++) cout << A[i]; cout << "\n";
}

signed main() {
    fastio;

    int T; cin >> T;
    while (T--) solve();

    return 0;
}
