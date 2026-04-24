#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=4e18;

int n, o, s, e, m, _p, _q;
vector<int> lnk[5050];
int dn[1010][5050];

int dist[1010][5050];

signed main() {
    fastio;

    cin >> n >> o >> s >> e >> m;
    for (int i=1; i<=m; i++) {
        int a, b; cin >> a >> b;
        lnk[a].push_back(b);
        lnk[b].push_back(a);
    }
    cin >> _p;
    for (int i=1; i<=_p; i++) {
        int a, b; cin >> a >> b;
        dn[a][b]=1;
    }

    for (int i=1; i<=o; i++) for (int j=1; j<=n; j++) dist[i][j]=inf;
    dist[1][s]=0;

    queue<array<int, 2>> q; q.push({1, s});

    while (q.size()) {
        array<int, 2> p=q.front(); q.pop();

        for (int i : lnk[p[1]]) if (dist[p[0]][i]==inf){
            dist[p[0]][i]=dist[p[0]][p[1]]+1;
            q.push({p[0], i});
        }
        if (dn[p[0]][p[1]] && dist[p[0]+1][p[1]]==inf) {
            dist[p[0]+1][p[1]]=dist[p[0]][p[1]]+1;
            q.push({p[0]+1, p[1]});
        }
    }

    cin >> _q;
    while (_q--) {
        if (dist[o][e]==inf){cout << "-1\n"; continue;}
        int a, b; cin >> a >> b;
        cout << a*(dist[o][e]-o+1)+b*(o-1) << "\n";
    }

    return 0;
}
