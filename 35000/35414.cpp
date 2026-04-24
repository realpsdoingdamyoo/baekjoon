#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=1e18;

int N, M;
vector<int> lnk[101010];

int vis[101010];
vector<int> ans;
void dfs(int p) {
    for (int i : lnk[p]) if (!vis[i])
        ans.push_back(i), vis[i]=1, dfs(i);
}

signed main(){
    fastio;

    cin >> N >> M;
    for (int i=1; i<=M; i++) {
        int a, b; cin >> a >> b;
        lnk[a].push_back(b); lnk[b].push_back(a);
    }

    for (int i=1; i<=N; i++) if (!vis[i]++) dfs(i);
    cout << ans.size() << "\n";
    while (ans.size()) cout << ans.back() << "\n", ans.pop_back();

    return 0;
}
