#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
const int mod=1e9+7, MOD=998244353, inf=2e18;

int N;
vector<array<int, 2>> lnk[505050];
set<array<int, 2>> st[505050];

void dfs(int p, int x) {
    for (array<int, 2> i : lnk[p]) if (i[0]!=x) {
        dfs(i[0], p); array<int, 2> fp;
        if (!st[i[0]].size()) fp={0, i[0]};
        else fp=*prev(st[i[0]].end());
        st[p].insert({fp[0]+i[1], fp[1]});
    }
}

void rrt(int p, int x) {
    for (array<int, 2> i : lnk[p]) if (i[0]!=x) {
        array<int, 2> fp=*prev(st[p].end());
        if (st[i[0]].size() && (*prev(st[p].end()))[1]==(*prev(st[i[0]].end()))[1]) fp=*prev(prev(st[p].end()));
        st[i[0]].insert({fp[0]+i[1], fp[1]});
        rrt(i[0], p);
    }
}

int g[505050];
int Find(int x){return g[x]<0?x:g[x]=Find(g[x]);}
void Union(int a, int b){a=Find(a); b=Find(b); g[a]+=g[b]; g[b]=a;}

signed travel(vector<signed> u, vector<signed> v, vector<signed> w) {
    N=u.size()+1; if (N==2) return w[0]*2;
    for (int i=0; i<N-1; i++) lnk[u[i]].push_back({v[i], w[i]}), lnk[v[i]].push_back({u[i], w[i]});
    int r=0;
    for (int i=0; i<N; i++) if (lnk[i].size()>=2) {r=i; break;}
    dfs(r, -1);
    rrt(r, -1);

    vector<array<int, 3>> ed;
    for (int i=0; i<N; i++) for (array<int, 2> j : st[i]) ed.push_back({j[0], i, j[1]});
    sort(ed.begin(), ed.end()); reverse(ed.begin(), ed.end());

    int R=0;
    fill(g, g+N, -1);
    for (array<int, 3> i : ed) if (Find(i[1])!=Find(i[2])) {
        R+=i[0]%mod*(g[Find(i[1])]*g[Find(i[2])]%mod)%mod;
        Union(i[1], i[2]);
    }
    return R*2%mod;
}
