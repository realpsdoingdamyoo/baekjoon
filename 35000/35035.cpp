#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e17;

int N, L, Q;

const int X=19;
struct node {
    array<int, 2> LX, RX;
    int D;

} seg[1<<X+1];

node mrg(node a, node b) {
    if (a.LX[0]==-1) return b;
    if (b.LX[0]==-1) return a;
    node r;

    r.LX[0]=max(a.LX[0], min(a.LX[1], max(a.RX[0], b.LX[0])));
    r.LX[1]=max(a.LX[0], min(a.LX[1], min(a.RX[1], b.LX[1])));

    r.RX[0]=max(b.RX[0], min(b.RX[1], max(a.RX[0], b.LX[0])));
    r.RX[1]=max(b.RX[0], min(b.RX[1], min(a.RX[1], b.LX[1])));

    if (r.LX[0]==r.LX[1]) r.D=a.D+b.D+max(max(a.RX[0], b.LX[0])-min(a.RX[1], b.LX[1]), 0LL);
    else r.D=0;
    return r;
}

void update(int p, int a, int b) {
    p+=1<<X; seg[p]={{a, b}, {a, b}, 0}; p>>=1;
    while (p) seg[p]=mrg(seg[p<<1], seg[p<<1|1]), p>>=1;
}

node qry(int l, int r) {
    node ret={{-1}};

    l+=1<<X; r+=1<<X;
    for (int i=X; i>=0; i--) {
        int L=(l-1>>i)+1, R=(r+1>>i)-1;
        if (L>R) continue;
        if (L&1) ret=mrg(seg[L], ret);
        if (~R&1) ret=mrg(ret, seg[R]);
    }
    return ret;
}

int A[303030], B[303030];

signed main() {
    fastio;

    // fuck why wa
    cin >> N >> L >> Q;
    for (int i=1; i<=N; i++) cin >> A[i];
    for (int i=1; i<=N; i++) cin >> B[i];
    for (int i=1; i<=N; i++) update(i, A[i], L-B[i]);

    while (Q--) {
        int t; cin >> t;
        if (t==1) {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            if (x1==x2){cout << abs(y1-y2) << "\n"; continue;}
            if (x1>x2) swap(x1, x2), swap(y1, y2); x1++;
            node nd=qry(x1, x2);

            int in=max(nd.LX[0], min(nd.LX[1], y1));
            int out=max(nd.RX[0], min(nd.RX[1], y2));
            //cout << in << " " << out << " " << nd.D << " / ";
            int ans=abs(y1-in)+nd.D+abs(y2-out);
            if (nd.LX[0]<nd.LX[1]) ans+=abs(out-in);
            cout <<ans+(x2-x1)+1 << "\n";
        }
        else {
            int x, a, b; cin >> x >> a >> b;
            update(x, a, L-b);
        }
    }

    return 0;
}
