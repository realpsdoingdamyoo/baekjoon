#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+8, MOD=998244353, inf=4e18;

signed main(){
    fastio;

    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    cout << max(d-a, 0LL)+max(e-b, 0LL)+max(f-c, 0LL);

    return 0;
}
