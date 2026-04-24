#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
const int mod=1e9+7, inf=2e18;
#define m (s+e>>1)

int N, Q;

array<int, 4> seg[2020202];
array<int, 4> mrg(array<int, 4> a, array<int, 4> b) {
    return {a[0]+b[0], min(a[1], a[0]+b[1]), min(b[2], b[0]+a[2]), min({a[3], b[3], a[2]+b[1]})};
}
void update(int p, int s, int e, int x, int y) {\
    if (s==e) {seg[p][0]=y; seg[p][1]=seg[p][2]=seg[p][3]=y; return;}
    if (x<=m) update(p<<1, s, m, x, y); else update(p<<1|1, m+1, e, x, y);
    seg[p]=mrg(seg[p<<1], seg[p<<1|1]);
}
array<int, 4> qry(int p, int s, int e, int l, int r) {
    if (r<s || e<l) return {0, 0, 0, 0};
    if (l<=s && e<=r) return seg[p];
    return mrg(qry(p<<1, s, m, l, r), qry(p<<1|1, m+1, e, l, r));
}

signed main() {
    fastio;

    cin >> N;
    for (int i=1; i<=N; i++) {
        char x; cin >> x;
        update(1, 1, N, i, (x=='T')-(x=='C'));
    }
    cin >> Q;
    while (Q--) {
        int a, b; cin >> a >> b;
        array<int, 4> ret=qry(1, 1, N, a, b);
        cout << ret[0]-ret[3] << "\n";
    }

    return 0;
}
