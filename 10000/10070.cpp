#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e9;

const int X=20;
struct node {int L=0, R=inf; bool av(){return L<=R;}} seg[1<<X+1];
node mrg(node a, node b){return {max(a.L, b.L), min(a.R, b.R)};}

void update(int p, int l, int r) {
    p+=1<<X; seg[p]={l, r}; p>>=1;
    while (p) seg[p]=mrg(seg[p<<1], seg[p<<1|1]), p>>=1;
}
pair<int, node> walk(int p) {
    node x={-1, inf};
    while (1) {
        if (p>=(1<<X)) return {p-(1<<X)+1, x};
        if (mrg(x, seg[p<<1|1]).av()) x=mrg(x, seg[p<<1|1]), p=p<<1;
        else p=p<<1|1;
    }
}

array<int, 2> w[505050];
vector<int> up[2020202], dn[2020202];
set<array<int, 2>> st;

signed main() {
    fastio;

    int N, K; cin >> N >> K;
    update(0, -1, 0);
    for (int i=1; i<(1<<X); i++) update(i, -1, inf);

    for (int i=1; i<=K; i++) {
        int o, s, e, x; cin >> o >> s >> e >> x;
        w[i]=(o==1?array<int, 2>{x, inf}:array<int, 2>{-1, x});
        up[s].push_back(i); dn[e].push_back(i);
    }

    st.insert({0, 0});
    for (int i=0; i<N; i++) {
        for (int x : up[i]) update(x, w[x][0], w[x][1]), st.insert({x, w[x][w[x][0]==-1]});
        pair<int, node> r=walk(1);
        int p=r.first; node v=r.second;
        int pv=(*prev(st.lower_bound({p, -inf})))[1];
        if (pv<v.L) cout << v.L << "\n";
        else if (pv>v.R) cout << v.R << "\n";
        else cout << pv << "\n";

        for (int x : dn[i]) update(x, -1, inf), st.erase(st.find({x, w[x][w[x][0]==-1]}));
    }

    return 0;
}
