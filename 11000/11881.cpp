#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e15;

signed n;
signed v[101010];
int dp[4][101010]={1}, x;

signed main() {
    fastio;

    cin >> n;
    for (int i=1; i<=n; i++) {int a; cin >> a; v[a]++;}
    for (int i=1; i<=100000; i++) {
        x=v[i]*i%mod;
        dp[1][i]=(dp[1][i-1]+x)%mod;
        dp[2][i]=(dp[2][i-1]+dp[1][i-1]*x)%mod;
        dp[3][i]=(dp[3][i-1]+dp[2][i-1]*x)%mod;
    }
    cout << dp[3][100000];

    return 0;
}
