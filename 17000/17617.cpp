#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e17;

int n, r, m, x[1010101];

signed main() {
    fastio;

    cin >> n >> r >> m;
    for (int i=1; i<=n; i++) cin >> x[i];
    sort(x+1, x+n+1); x[0]=x[n]-m;

    for (int i=n; i>=1; i--) x[i]-=x[i-1]+2*r;
    int a=0, s=0;
    for (int i=1; i<=n; i++) s=max(s+x[i], 0LL), a=max(a, s);
    for (int i=1; i<=n; i++) s=max(s+x[i], 0LL), a=max(a, s);
    cout << (a+1>>1);

    return 0;
}
