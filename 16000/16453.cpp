#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, inf=1e18;

int N, Q;
vector<int> lnk[101010];
int sp[101010][20], dep[101010];

void dfs(int p, int x) {
    for (int i : lnk[p]) if (i!=x) {
        sp[i][0]=p; for (int j=1; j<20; j++) sp[i][j]=sp[sp[i][j-1]][j-1];
        dep[i]=dep[p]+1; dfs(i, p);
    }
}

int lca(int a, int b) {
    if (dep[a]<dep[b]) swap(a, b);
    for (int i=19; i>=0; i--) if (dep[a]-dep[b]&1<<i) a=sp[a][i];
    for (int i=19; i>=0; i--) if (sp[a][i]!=sp[b][i]) a=sp[a][i], b=sp[b][i];
    return a==b?a:sp[a][0];
}
int lca(int a, int b, int c) {
    return lca(a, b)^lca(b, c)^lca(c, a);
}
int dist(int a, int b) {
    return dep[a]+dep[b]-2*dep[lca(a, b)];
}

signed main() {
    fastio;

    cin >> N >> Q;
    for (int i=1, a, b; i<N; i++) cin >> a >> b, lnk[a].push_back(b), lnk[b].push_back(a);
    dfs(1, 0);

    for (int i=1; i<=Q; i++) {
        int a, b, c, d; cin >> a >> b >> c >> d;
        int x=lca(a, b, c), y=lca(a, b, d);
        if (x==y) cout << (lca(c, d, x)==x) << "\n";
        else cout << dist(x, y)+1 << "\n";
    }

    return 0;
}
