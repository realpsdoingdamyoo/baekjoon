#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
const int mod=1e9+7, MOD=998244353, inf=2e18;

int n, x;
int v[202020];

signed main() {
    fastio;

    cin >> n >> x;
    for (int i=1; i<=n; i++) cin >> v[i];

    if (n%2==0) for (int i=1, j=n; i<j; i++, j--) x=2*v[j]-2*v[i]+x;
    else {x=2*v[n]-x; for (int i=1, j=n-1; i<j; i++, j--) x=2*v[j]-2*v[i]+x;}
    cout << x;

    return 0;
}
