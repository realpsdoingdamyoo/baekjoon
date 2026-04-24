#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;

int N, Q, W, last;
array<int, 3> edg[101010];
vector<array<int, 2>> lnk[101010];
int LP[101010], RP[101010], pv, V[202020];

void DFS(int p, int x) {
    for (array<int, 2> i : lnk[p]) if (i[0]!=x) {
        LP[i[0]]=++pv; DFS(i[0], p); RP[i[0]]=++pv;
        V[LP[i[0]]]=i[1]; V[RP[i[0]]]=-i[1];
    }
}

const int X=18;
struct node {int s, lmx, rmn, ac, lc, rc, c;} seg[1<<X+1];

node mrg(node a, node b) {
    node r;
    r.s=a.s+b.s;
    r.lmx=max(a.lmx, a.s+b.lmx);
    r.rmn=min(b.rmn, a.rmn+b.s);
    r.ac=max(a.ac+b.s, -a.s+b.ac);
    r.lc=max(max(a.lc, a.ac+b.lmx), -a.s+b.lc);
    r.rc=max(max(b.rc, b.ac-a.rmn), a.rc+b.s);
    r.c=max(max(a.c, b.c), max(a.rc+b.lmx, -a.rmn+b.lc));
    return r;
}

void update(int p, int x) {
    p+=1<<X; seg[p]={x, max(x, 0LL), min(x, 0LL), abs(x), abs(x), abs(x), abs(x)}; p>>=1;
    while (p) seg[p]=mrg(seg[p<<1], seg[p<<1|1]), p>>=1;
}

int query(int s, int e) {
    s+=1<<X; e+=1<<X; node ret=seg[0];
    for (int i=X; i>=0; i--) {
        int l=(s-1>>i)+1, r=(e+1>>i)-1;
        if (l>r) continue;
        if (l&1) ret=mrg(seg[l], ret);
        if (~r&1) ret=mrg(ret, seg[r]);
    }
    return ret.c;
}

signed main() {
    fastio;

    cin >> N >> Q >> W;

    for (int i=1; i<N; i++) {
        int a, b, c; cin >> a >> b >> c;
        edg[i]={a, b, c};
        lnk[a].push_back({b, c});
        lnk[b].push_back({a, c});
    }

    DFS(1, 0);

    for (int i=1; i<=N*2; i++) update(i, V[i]);
    for (int i=1; i<N; i++) if (LP[edg[i][0]]<LP[edg[i][1]]) swap(edg[i][0], edg[i][1]);

    for (int i=1; i<=Q; i++) {
        int p, d; cin >> p >> d;
        p=edg[(p+last)%(N-1)+1][0]; d=(d+last)%W;
        update(LP[p], d); update(RP[p], -d);
        cout << (last=query(1, 2*N-2)) << "\n";
    }

    return 0;
}
