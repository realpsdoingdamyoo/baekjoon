#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e9;

int N, L, R;
int DP[2020][2020];
int dp(int i, int j){return i>=0&&j>=0?DP[i][j]:0;}

signed main() {
    fastio;

    cin >> N >> L >> R;
    if (L>R) swap(L, R);
    if (N==2){cout << "1"; return 0;}

    DP[0][0]=1;
    for (int i=1; i<=L-1; i++) for (int j=0; j<=N; j++) DP[i][j]=(dp(i-1, j-1)*j+dp(i-1, j+1)*j)%mod;
    for (int j=0; j<=N; j++) DP[L][j]=(dp(L-1, j)+dp(L-1, j-1))%mod;
    for (int i=L+1; i<=R-1; i++) for (int j=0; j<=N; j++) DP[i][j]=(dp(i-1, j-1)*(j-1)+dp(i-1, j+1)*j)%mod;
    for (int j=0; j<=N; j++) DP[R][j]=(dp(R-1, j)+dp(R-1, j-1))%mod;
    for (int i=R+1; i<=N; i++) for (int j=0; j<=N; j++) DP[i][j]=(dp(i-1, j-1)*(j-2)+dp(i-1, j+1)*j)%mod;

    cout << DP[N][1];

    return 0;
}
