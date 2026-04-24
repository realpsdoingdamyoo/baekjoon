#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
const int mod=1e9+7, inf=2e18;

int N, C[3030][3030], g[3030], go[3030][3030];
int Find(int x){return g[x]==x?x:g[x]=Find(g[x]);}
vector<int> lnk[3030], v;

void dfs(int p, int x, int c, int n) {
    go[n][p]=c;
    for (int i : lnk[p]) if (i!=x) dfs(i, p, c, n);
}

signed main() {
    fastio;

    cin >> N >> N;
    for (int i=1; i<=N; i++) for (int j=1; j<=N; j++) cin >> C[i][j];
    for (int i=1; i<=N; i++) g[i]=i;
    for (int i=1; i<=N; i++) for (int j=1; j<=N; j++) if (C[i][j]==1 && Find(i)!=Find(j))
        lnk[i].push_back(j), lnk[j].push_back(i), v.push_back(i*mod+j), g[Find(j)]=Find(i);
    for (int i=1; i<=N; i++) for (int j=1; j<=N; j++) if (C[i][j]==2 && Find(i)!=Find(j))
        lnk[i].push_back(j), lnk[j].push_back(i), v.push_back(i*mod+j), g[Find(j)]=Find(i);

    for (int i=1; i<=N; i++) g[i]=i;
    for (int i=1; i<=N; i++) for (int j : lnk[i]) dfs(j, i, j, i);
    for (int i=1; i<=N; i++) for (int j=i+1; j<=N; j++) {
        if (go[i][j]==j) {if (C[i][j]==1) g[Find(i)]=Find(j);}
        else if (C[i][j]==C[i][go[j][i]] && C[i][j]==C[go[i][j]][j] && C[i][j]>C[go[i][j]][go[j][i]]) g[Find(i)]=Find(j);
    }
    for (int i=1; i<=N; i++) cout << Find(i) << " "; cout << "\n";
    for (int i : v) cout << i/mod << " " << i%mod << "\n";


    return 0;
}
