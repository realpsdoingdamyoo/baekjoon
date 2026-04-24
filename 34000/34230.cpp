#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;

int n;
int v[5050];
const int MX=4096;
int DP[2][5050][MX];

signed main(){
    fastio;

    cin >> n;
    for (int i=1; i<=n; i++) cin >> v[i];
    for (int i=1; i<=n; i++) {
        int X=0;
        for (int j=0; j<=MX; j++) DP[0][i][j]=DP[1][i][j]=-inf;

        for (int j=i; j>=1; j--) {
            X^=v[j];
            if (X>0) DP[0][i][X]=max(DP[0][i][X], DP[1][j-1][X-1]+1);
            if (X<MX-1) DP[1][i][X]=max(DP[1][i][X], DP[0][j-1][X+1]+1);
        }
        for (int j=MX-2; j>=0; j--) DP[0][i][j]=max(DP[0][i][j], DP[0][i][j+1]);
        for (int j=1; j<MX; j++) DP[1][i][j]=max(DP[1][i][j], DP[1][i][j-1]);
    }
    cout << n-max(DP[0][n][0], DP[1][n][MX-1]);

    return 0;
}
