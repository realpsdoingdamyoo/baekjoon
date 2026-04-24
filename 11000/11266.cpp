#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;

int N, M, R;
vector<int> lnk[10101];
int vis[10101], dep[10101], pr[10101], ar[10101];
int dfs(int p) {
    int up=dep[p], cn=0; vis[p]=1;
    for (int i : lnk[p]) if (i!=pr[p]) {
        if (vis[i]) up=min(up, dep[i]);
        else {
            pr[i]=p, dep[i]=dep[p]+1; cn++;
            int g=dfs(i); up=min(up, g);
            if (g>=dep[p] && p!=R) ar[p]=1;
        }
    }
    if (p==R && cn>=2) ar[p]=1;
    return up;
}

signed main(){
    fastio;

    cin >> N >> M;
    for (int i=0; i<M; i++) {
        int a, b; cin >> a >> b;
        lnk[a].push_back(b); lnk[b].push_back(a);
    }
    for (int i=1; i<=N; i++) if (!vis[i]) dfs(R=i);
    cout << accumulate(ar+1, ar+N+1, 0LL) << "\n";
    for (int i=1; i<=N; i++) if (ar[i]) cout << i << " ";

    return 0;
}
