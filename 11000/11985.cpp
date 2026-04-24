#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=4e18;

int n, m, k;
int v[20202];
int dp[20202];

signed main() {
    fastio;

    cin >> n >> m >> k;
    for (int i=1; i<=n; i++) cin >> v[i];

    for (int i=1; i<=n; i++) {
        dp[i]=inf;
        int mx=0, mn=inf;
        for (int j=i; j>=max(1LL, i-m+1); j--) {
            mx=max(mx, v[j]); mn=min(mn, v[j]);
            dp[i]=min(dp[i], dp[j-1]+k+(i-j+1)*(mx-mn));
        }
    }

    cout << dp[n];

    return 0;
}
