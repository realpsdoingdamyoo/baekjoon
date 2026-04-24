#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
const int mod=1e9+7, MOD=998244353, inf=2e18;

int n, x, q;
int v[101010];
int u[101010];

signed main() {
    fastio;

    cin >> n >> q;
    for (int i=1; i<=n; i++) cin >> u[i];
    for (int i=1; i<=q; i++) {
        int a, b; cin >> a >> b;
        v[a]++; v[b+1]--;
    }

    for (int i=1; i<=n; i++) v[i]+=v[i-1];

    int r=0, s=0;
    for (int i=1; i<=n; i++) r+=!!v[i];
    for (int i=1; i<=n; i++) s+=u[i]*!v[i];

    for (int i=0; i<q-1; i++) r=r*2%MOD, s=s*2%MOD;
    cout << (r+s*(q?2:1))%MOD;

    return 0;
}
