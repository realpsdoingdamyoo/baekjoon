#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=4e18;

signed main() {
    fastio;

    string a, b; int r=0; cin >> a >> a >> b;
    for (int i=0; i<a.size(); i++) {
        int p=abs(a[i]-b[i]); r+=min(p, 26-p);
    }
    cout << r;

    return 0;
}
