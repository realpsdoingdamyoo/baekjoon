#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e17;

int n, m;
vector<int> lnk[303030];

const int X=19;
int seg[2][1<<X+1];
void update(int s, int e, int x, int y) {
    s+=1<<X; e+=1<<X;
    while (s<=e) {
        if (s&1) seg[y][s]+=x; ++s>>=1;
        if (~e&1) seg[y][e]+=x; --e>>=1;
    }
}
int val(int p, int y) {
    int ret=0; p+=1<<X;
    while (p) ret+=seg[y][p], p>>=1;
    return ret;
}

int seg2[1<<X+1];
void update2(int p, int x) {
    p+=1<<X;
    while (p) seg2[p]+=x, p>>=1;
}
int sum(int s, int e) {
    s+=1<<X; e+=1<<X; int r=0;
    while (s<=e) {
        if (s&1) r+=seg2[s]; ++s>>=1;
        if (~e&1) r+=seg2[e]; --e>>=1;
    } return r;
}

int g[303030], e[303030], deg[303030];
int Find(int x){return g[x]<=0?x:g[x]=Find(g[x]);}
void Union(int a, int b) {
    a=Find(a); b=Find(b);
    if (a==b) return;
    g[a]+=g[b], g[b]=a, e[a]+=e[b];
}
vector<array<int, 3>> edg;
vector<int> adj[303030];
int vis[303030];

array<int, 2> DFS(int p) {
    vis[p]=1; int ret0=lnk[p][lnk[p].size()-3]+1, ret1=lnk[p][lnk[p].size()-2];
    for (int i : adj[p]) if (!vis[i]) {
        array<int, 2> rt=DFS(i);
        ret0=max(ret0, rt[0]);
        ret1=min(ret1, rt[1]);
    }
    return {ret0, ret1};
}

signed main() {
    fastio;

    cin >> n >> m;
    for (int i=1; i<=m; i++) {
        int a, b, c; cin >> a >> b >> c;
        lnk[a].push_back(c);
        lnk[b].push_back(c);
        update2(c, 1);
        edg.push_back({c, a, b});
    }

    for (int i=1; i<=n; i++) {
        lnk[i].push_back(-1);
        lnk[i].push_back(-1);
        lnk[i].push_back(-1);
        sort(lnk[i].begin(), lnk[i].end());
    }

    for (int i=1; i<=n; i++) g[i]=-1;

    sort(edg.begin(), edg.end());
    reverse(edg.begin(), edg.end());

    for (array<int, 3> i : edg) {
        adj[i[1]].push_back(i[2]);
        adj[i[2]].push_back(i[1]);
        Union(i[1], i[2]);
        deg[i[1]]++; deg[i[2]]++;
        int x=Find(i[1]);
        e[x]+=(deg[i[1]]==2)-(deg[i[1]]==3);
        e[x]+=(deg[i[2]]==2)-(deg[i[2]]==3);
        if (g[x]+e[x]!=0) continue;
        array<int, 2> y=DFS(i[1]);
        update(y[0], y[1], -1, 0);
    }

    for (int i=1; i<=n; i++) update(lnk[i][lnk[i].size()-3]+1, lnk[i][lnk[i].size()-2], 1, 0);
    for (int i=1; i<=n; i++) update(lnk[i][lnk[i].size()-1]+1, 303030, 1, 1);
    int q; cin >> q;
    while (q--) {
        int a; cin >> a;
        int ans=m-sum(0, a-1)-val(a, 0);
        cout << n-val(a, 0)-val(a, 1) << " " << ans << " " << "\n";
    }


    return 0;
}
