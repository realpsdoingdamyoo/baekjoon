#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
const int mod=1e9+7, MOD=998244353, inf=2e17;

const int X=18;
struct node {
    int s, inc;
    array<int, 2> lmx, llmx, rmx, rlmx;
    array<int, 3> amx;
} seg[1<<X+1];

node r;
node mrg(node a, node b) {
    r.s=max(a.s+b.s, -inf); r.inc=a.inc||b.inc;
    r.lmx=max(a.lmx, {b.lmx[0]+a.s, b.lmx[1]});
    r.llmx=max(a.llmx, {b.llmx[0]+a.s, b.llmx[1]});
    if (a.inc) r.llmx=max(r.llmx, {b.lmx[0]+a.s, b.lmx[1]});
    r.rmx=max(b.rmx, {a.rmx[0]+b.s, a.rmx[1]});
    r.rlmx=max(b.rlmx, {a.rlmx[0]+b.s, a.rlmx[1]});
    if (b.inc) r.rlmx=max(r.rlmx, {a.rmx[0]+b.s, a.rmx[1]});
    r.amx=max({a.amx, b.amx, {a.rlmx[0]+b.lmx[0], a.rlmx[1], b.lmx[1]}, {a.rmx[0]+b.llmx[0], a.rmx[1], b.llmx[1]}});
    return r;
}

void update(int p, int x) {
    node n;
    if (x<=0) n.s=x, n.inc=1, n.lmx=n.llmx=n.rmx=n.rlmx={x, p}, n.amx={x, x, p};
    else n.s=x, n.inc=0, n.lmx=n.rmx={x, p}, n.llmx=n.rlmx={-inf, -1}, n.amx={-inf, -1, -1};
    p+=1<<X; seg[p]=n; p>>=1;
    while (p) seg[p]=mrg(seg[p<<1], seg[p<<1|1]), p>>=1;
}

int N;
int T[202020], S[202020];
set<int> st;

signed main() {
    fastio;

    cin >> N;
    for (int i=0; i<(1<<X); i++) update(i, -inf);
    for (int i=1; i<=N; i++) {
        cin >> T[i] >> S[i];
        update(i, -T[i]*S[i]);
        if (T[i]!=-1) st.insert(i);
    }

    vector<array<int, 2>> ans;

    while (seg[1].amx[0]>0) {
        int s=seg[1].amx[1], e=seg[1].amx[2];
        while (st.lower_bound(s)!=st.upper_bound(e)) {
            int x=*st.lower_bound(s); st.erase(st.lower_bound(s));
            update(x, S[x]); T[x]=1;
        }
        ans.push_back({s, e});
    }

    if (st.size()) cout << "-1\n";
    else {
        cout << ans.size() << "\n";
        for (array<int, 2> i : ans) cout << i[0] << " " << i[1] << "\n";
    }

    return 0;
}
