#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
const int mod=1e9+7, MOD=998244353, inf=2e18;

int pw(int x, int y) {
    int r=1;
    while (y) {
        if (y&1) r=r*x%MOD;
        y>>=1; x=x*x%MOD;
    } return r;
}

int pwp[62]={1};
int prp[62]={1};

void psm(int p) {
    for (int i=1; i<=60; i++) pwp[i]=pwp[i-1]*p%MOD;
    for (int i=1; i<=60; i++) prp[i]=prp[i-1]*(pw(p, 1LL<<i-1)+1)%MOD;
}

int psum(int p, int n) {
    int ret=0;
    for (int i=60; i>=0; i--) if (n>=(1LL<<i)) {
        ret+=prp[i]*pw(p, n-(1LL<<i))%MOD;
        n-=(1LL<<i);
    }
    return ret%MOD;
}

void solve() {
    int p, n, m; cin >> p >> n >> m;
    if (n>m) swap(n, m);
    int d=(m-1)/n;

    int P=pw(p, n);
    psm(P);

    int ans=(psum(P, d)*P%MOD+pw(p, m))%MOD;
    cout << ans << "\n";
}

signed main() {
    fastio;

    int T; cin >> T;
    while (T--) solve();

    return 0;
}
