#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;

int n, m;
int deg[101010];

signed main(){
    fastio;

    cin >> n >> m;
    for (int i=1; i<=m; i++) {
        int a, b; cin >> a >> b;
        deg[a]++; deg[b]++;
    }

    int ans=0;
    for (int i=1; i<=n; i++) ans+=deg[i]*(deg[i]-1)*(deg[i]-2)/6%mod;
    cout << ans%mod;

    return 0;
}
