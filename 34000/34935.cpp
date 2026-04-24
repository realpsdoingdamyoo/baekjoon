#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e17;

signed main() {
    fastio;

    int N, pv=-inf*6; cin >> N;
    for (int i=1; i<=N; i++) {
        int x; cin >> x;
        if (x==pv) {cout << "0"; return 0;}
        pv=x;
    }
    cout << 1;

    return 0;
}
