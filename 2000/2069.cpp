#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
const int mod=1e9+7, MOD=998244353, inf=2e18;

int n, pv;
array<int, 2> v[101010], u[101010];

signed main() {
    fastio;

    cin >> n;
    for (int i=1; i<=n; i++) cin >> v[i][0] >> v[i][1];
    sort(v+1, v+n+1, [&](array<int, 2> a, array<int, 2> b){return a[1]*mod-a[0]<b[1]*mod-b[0];});
    for (int i=1; i<=n; i++) {
        while (pv>=1 && v[i][0]<=u[pv][0] && u[pv][1]<=v[i][1]) pv--;
        u[++pv]=v[i];
    }

    int ans=0;
    for (int i=1; i<=pv; i++) {
        int d1=u[i][1]-u[i][0];
        int d2=max(min(u[i][1], u[i-1][1])-max(u[i][0], u[i-1][0]), 0LL);
        ans+=d1*d1-d2*d2;
    }
    cout << ans;

    return 0;
}
