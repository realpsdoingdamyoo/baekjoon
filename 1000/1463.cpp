#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e17;

int dp[1010101];

signed main() {
    fastio;

    int n; cin >> n;
    for (int i=2; i<=n; i++) {
        dp[i]=min(dp[i-1], min(dp[i/3]+(i%3)*inf, dp[i/2]+(i%2)*inf))+1;
    }
    cout << dp[n];


    return 0;
}
