#include <bits/stdc++.h>
#define int long long
using namespace std;
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
const int mod=1e9+7, MOD=998244353, inf=2e17;

int N, ans=inf;;
int V[16][16], DP[1<<16][16];

signed main() {
    fastio;

    cin >> N; DP[1][0]=-inf;
    for (int i=0; i<N; i++) for (int j=0; j<N; j++) {cin >> V[i][j]; if (!V[i][j]) V[i][j]=inf;}
    for (int i=0; i<1<<N; i++) for (int p=0; p<N; p++) if (i&(1<<p)) for (int j=0; j<N; j++) if (i&(1<<j) && j!=p)
        DP[i][p]=min(DP[i][p], DP[i^(1<<p)][j]+V[j][p]);

    for (int i=1; i<N; i++) ans=min(ans, DP[(1<<N)-1][i]+V[i][0]+inf);
    cout << ans;

    return 0;
}
