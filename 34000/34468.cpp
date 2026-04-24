#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;

int N, M, Q, R;
int C[202020], P[202020];
multiset<int> st[202020];
multiset<int> fi, se;

void update(int p, int x, int y) {
    if (st[p].size()>=1) R-=*prev(st[p].end());
    if (st[p].size()>=1) fi.erase(fi.find(*prev(st[p].end())));
    if (st[p].size()>=2) se.erase(se.find(*prev(prev(st[p].end()))));
    if (y==0) st[p].erase(st[p].find(x)); else st[p].insert(x);
    if (st[p].size()>=1) fi.insert(*prev(st[p].end()));
    if (st[p].size()>=2) se.insert(*prev(prev(st[p].end())));
    if (st[p].size()>=1) R+=*prev(st[p].end());
}

int upbo() {
    if (se.size()>=1) return R+max(*prev(se.end())-*fi.begin(), 0LL);
    return R;
}

signed main(){
    fastio;

    cin >> N >> M >> Q;
    for (int i=1; i<=N; i++) {
        cin >> C[i] >> P[i];
        st[C[i]].insert(P[i]);
    }

    for (int i=1; i<=M; i++) {
        R+=*prev(st[i].end());
        fi.insert(*prev(st[i].end()));
        if (st[i].size()>=2) se.insert(*prev(prev(st[i].end())));
    }
    cout << upbo() << "\n";

    for (int i=1; i<=Q; i++) {
        int a, b, c; cin >> a >> b >> c;
        update(C[b], P[b], 0); (a==1?C[b]:P[b])=c; update(C[b], P[b], 1);
        cout << upbo() << "\n";
    }

    return 0;
}
