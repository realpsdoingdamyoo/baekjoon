#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e17;

int n, m;
vector<int> lnk[505];
int dist[505];

int BFS(int p) {
    for (int i=1; i<=n; i++) dist[i]=inf;
    dist[p]=0; queue<int> q; q.push(p);

    while (q.size()) {
        int x=q.front(); q.pop();
        for (int i : lnk[x]) {
            if (dist[i]==inf) {
                q.push(i);
                dist[i]=dist[x]+1;
            }
        }
    }

    int ret=inf;
    for (int i=1; i<=n; i++) {
        int k=0;
        for (int j : lnk[i]) {
            if (dist[i]==dist[j]) ret=min(ret, dist[i]*2+1);
            if (dist[i]==dist[j]+1) k++;
        }
        if (k>=2) ret=min(ret, dist[i]*2);
    }
    return ret;
}

int solve() {
    cin >> n >> m;
    for (int i=1; i<=n; i++) lnk[i].clear();
    for (int i=1; i<=m; i++) {
        int a, b; cin >> a >> b; a++; b++;
        lnk[a].push_back(b);
        lnk[b].push_back(a);
    }

    int ans=inf;
    for (int i=1; i<=n; i++) ans=min(ans, BFS(i));
    return ans;
}

signed main() {
    fastio;

    int t; cin >> t;
    for (int i=1; i<=t; i++) {
        int ret=solve();
        cout << "Case " << i << ": ";
        if (ret==inf) cout << "impossible\n";
        else cout << ret << "\n";
    }

    return 0;
}
