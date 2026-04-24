#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2.1e9;

#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,sse,sse2")

int N, M, L, Q, ans[303030];
vector<vector<int>> V, id;
int U[303030];

int g[303030];
int Find(int x) {return g[x]==x?x:g[x]=Find(g[x]);}
vector<int> lnk[303030];
void Union(int a, int b) {
    if (Find(a)==Find(b)) return;
    lnk[b].push_back(Find(a)); g[Find(a)]=b;
}

vector<array<int, 2>> vec;
int sp[303030][20], lp[303030][20], dep[303030];
void dfs(int p) {
    vec.push_back({U[p], p});
    for (int i : lnk[p]) {
        if (U[p]<=U[i]+L) {
            int s=0, e=vec.size()-1;
            while (s<=e) {
                int m=s+e>>1;
                if (vec[m][0]>U[i]+L) s=m+1;
                else e=m-1;
            }
            sp[i][0]=vec[s][1];
        }
        else sp[i][0]=i;
        lp[i][0]=p; dep[i]=dep[p]+1;
        for (int j=1; j<20; j++) sp[i][j]=sp[sp[i][j-1]][j-1], lp[i][j]=lp[lp[i][j-1]][j-1];
        dfs(i);
    }
    vec.pop_back();
}

int lca(int a, int b) {
    if (dep[a]<dep[b]) swap(a, b);
    for (int i=19; i>=0; i--) if (dep[a]-dep[b]&1<<i) a=lp[a][i];
    if (a==b) return a;
    for (int i=19; i>=0; i--) if (lp[a][i]!=lp[b][i]) a=lp[a][i], b=lp[b][i];
    return lp[a][0];
}

signed main(){
    fastio;

    cin >> N >> M >> L;
    V=vector<vector<int>>(N+2, vector<int>(M+2, inf));
    id=vector<vector<int>>(N+2, vector<int>(M+2));
    for (int i=1; i<=N; i++) for (int j=1; j<=M; j++) cin >> V[i][j], id[i][j]=i*M-M+j;
    cin >> Q;

    for (int i=1; i<=N; i++) for (int j=1; j<=M; j++) U[id[i][j]]=V[i][j];

    vector<array<int, 3>> v;
    for (int i=1; i<=N; i++) for (int j=1; j<=M; j++) v.push_back({V[i][j], i, j});
    sort(v.begin(), v.end());

    for (int i=1; i<=N*M; i++) g[i]=i;
    for (array<int, 3> i : v) {
        int x=i[1], y=i[2];
        if (V[x][y]>=V[x-1][y]) Union(id[x-1][y], id[x][y]);
        if (V[x][y]>=V[x+1][y]) Union(id[x+1][y], id[x][y]);
        if (V[x][y]>=V[x][y-1]) Union(id[x][y-1], id[x][y]);
        if (V[x][y]>=V[x][y+1]) Union(id[x][y+1], id[x][y]);
    }

    int rt=id[v.back()[1]][v.back()[2]];
    for (int i=0; i<20; i++) sp[rt][i]=rt, lp[rt][i]=rt;
    dfs(rt);

    while (Q--) {
        int a, b, c, d; cin >> a >> b >> c >> d;
        int x=id[a][b], y=id[c][d];
        int l=lca(x, y), ret=0;
        for (int i=19; i>=0; i--) {
            if (U[sp[x][i]]<U[l]) x=sp[x][i], ret+=1<<i;
        }
        if (ret>N*M) cout << "-1\n";
        else cout << ret+1 << "\n";
    }


    return 0;
}
