#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, inf=1e18;
#define m (s+e>>1)

int N, Q, A[505050], lzy[2020202];
struct Node {int MN, AND, OR;} seg[2020202];
Node mrg(Node a, Node b) {return {min(a.MN, b.MN), a.AND&b.AND, a.OR|b.OR};}

void init(int p, int s, int e) {
    if (s==e) seg[p]={A[s], A[s], A[s]};
    else init(p<<1, s, m), init(p<<1|1, m+1, e), seg[p]=mrg(seg[p<<1], seg[p<<1|1]);
}

void prop(int p, int s, int e) {
    if (s<e) lzy[p<<1]+=lzy[p], lzy[p<<1|1]+=lzy[p];
    seg[p].MN+=lzy[p]; seg[p].AND+=lzy[p]; seg[p].OR+=lzy[p]; lzy[p]=0;
}

void update(int p, int s, int e, int l, int r, int x, int y) {
    prop(p, s, e);
    if (e<l || r<s) return;
    if (l<=s && e<=r) {
        if (y==0 && (seg[p].AND&~x)==(seg[p].OR&~x)) {
            lzy[p]=(seg[p].AND&x)-seg[p].AND; prop(p, s, e); return;
        }
        if (y==1 && (seg[p].AND&x)==(seg[p].OR&x)) {
            lzy[p]=(seg[p].OR|x)-seg[p].OR; prop(p, s, e); return;
        }
    }

    update(p<<1, s, m, l, r, x, y); update(p<<1|1, m+1, e, l, r, x, y);
    seg[p]=mrg(seg[p<<1], seg[p<<1|1]);
}

int query(int p, int s, int e, int l, int r) {
    prop(p, s, e);
    if (e<l || r<s) return inf;
    if (l<=s && e<=r) return seg[p].MN;
    return min(query(p<<1, s, m, l, r), query(p<<1|1, m+1, e, l, r));
}

signed main() {
    fastio;

    cin >> N;
    for (int i=1; i<=N; i++) cin >> A[i];
    init(1, 1, N);

    cin >> Q;
    while (Q--) {
        char a; cin >> a;
        if (a!='?') {
            int l, r, x; cin >> l >> r >> x;
            update(1, 1, N, l, r, x, a=='|');
        }
        else {
            int l, r; cin >> l >> r;
            cout << query(1, 1, N, l, r) << "\n";
        }
    }

    return 0;
}
