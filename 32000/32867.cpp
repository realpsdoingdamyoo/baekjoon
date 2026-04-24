#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e15;

int n, k, a;
int v[202020];

signed main() {
    fastio;

    cin >> n >> k;
    for (int i=1; i<=n; i++) cin >> v[i]; v[n+1]=inf;

    for (int i=1, j; i<=n; i=j) {
        int mx=v[i], mn=v[i];
        j=i; while (j<=n && mx-mn<k) {
            ++j, mx=max(mx, v[j]), mn=min(mn, v[j]);
        }
        a++;
    }
    cout << a-1;

    return 0;
}
