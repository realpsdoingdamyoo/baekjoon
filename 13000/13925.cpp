#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;

int N, K;
vector<int> lnk[303030];
int D[303030];

struct dsg {
    struct Node {int t=0, x=1, y=0, L=0, R=0;};
    vector<Node> seg={{0, 0, 0, 0, 0}};
    void update(int p, int x, int y, int d) {
        Node& n=seg[p];
        n.t=(n.t*x+d*y)%mod;
        n.x=n.x*x%mod;
        n.y=(n.y*x+y)%mod;
    }
    int query(int p, int s, int e, int l, int r, int x, int y) {
        int ret=0;
        if (l<=s && e<=r) update(p, x, y, e-s+1), ret=seg[p].t;
        else if (l<=e && s<=r) {
            if (seg[p].L==0) seg[p].L=seg.size(), seg.push_back({0, 0, 0, 0, 0});
            if (seg[p].R==0) seg[p].R=seg.size(), seg.push_back({0, 0, 0, 0, 0});
            update(seg[p].L, seg[p].x, seg[p].y, e-s+2>>1);
            update(seg[p].R, seg[p].x, seg[p].y, e-s+1>>1);
            ret+=query(seg[p].L, s, s+e>>1, l, r, x, y);
            ret+=query(seg[p].R, s+e+2>>1, e, l, r, x, y);
            seg[p].t=(seg[seg[p].L].t+seg[seg[p].R].t)%mod; seg[p].x=1; seg[p].y=0;
        }
        return ret%mod;
    }
} seg;

signed main() {
    fastio;

    cin >> N;
    for (int i=1; i<=N; i++) {
        int a; cin >> a;
        seg.query(0, 1, N, i, i, 0, a);
    }
    int q; cin >> q;
    for (int i=1; i<=q; i++) {
        int a, b, c; cin >> a >> b >> c;
        if (a==4) cout << seg.query(0, 1, N, b, c, 1, 0) << "\n";
        else {
            int d; cin >> d;
            if (a==1) seg.query(0, 1, N, b, c, 1, d);
            if (a==2) seg.query(0, 1, N, b, c, d, 0);
            if (a==3) seg.query(0, 1, N, b, c, 0, d);
        }
    }

    return 0;
}
