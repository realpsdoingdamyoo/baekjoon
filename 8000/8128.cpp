#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
//const int mod=1e9+7, MOD=998244353, inf=2e17;

int N, K, P, R;
vector<int> lnk[1010101];

int od[1010101];
void dfs(int p, int x) {
    if (od[p]>od[P]) P=p;
    for (int i : lnk[p]) if (i!=x) od[i]=od[p]+1, dfs(i, p);
}

int pv, pq[1010101];
void dfs2(int p, int x) {
    od[p]=++pv;
    for (int i : lnk[p]) if (i!=x) {
        dfs2(i, p);
        if (pq[od[p]]<pq[od[i]]) swap(pq[od[p]], pq[od[i]]);
    }
    pq[od[p]]++;
}

signed main() {
    fastio;

    cin >> N >> K;
    for (int i=1; i<N; i++) {
        int a, b; cin >> a >> b;
        lnk[a].push_back(b); lnk[b].push_back(a);
    }
    dfs(1, 0);

    dfs2(P, 0);
    sort(pq+1, pq+N+1);
    reverse(pq+1, pq+N+1);
    for (int i=1; i<2*K; i++) R+=pq[i];
    cout << R;

    return 0;
}
