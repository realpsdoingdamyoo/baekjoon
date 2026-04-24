#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e15;

int K;
int A[512][512], DP[512][512];

signed main() {
    fastio;

    cin >> K;
    for (int i=0; i<1<<K; i++) for (int j=0; j<1<<K; j++) cin >> A[i][j], DP[i][j]=inf*!!i;
    for (int i=1; i<(1<<K); i++) for (int j=0; j<1<<K; j++) for (int p=0; p<1<<K; p++) if (p!=j) {
        int ld=31-__builtin_clz(j^p);
        if ((i&((1<<ld)-1)) || !(i&(1<<ld))) continue;
        DP[i][p]=min(DP[i][p], DP[i-1][j]+A[j][p]);
    }

    int ans=inf;
    for (int i=0; i<1<<K; i++) ans=min(ans, DP[(1<<K)-1][i]);
    cout << ans;

    return 0;
}
