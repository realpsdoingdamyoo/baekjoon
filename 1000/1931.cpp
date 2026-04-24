#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
const int mod=1e9+7, MOD=998244353, inf=2e18;

int n;
array<int, 2> v[101010];

signed main() {
    fastio;

    cin >> n;
    for (int i=1; i<=n; i++) cin >> v[i][0] >> v[i][1];
    sort(v+1, v+n+1, [&](array<int, 2> a, array<int, 2> b){return a[1]==b[1]?(a[0]<b[0]):(a[1]<b[1]);});
    int c=0, e=0;
    for (int i=1; i<=n; i++) if (e<=v[i][0]) e=v[i][1], c++;
    cout << c;

    return 0;
}
