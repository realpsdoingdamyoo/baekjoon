#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;

signed main(){
    fastio;

    int n; cin >> n;
    vector<int> v(n);
    for (int& i : v) cin >> i;
    sort(v.begin(), v.end());
    for (int i=n-3; i>=0; i--) if (v[i]+v[i+1]>v[i+2]) {
        cout << v[i]+v[i+1]+v[i+2]; return 0;
    }
    cout << -1;

    return 0;
}
