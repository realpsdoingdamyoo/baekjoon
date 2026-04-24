#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;

int n, m, k;
int deg[101010];

int mpw(int x, int y) {
    int r=1;
    while (y){if (y&1) r=r*x%MOD; x=x*x%MOD; y>>=1;}
    return r;
}

map<int, int> mp;
int cal(int d) {
    if (mp.find(d)!=mp.end()) return mp[d];
    int ret=0;
    for (int i=1; i<=k; i++) ret+=mpw(i, d);
    return mp[d]=ret%MOD;
}

signed main(){
    fastio;

    cin >> n >> m >> k;
    for (int i=1; i<=m; i++) {
        int a, b; cin >> a >> b;
        deg[b]++;
    }

    int ans=0;
    for (int i=1; i<=n; i++) if (deg[i]) ans+=cal(deg[i])*mpw(mpw(k, deg[i]), MOD-2)%MOD;
    cout << ans%MOD;


    return 0;
}
