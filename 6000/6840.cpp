#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, inf=1e18;

signed main() {
    fastio;

    int a, b, c;
    cin >> a >> b >> c;
    cout << a+b+c-min({a, b, c})-max({a, b, c});

    return 0;
}
