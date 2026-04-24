#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e17;

int N, SZ[202020];
vector<int> lnk[202020];

void dfs1(int p, int x) {
    SZ[p]=1;
    for (int& i : lnk[p]) if (i==x) {swap(i, lnk[p].back()); lnk[p].pop_back(); break;}
    for (int i : lnk[p]) dfs1(i, p), SZ[p]+=SZ[i];
}

void dfs(int p, int x) {

    for (int& i : lnk[p]) if (SZ[i]>SZ[lnk[p][0]]) swap(i, lnk[p][0]);
    for (int i : lnk[p]) dfs(i, p);
    cout << p << " ";
}

signed main() {
    fastio;

    cin >> N;
    for (int i=1; i<N; i++) {
        int a, b; cin >> a >> b;
        lnk[a].push_back(b);
        lnk[b].push_back(a);
    }

    dfs1(1, 0);
    dfs(1, 0);

    return 0;
}
