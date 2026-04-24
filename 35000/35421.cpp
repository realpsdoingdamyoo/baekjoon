#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=1e18;

int N, M, Q;
vector<array<int, 2>> lnk[101010], gr[101010];
vector<int> lef;

array<int, 2> qry[101010];
int ans[101010];

int g[101010];
int Find(int x){return g[x]==x?x:g[x]=Find(g[x]);}

int D[101010], vis[101010];

int dep[101010], dis[101010], sp[101010][20];

void dfs(int p, int x) {
    for (int i=1; i<20; i++) sp[p][i]=sp[sp[p][i-1]][i-1];
    for (array<int, 2> i : lnk[p]) if (i[0]!=x) {
        sp[i[0]][0]=p; dep[i[0]]=dep[p]+1; dis[i[0]]=dis[p]+i[1]; dfs(i[0], p);
    }
}

int lca(int a, int b) {
    if (dep[a]<dep[b]) swap(a, b);
    for (int i=19; i>=0; i--) if (dep[a]-dep[b]&1<<i) a=sp[a][i];
    for (int i=19; i>=0; i--) if (sp[a][i]!=sp[b][i]) a=sp[a][i], b=sp[b][i];
    return a==b?a:sp[a][0];
}

int dist(int a, int b) {return dis[a]+dis[b]-2*dis[lca(a, b)];}

signed main(){
    fastio;

    cin >> N >> M;
    for (int i=1; i<=N; i++) g[i]=i;
    for (int i=1; i<=M; i++) {
        int a, b, c; cin >> a >> b >> c;
        gr[a].push_back({b, c}); gr[b].push_back({a, c});
        if (Find(a)!=Find(b)) {
            lnk[a].push_back({b, c}); lnk[b].push_back({a, c});
            g[Find(a)]=Find(b);
        }
        else lef.push_back(a);
    }

    cin >> Q;
    for (int i=1; i<=Q; i++) cin >> qry[i][0] >> qry[i][1], ans[i]=inf;

    for (int p : lef) {
        fill(D+1, D+N+1, inf); D[p]=0; fill(vis+1, vis+N+1, 0);
        priority_queue<array<int, 2>, vector<array<int, 2>>, greater<array<int, 2>>> pq;
        pq.push({0, p});

        while (pq.size()) {
            int x=pq.top()[1]; pq.pop();
            if (vis[x]++) continue;
            for (array<int, 2> i : gr[x]) if (D[i[0]]>D[x]+i[1])
                D[i[0]]=D[x]+i[1], pq.push({D[i[0]], i[0]});
        }

        for (int i=1; i<=Q; i++) ans[i]=min(ans[i], D[qry[i][0]]+D[qry[i][1]]);
    }

    dfs(1, 0);

    for (int i=1; i<=Q; i++) cout << min(ans[i], dist(qry[i][0], qry[i][1])) << "\n";

    return 0;
}
