#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e17;

int N;
vector<array<int, 3>> lnk[303030];
int DP[303030], R[303030], SZ[303030];

void dfs(int p, int x) {
    SZ[p]=1;
    for (array<int, 3> i : lnk[p]) if (i[0]!=x) {
        dfs(i[0], p); DP[p]+=DP[i[0]]+i[1]*SZ[i[0]]; SZ[p]+=SZ[i[0]];
    }
}

void rr(int p, int x) {
    for (array<int, 3> i : lnk[p]) if (i[0]!=x) {
        R[i[0]]+=DP[p]-DP[i[0]]-i[1]*SZ[i[0]]+R[p]+i[2]*(N-SZ[i[0]]); rr(i[0], p);
    }
}

signed main() {
    fastio;

    cin >> N;
    for (int i=1; i<N; i++) {
        int a, b, c, d; cin >> a >> b >> c >> d;
        lnk[a].push_back({b, c, d}); lnk[b].push_back({a, d, c});
    }

    dfs(1, 0); rr(1, 0);

    int ans=inf;
    for (int i=1; i<=N; i++) ans=min(ans, DP[i]+R[i]);
    cout << ans;

    return 0;
}
