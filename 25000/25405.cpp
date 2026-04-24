#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e17;

int n, m, k;
int v[101010], u[101010];

int put(int x) {
    int s=0;
    for (int i=1; i<=n; i++) s+=min(m, max(0LL, x-v[i]));
    return s;
}

signed main() {
    fastio;

    cin >> n;
    for (int i=1; i<=n; i++) cin >> v[i];
    cin >> m >> k;
    sort(v+1, v+n+1);

    int s=1, e=2e9;
    while (s<=e) {
        int md=s+e>>1;
        if (put(md)>m*k) e=md-1; else s=md+1;
    }

    int r=m*k-put(e);
    for (int i=1; i<=n; i++) u[i]=v[i]+min(m, max(0LL, e-v[i]));
    for (int i=1; i<=n; i++) if (u[i]<v[i]+m && r) u[i]++, r--;
    sort(u+1, u+n+1);
    for (int i=1; i<=n; i++) cout << u[i] << " ";

    return 0;
}
