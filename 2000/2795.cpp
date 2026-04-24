#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e7;

int n, m;
int dist[110][110];
int dp[110][110], vis[110][110];

signed main() {
    fastio;

    cin >> n >> m;
    for (int i=1; i<=n; i++) for (int j=1; j<=n; j++) dist[i][j]=(i!=j)*inf;
    for (int i=1; i<=m; i++){int a, b; cin >> a >> b; dist[a][b]=1;}
    for (int i=1; i<=n; i++) for (int j=1; j<=n; j++) for (int k=1; k<=n; k++) dist[j][k]=min(dist[j][k], dist[j][i]+dist[i][k]);

    for (int i=1; i<=n; i++) for (int j=1; j<=n; j++) dp[i][j]=inf;
    dp[2][2]=1;

    priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> pq;
    pq.push({1, 2, 2});

    while (pq.size()) {
        int d=pq.top()[0], x=pq.top()[1], y=pq.top()[2]; pq.pop();
        if (vis[x][y]++) continue;

        for (int i=1; i<=n; i++) if (i!=y) {
            dp[x][i]=min(dp[x][i], d+dist[y][i]-(x==i));
            pq.push({dp[x][i], x, i});
        }
        for (int i=1; i<=n; i++) if (i!=x) {
            dp[i][y]=min(dp[i][y], d+dist[i][x]-(i==y));
            pq.push({dp[i][y], i, y});
        }
        dp[y][x]=min(dp[y][x], d+dist[y][x]-1+(x==y));
        pq.push({dp[y][x], y, x});
    }

    cout << dp[1][1];

    return 0;
}
