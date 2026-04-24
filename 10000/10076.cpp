#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;

int N, P, D, V[101010], U[101010], R;

struct Node{signed L, R, C; int S;} node[1820202];
int pv=0, root[101010]={0};

void update(int c, int p, int s, int e, int x) {
    node[c].S=node[p].S+U[x]; node[c].C=node[p].C+1;
    if (s==e) return;
    int m=s+e>>1;
    if (x<=m) {
        if (node[c].L==0) node[c].L=++pv; node[c].R=node[p].R;
        update(node[c].L, node[p].L, s, m, x);
    }
    else {
        if (node[c].R==0) node[c].R=++pv; node[c].L=node[p].L;
        update(node[c].R, node[p].R, m+1, e, x);
    }
}

int query(int c, int p, int s, int e, int x) {
    if (s==e) return U[s]*x;
    int RC=node[node[c].R].C-node[node[p].R].C, m=s+e>>1;
    if (x<=RC) return query(node[c].R, node[p].R, m+1, e, x);
    return (node[node[c].R].S-node[node[p].R].S)+query(node[c].L, node[p].L, s, m, x-RC);
}

int trip(int l, int r) {
    int n=min(D-(r-l)-min(P-l, r-P), r-l+1);
    return query(root[r], root[l-1], 1, N, n);
}

int opt[101010];

void DNC(int l, int r, int s, int e) {
    if (l>r) return;

    int m=l+r>>1; array<int, 2> ret={-inf, -inf};
    for (int i=s; i<=e; i++) ret=max(ret, {trip(m, i), i});
    opt[m]=ret[1]; R=max(R, ret[0]);
    DNC(l, m-1, s, opt[m]); DNC(m+1, r, opt[m], e);
}

signed main() {
    fastio;

    cin >> N >> P >> D; P++;
    for (int i=1; i<=N; i++) cin >> V[i], U[i]=V[i];
    sort(U+1, U+N+1);
    for (int i=1; i<=N; i++) root[i]=++pv;
    for (int i=1; i<=N; i++) update(root[i], root[i-1], 1, N, lower_bound(U+1, U+N+1, V[i])-U);

    DNC(1, P, P, N);

    cout << R;

    return 0;
}
