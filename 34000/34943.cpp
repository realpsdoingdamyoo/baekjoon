#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e17;

int seg[2020202], lzy[2020202];

void update(int p, int s, int e, int l, int r) {
    if (r<s || e<l) return;
    if (l<=s && e<=r) lzy[p]=lzy[p]*2%MOD;
    else {
        int m=s+e>>1;
        lzy[p<<1]=lzy[p<<1]*lzy[p]%MOD; lzy[p<<1|1]=lzy[p<<1|1]*lzy[p]%MOD; lzy[p]=1;
        update(p<<1, s, m, l, r); update(p<<1|1, m+1, e, l, r);
        seg[p]=(seg[p<<1]*lzy[p<<1]+seg[p<<1|1]*lzy[p<<1|1])%MOD;
    }
}

void update2(int p, int s, int e, int x, int y) {
    if (s==e) seg[p]=seg[p]*lzy[p]%MOD, seg[p]+=y, lzy[p]=1;
    else {
        int m=s+e>>1;
        lzy[p<<1]=lzy[p<<1]*lzy[p]%MOD; lzy[p<<1|1]=lzy[p<<1|1]*lzy[p]%MOD; lzy[p]=1;
        if (x<=m) update2(p<<1, s, m, x, y); else update2(p<<1|1, m+1, e, x, y);
        seg[p]=(seg[p<<1]*lzy[p<<1]+seg[p<<1|1]*lzy[p<<1|1])%MOD;
    }
}

int query(int p, int s, int e, int l, int r) {
    if (r<s || e<l) return 0;
    if (l<=s && e<=r) return seg[p]*lzy[p]%MOD;

    int m=s+e>>1;
    return (query(p<<1, s, m, l, r)+query(p<<1|1, m+1, e, l, r))*lzy[p]%MOD;
}

int N;
array<int, 2> V[252525];

signed main() {
    fastio;

    cin >> N;
    for (int i=1; i<=N; i++) cin >> V[i][0] >> V[i][1];
    sort(V+1, V+N+1);

    fill(lzy, lzy+8*N+10, 1);

    for (int i=1; i<=N; i++) {
        int s=query(1, 1, N*2, V[i][0], V[i][1]-1);
        update(1, 1, N*2, V[i][1], N*2);
        update2(1, 1, N*2, V[i][1], s+1);
        //cout << s+1 << "\n";

        //for (int j=1; j<=N*2; j++) cout << query(1, 1, N*2, j, j) << " ";
        //cout << '\n';
    }

    cout << query(1, 1, N*2, 1, N*2);


    return 0;
}
