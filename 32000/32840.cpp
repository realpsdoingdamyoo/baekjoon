#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e14;

int gcd(int a, int b){return b?gcd(b, a%b):a;}

int x[5], y[5];
array<int, 2> us[5]={{0, 0}, {1, 2}, {1, 3}, {2, 3}};
vector<array<int, 2>> v[4];

int ss(array<int, 2> a, array<int, 2> b, array<int, 2> c) {
    return abs(a[0]*b[1]+b[0]*c[1]+c[0]*a[1]-a[1]*b[0]-b[1]*c[0]-c[1]*a[0]);
}

signed main() {
    fastio;

    for (int i=1; i<=3; i++) cin >> x[i] >> y[i];
    for (int i=1; i<=3; i++) {
        int dx=x[us[i][1]]-x[us[i][0]];
        int dy=y[us[i][1]]-y[us[i][0]];
        int g=gcd(abs(dx), abs(dy));
        if (g==1){cout << "-1"; return 0;}

        v[i].push_back({x[us[i][0]]+dx/g, y[us[i][0]]+dy/g});
        v[i].push_back({x[us[i][1]]-dx/g, y[us[i][1]]-dy/g});
    }

    int Min=inf, Max=-inf;
    for (array<int, 2> i : v[1]) for (array<int, 2> j : v[2]) for (array<int, 2> k : v[3]) {
        int ret=ss(i, j, k); Min=min(Min, ret); Max=max(Max, ret);
    }
    cout << Max << " " << Min;

    return 0;
}
