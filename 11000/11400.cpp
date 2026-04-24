#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;

int N, M;
vector<int> lnk[101010];
int vis[101010], dep[101010], pr[101010];
vector<array<int, 2>> ar;
int dfs(int p) {
    int up=dep[p], cn=0; vis[p]=1;
    for (int i : lnk[p]) if (i!=pr[p]) {
        if (vis[i]) up=min(up, dep[i]);
        else {
            pr[i]=p, dep[i]=dep[p]+1; cn++;
            int g=dfs(i); up=min(up, g);
            if (g>dep[p]) ar.push_back({min(p, i), max(p, i)});
        }
    }
    return up;
}

signed main(){
    fastio;

    cin >> N >> M;
    for (int i=0; i<M; i++) {
        int a, b; cin >> a >> b;
        lnk[a].push_back(b); lnk[b].push_back(a);
    }
    dfs(1);
    sort(ar.begin(), ar.end());
    cout << ar.size() << "\n";
    for (array<int, 2> i : ar) cout << i[0] << " " << i[1] << "\n";

    return 0;
}
