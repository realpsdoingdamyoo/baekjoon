#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e17;

const int X=1e6;
array<int, 2> seg[X<<2];

array<int, 2> mrg(array<int, 2> a, array<int, 2> b) {
    if (a[0]+b[0]<0) return max(a, b);
    return {a[0]+b[0], max(a[1]+b[0], b[1])};
}
void update(int p, int s, int e, int x, int y) {
    if (s==e) {seg[p]=y?array<int, 2>{y, y+x}:array<int, 2>{-inf, -inf}; return;}

    int m=s+e>>1;
    if (x<=m) update(p<<1, s, m, x, y);
    else update(p<<1|1, m+1, e, x, y);
    seg[p]=mrg(seg[p<<1], seg[p<<1|1]);
}

array<int, 2> query(int p, int s, int e, int l, int r) {
    if (e<l || r<s) return {-inf, -inf};
    if (l<=s && e<=r) return seg[p];
    int m=s+e>>1;
    return mrg(query(p<<1, s, m, l, r), query(p<<1|1, m+1, e, l, r));
}

array<int, 2> qry[303030];

signed main() {
    fastio;

    int Q; cin >> Q;
    for (int i=1; i<=Q; i++) {
        char c; cin >> c;
        if (c=='+') {
            int a, b; cin >> a >> b;
            qry[i]={a, b};
            update(1, 1, X, a, b);
        }
        else if (c=='-') {
            int a; cin >> a;
            update(1, 1, X, qry[a][0], 0);
        }
        else {
            int a; cin >> a;
            cout << max(0LL, query(1, 1, X, 1, a)[1]-a) << "\n";
        }
    }

    return 0;
}
