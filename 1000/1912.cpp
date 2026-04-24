#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e17;

int n;
int v[101010];

signed main() {
    fastio;

    cin >> n;
    for (int i=1; i<=n; i++) cin >> v[i];
    int s=0, mn=0, r=-inf;
    for (int i=1; i<=n; i++) r=max(r, v[i]);
    if (r>=0)
    for (int i=1; i<=n; i++) {
        s+=v[i]; mn=min(mn, s);
        r=max(r, s-mn);
    }
    cout << r;


    return 0;
}
