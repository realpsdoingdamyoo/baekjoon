#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e7;

int n, m, k;
int sx, sy, ex, ey;
int dis[1010][1010], dist[1010][1010];
int vis[1010][1010];

double crs(array<int, 2> a, array<int, 2> b) {
    return (b[1]-a[1]+0.0)/(a[0]-b[0]);
}

signed main() {
    fastio;

    cin >> n >> m >> sx >> sy >> ex >> ey >> k;
    for (int i=1; i<=n; i++) for (int j=1; j<=m; j++) dis[i][j]=inf;
    for (int i=1; i<=k; i++) {int a, b; cin >> a >> b; dis[a][b]=0;}

    for (int j=1; j<=m; j++) {
        int d=inf; for (int i=1; i<=n; i++) dis[i][j]=min(dis[i][j], d), d=dis[i][j]+1;
        d=inf; for (int i=n; i>=1; i--) dis[i][j]=min(dis[i][j], d), d=dis[i][j]+1;
        for (int i=1; i<=n; i++) dis[i][j]*=dis[i][j];
    }

    for (int i=1; i<=n; i++) {
        vector<array<int, 2>> con;
        for (int j=1; j<=m; j++) {
            array<int, 2> p={-2*j, j*j+dis[i][j]};
            while (con.size()>=2 && crs(con[con.size()-2], con[con.size()-1])>crs(con[con.size()-1], p)) con.pop_back();
            con.push_back(p);
        }
        for (int j=m; j>=1; j--) {
            while (con.size()>=2 && con[con.size()-2][0]*j+con[con.size()-2][1]<con[con.size()-1][0]*j+con[con.size()-1][1]) con.pop_back();
            dist[i][j]=j*j+con[con.size()-1][0]*j+con[con.size()-1][1];
        }
    }

    priority_queue<array<int, 3>> pq;
    pq.push({dist[sx][sy], sx, sy});
    while (pq.size()) {
        int d=pq.top()[0], x=pq.top()[1], y=pq.top()[2]; pq.pop();
        if (x==0 || y==0 || x==n+1 || y==m+1) continue;
        if (vis[x][y]++) continue; dist[x][y]=d;

        for (array<int, 2> i : vector<array<int, 2>>{{0, 1}, {1, 0}, {-1, 0}, {0, -1}}) {
            int nx=x+i[0], ny=y+i[1];
            pq.push({min(dist[nx][ny], dist[x][y]), nx, ny});
        }
    }
    cout << dist[ex][ey] << "\n";

    return 0;
}
