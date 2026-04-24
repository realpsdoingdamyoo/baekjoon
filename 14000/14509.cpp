#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
const int mod=1e9+7, inf=2e18;

int N, A[202020];
vector<int> lnk[202020];
multiset<int> st[202020];

void dfs(int p) {
    for (int i : lnk[p]) {
        dfs(i);
        if (st[i].size()>st[p].size()) swap(st[i], st[p]);
        for (int j : st[i]) st[p].insert(j);
    }
    set<int>::iterator it=st[p].lower_bound(A[p]);
    if (it!=st[p].end()) st[p].erase(it);
    st[p].insert(A[p]);
}

signed main() {
    fastio;

    cin >> N;
    for (int i=1, x; i<=N; i++) {
        cin >> A[i] >> x;
        lnk[x].push_back(i);
    }

    dfs(1);
    cout << st[1].size();

    return 0;
}
