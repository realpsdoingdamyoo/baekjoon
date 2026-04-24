#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e14;

int n;
int v[202020][2];
vector<int> lnk[1010101];

int is[1010101], vis[1010101], cntp, cnte;

void dfs(int p) {
    vis[p]=1;
    for (int i : lnk[p]) if (!vis[i]) dfs(i);
    cntp++; cnte+=lnk[p].size();
}

signed main() {
    fastio;

    cin >> n;
    for (int i=1; i<=n; i++) cin >> v[i][0];
    for (int i=1; i<=n; i++) cin >> v[i][1];
    for (int i=1; i<=n; i++) {
        is[v[i][0]]=is[v[i][1]]=1;
        lnk[v[i][0]].push_back(v[i][1]);
        lnk[v[i][1]].push_back(v[i][0]);
    }

    int ans=0;
    for (int i=0; i<1010101; i++) if (!vis[i] && is[i]) {
        cntp=cnte=0; dfs(i);
        if (cntp-1==cnte/2) ans+=cntp-1;
        else ans+=cntp;
    }
    cout << ans;

    return 0;
}
