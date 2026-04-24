#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e14;

int n, m;
vector<int> lnk[101010];
int dep[101010], sp[101010][18];
vector<array<int, 3>> del[101010];

void dfs(int p, int pre) {
    sp[p][0]=pre; for (int i=1; i<18; i++) sp[p][i]=sp[sp[p][i-1]][i-1];
    for (int i : lnk[p]) if (i!=pre) dep[i]=dep[p]+1, dfs(i, p);
}
int lca(int a, int b) {
    if (dep[a]<dep[b]) swap(a, b);
    for (int i=17; i>=0; i--) if (dep[a]-dep[b]&(1<<i)) a=sp[a][i];
    if (a==b) return a;
    for (int i=17; i>=0; i--) if (sp[a][i]!=sp[b][i]) a=sp[a][i], b=sp[b][i];
    return sp[a][0];
}
int dist(int a, int b){return dep[a]+dep[b]-2*dep[lca(a, b)];}

int cpr[101010];
vector<int> ctr[101010];
int centout[101010];
int sz[101010];

int D[101010];
vector<int> F[101010], G[101010];

void getsize(int p, int pre) {
    sz[p]=1;
    for (int i : lnk[p]) if (i!=pre && !centout[i]) getsize(i, p), sz[p]+=sz[i];
}
int getcent(int p, int pre, int tsz) {
    for (int i : lnk[p]) if (i!=pre && !centout[i] && sz[i]>tsz/2) return getcent(i, p, tsz);
    return p;
}

void decomp(int p, int pre) {
    getsize(p, 0);
    int cent=getcent(p, 0, sz[p]);
    F[cent].resize(sz[p]+1); G[cent].resize(sz[p]*2+1);
    centout[cent]=1;
    if (pre) cpr[cent]=pre, ctr[pre].push_back(cent);
    for (int i : lnk[cent]) if (!centout[i]) decomp(i, cent);
}

int getF(int p, int x){return F[p].size()>x?F[p][x]:0;}
int getG(int p, int x){return G[p].size()>x?G[p][x]:0;}

int getD(int p, int d) {
    int ret=getF(p, d);
    int c=p;
    while (cpr[c]) {
        ret+=getF(cpr[c], d-dist(cpr[c], p));
        ret-=getG(c, d-dist(cpr[c], p));
        c=cpr[c];
    }
    return ret;
}

void DFS(int p, int pre) {
    for (int i : lnk[p]) if (i!=pre) DFS(i, p), D[p]+=D[i];
    for (array<int, 3> i : del[p]) D[p]=max(D[p], i[2]+getD(i[0], i[1]+1));

    F[p][0]+=D[p];
    if (cpr[p]) G[p][dist(cpr[p], p)]+=D[p];

    int c=cpr[p];
    while (c) {
        F[c][dist(c, p)]+=D[p];
        if (cpr[c]) G[c][dist(cpr[c], p)]+=D[p];
        c=cpr[c];
    }
}

signed main() {
    fastio;

    cin >> n >> m;
    for (int i=1; i<n; i++) {
        int a, b; cin >> a >> b;
        lnk[a].push_back(b);
        lnk[b].push_back(a);
    }
    dfs(1, 0);

    for (int i=1; i<=m; i++) {
        int a, b, c, ap; cin >> a >> b >> c; ap=a;
        for (int j=0; j<18; j++) if (b&(1<<j)) ap=max(1LL, sp[ap][j]);
        del[ap].push_back({a, b, c});
    }

    decomp(1, 0);

    DFS(1, 0);
    cout << D[1];


    return 0;
}
