#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
const int mod=1e9+7, MOD=998244353, inf=2e18;

int N, M;
int V[1010101];
struct Node{int l, r, c, s;} node[25212121];
int root[1010101], pv;
vector<int> comp;

struct pst {
    void update(int p, int n, int l, int r, int x){
        node[p].c=node[n].c+1;
        node[p].s=node[n].s+comp[x];
        if(l==r) return;
        int m=l+r>>1;
        if(x<=m){
            if(node[p].l==0) node[p].l=++pv; node[p].r=node[n].r;
            update(node[p].l, node[n].l, l, m, x);
        }
        else{
            if(node[p].r==0) node[p].r=++pv; node[p].l=node[n].l;
            update(node[p].r, node[n].r, m+1, r, x);
        }
    }

    int query(int p, int n, int l, int r, int k){
        if(l==r) return comp[l]*k;
        int lc=node[node[p].l].c-node[node[n].l].c;
        int m=l+r>>1;
        if(lc>=k) return query(node[p].l, node[n].l, l, m, k);
        return query(node[p].r, node[n].r, m+1, r, k-lc)+(node[node[p].l].s-node[node[n].l].s);
    }
} pst;

signed main() {
    fastio;

    cin >> N >> M;
    for (int i=1; i<=N; i++) cin >> V[i], comp.push_back(V[i]);
    for(int i=0; i<=N; i++) root[i]=++pv;
    sort(comp.begin(), comp.end());
    for (int i=1; i<=N; i++) {
        int x=lower_bound(comp.begin(), comp.end(), V[i])-comp.begin();
        pst.update(root[i], root[i-1], 0, N, x);
    }

    for (int i=1; i<=M; i++) {
        int s, e, m, l, r;
        cin >> s >> e >> m >> l >> r;
        cout << pst.query(root[min(e, s+r+m-1)], root[s-1], 0, N, r)-pst.query(root[min(e, s+l+m-2)], root[s-1], 0, N, l-1) << "\n";
    }

    return 0;
}
