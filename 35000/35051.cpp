#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e9;

int DP[1010101][2];

void solve() {
    DP[0][1]=inf;
    string a, b; cin >> a >> b;
    int N=a.length();
    a=" "+a; b=" "+b;
    for (int i=1; i<=N; i++) {
        DP[i][0]=min(DP[i-1][0]+(b[i]!='0')+(a[i]!='0'), DP[i-1][1]+(b[i]!='0')+(a[i]!='1'));
        DP[i][1]=min(DP[i-1][0]+(b[i]!='1')+(a[i]!='1'), DP[i-1][1]+(b[i]!='1')+(a[i]!='0'));
    }
    cout << min(DP[N][0], DP[N][1]) << "\n";
}

signed main() {
    fastio;

    int T; cin >> T;
    while (T--) solve();

    return 0;
}
