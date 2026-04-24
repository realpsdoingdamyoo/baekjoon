#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
const int mod=1e9+7, MOD=998244353, inf=2e18;

int n, m;
int d[505][505];

signed main() {
    fastio;

    cin >> n >> m;
    for (int i=1; i<=n; i++) for (int j=1; j<=n; j++) d[i][j]=(i!=j)*inf;
    for (int i=1; i<=m; i++) {
        int a, b, c; cin >> a >> b >> c;
        d[a][b]=d[b][a]=min(d[a][b], c);
    }

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            for (int k=1; k<=n; k++) {
                d[j][k]=min(d[j][k], d[j][i]+d[i][k]);
            }
        }
    }
    array<int, 3> ans={0, 0, 0};
    for (int i=1; i<=n; i++) for (int j=1; j<=n; j++)
        ans=max(ans, {d[i][j], i, j});

    int x=ans[1];
    for (int i=1; i<=n; i++) cout << d[x][i] << " ";


    return 0;
}
