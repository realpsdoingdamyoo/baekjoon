#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
const int mod=1e9+7, MOD=998244353, inf=2e18;

int n, m, k;
string s[2020];
int v[4040][4040];

signed main() {
    fastio;

    cin >> n >> m >> k;
    int ans=k*k;
    for (int i=1; i<=n; i++) {
        cin >> s[i]; s[i]=" "+s[i];
        for (int j=1; j<=m; j++) {
            int x=(s[i][j]=='B')^(i+j&1);
            v[i][j]+=x; v[i][j+k]-=x; v[i+k][j]-=x; v[i+k][j+k]+=x;
        }
    }

    for (int i=1; i<=n; i++) for (int j=1; j<=m; j++)
        v[i][j]+=v[i-1][j]+v[i][j-1]-v[i-1][j-1];

    for (int i=k; i<=n; i++) for (int j=k; j<=m; j++)
        ans=min(ans, min(v[i][j], k*k-v[i][j]));

    cout << ans;

    return 0;
}
