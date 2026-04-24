#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e14;

int l, n;
int v[1010101];
int L[1010101], R[1010101];

bool valid(int x) {
    for (int i=1; i<=n; i++) L[i]=inf, R[i]=-inf;
    R[1]=x; L[n]=l-x;

    for (int i=2; i<=n; i++) R[i]=v[i]+x-2*min(x+1, max(0LL, v[i]-R[i-1]));
    for (int i=n-1; i>=1; i--) L[i]=v[i]-x+2*min(x+1, max(0LL, L[i+1]-v[i]));

    for (int i=1; i<n; i++) if (R[i]>=L[i+1]) return true;
    return false;
}

signed main() {
    fastio;

    cin >> l >> n;
    for (int i=1; i<=n; i++) cin >> v[i];

    int s=0, e=l;
    while (s<=e) {
        int m=s+e>>1;
        if (valid(m)) e=m-1; else s=m+1;
    }
    cout << s << "\n";

    return 0;
}
