#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;

int N, ans;
vector<array<int, 2>> lnk[252525];
set<array<int, 3>> st[252525];

int C2(int x){return x*(x-1)/2;}
int push(set<array<int, 3>>& s, array<int, 3> p) {
    array<int, 3> it=*prev(s.lower_bound({p[0], inf, inf})), pv, nx;
    int ret=-C2(it[1]-it[0]+1)+C2(p[0]-it[0])+C2(it[1]-p[1])+C2(p[1]-p[0]+1);
    if (it[0]!=p[0]) s.insert({it[0], p[0]-1, 0});
    if (it[1]!=p[1]) s.insert({p[1]+1, it[1], 0});
    s.insert(p); s.erase(s.find(it));

    if (p[0]!=0 && it[0]==p[0]) {
        pv=*prev(s.find(p));
        s.erase(s.find(pv)); s.erase(s.find(p));
        ret+=(p[1]-p[0]+1)*(pv[1]-pv[0]+1);
        s.insert({pv[0], p[1], 1}); p[0]=pv[0];
    }
    if (p[1]!=N-1 && it[1]==p[1]) {
        nx=*next(s.find(p));
        s.erase(s.find(p)); s.erase(s.find(nx));
        ret+=(nx[1]-nx[0]+1)*(p[1]-p[0]+1);
        s.insert({p[0], nx[1], 1});
    }
    return ret;
}

int dfs(int p, int x, int e) {
    if (p!=0) st[p].insert({0, p-1, 0});
    st[p].insert({p, p, 1});
    if (p!=N-1) st[p].insert({p+1, N-1, 0});

    int r=C2(p)+C2(N-p-1);
    for (array<int, 2> i : lnk[p]) if (i[0]!=x) {
        int nr=dfs(i[0], p, i[1]);
        if (st[p].size()<st[i[0]].size()) swap(st[p], st[i[0]]), r=nr;
        for (array<int, 3> v : st[i[0]]) if (v[2]==1) r+=push(st[p], v);
    }
    ans+=(C2(N)-r)%mod*e%mod;
    return r;
}

signed maintenance_costs_sum(vector<signed> U, vector<signed> V, vector<signed> W) {
    N=U.size()+1;
    for (int i=0; i<N-1; i++) {
        lnk[U[i]].push_back({V[i], W[i]});
        lnk[V[i]].push_back({U[i], W[i]});
    }
    dfs(0, -1, 0);
    return ans%mod;
}
