#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, inf=1e18;
#define m (s+e>>1)

int N, Q, A[1010101];
struct Node {int S, MX, MXC, SMX;} seg[4040404];
Node mrg(Node a, Node b) {
    if (a.MX>b.MX) return {a.S+b.S, a.MX, a.MXC, max(a.SMX, b.MX)};
    if (a.MX<b.MX) return {a.S+b.S, b.MX, b.MXC, max(b.SMX, a.MX)};
    return {a.S+b.S, a.MX, a.MXC+b.MXC, max(a.SMX, b.SMX)};
}

void init(int p, int s, int e) {
    if (s==e) seg[p]={A[s], A[s], 1, -1};
    else init(p<<1, s, m), init(p<<1|1, m+1, e), seg[p]=mrg(seg[p<<1], seg[p<<1|1]);
}

void push(Node& n, int x) {
    assert(n.SMX<x);
    if (x<n.MX) n.S-=(n.MX-x)*n.MXC, n.MX=x;
}

void update(int p, int s, int e, int l, int r, int x) {
    if (e<l || r<s) return;
    if (l<=s && e<=r && seg[p].SMX<x) {
        push(seg[p], x); return;
    }

    if (seg[p].MX<seg[p<<1].MX) push(seg[p<<1], seg[p].MX);
    if (seg[p].MX<seg[p<<1|1].MX) push(seg[p<<1|1], seg[p].MX);
    update(p<<1, s, m, l, r, x); update(p<<1|1, m+1, e, l, r, x);
    seg[p]=mrg(seg[p<<1], seg[p<<1|1]);
}

int query(int p, int s, int e, int l, int r, int t) {
    if (e<l || r<s) return 0;
    if (l<=s && e<=r) return t==2?seg[p].MX:seg[p].S;

    if (seg[p].MX<seg[p<<1].MX) push(seg[p<<1], seg[p].MX);
    if (seg[p].MX<seg[p<<1|1].MX) push(seg[p<<1|1], seg[p].MX);
    int a=query(p<<1, s, m, l, r, t), b=query(p<<1|1, m+1, e, l, r, t);
    return t==2?max(a, b):a+b;
}

signed main() {
    fastio;

    cin >> N;
    for (int i=1; i<=N; i++) cin >> A[i];
    init(1, 1, N);

    cin >> Q;
    while (Q--) {
        int a; cin >> a;
        if (a==1) {
            int l, r, x; cin >> l >> r >> x;
            update(1, 1, N, l, r, x);
        }
        else {
            int l, r; cin >> l >> r;
            cout << query(1, 1, N, l, r, a) << "\n";
        }
    }

    return 0;
}
