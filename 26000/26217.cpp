#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;

signed main(){
    fastio;

    double n, ans; cin >> n;
    for (int i=1; i<=n; i++) ans+=n/i;
    cout << ans;

    return 0;
}
