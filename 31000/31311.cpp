#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef array<int, 2> pii;
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e7+7, MOD=998244353, inf=2147483647;
const int BI=69696969696969;

int n, m;
vector<pii> Lnk[101010];
vector<int> lnk[101010];
vector<array<int, 3>> ed;
set<array<int, 3>> st;
bool use[1010101];
int w;

void mst(){
    priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> pq;
    for(array<int, 3> e : ed) pq.push({e[2], e[1], e[0]});
    vector<int> un(n+1);
    vector<vector<int>> uf(n+1);

    for(int i=1; i<=n; i++) un[i]=i, uf[i].push_back(i);

    while(pq.size()){
        array<int, 3> t=pq.top(); pq.pop();
        if(un[t[1]]==un[t[2]]) continue;
        int a=un[t[1]], b=un[t[2]]; w+=t[0];
        if(uf[a].size()<uf[b].size()) swap(a, b);
        for(int i : uf[b]) un[i]=a, uf[a].push_back(i);
        uf[b].clear();
        lnk[t[1]].push_back(t[2]);
        lnk[t[2]].push_back(t[1]);
        st.insert({min(t[1], t[2]), max(t[1], t[2]), t[0]});
    }
}

const int X=18;
int seg[1<<X+1];

void update(int s, int e, int x){
    s+=1<<X; e+=1<<X;
    while(s<=e){
        if(s&1) seg[s]=min(seg[s], x);
        if(~e&1) seg[e]=min(seg[e], x);
        ++s>>=1; --e>>=1;
    }
}

int sz[101010], tp[101010], dep[101010], pv;
int in[101010], par[101010];

int val(int p){
    int ret=inf; p+=1<<X;
    while(p) ret=min(ret, seg[p]), p>>=1;
    return ret;
}

void dfs0(int p, int pre){
    for(auto it=lnk[p].begin(); it!=lnk[p].end(); it++)
        if(*it==pre){lnk[p].erase(it); break;}
    for(int& i : lnk[p]) dfs0(i, p);
}

void dfs1(int p){
    sz[p]=1;
    for(int& i : lnk[p]){
        par[i]=p; dep[i]=dep[p]+1;
        dfs1(i); sz[p]+=sz[i];
        if(sz[i]>sz[lnk[p][0]]) swap(i, lnk[p][0]);
    }
}

void dfs2(int p){
    in[p]=++pv;
    for(int i : lnk[p]){
        if(i==lnk[p][0]) tp[i]=tp[p];
        else tp[i]=i;
        dfs2(i);
    }
}

void Update(int a, int b, int x){
    while(tp[a]!=tp[b]){
        if(dep[tp[a]]<dep[tp[b]]) swap(a, b);
        update(in[tp[a]], in[a], x);
        a=par[tp[a]];
    }
    if(dep[a]>dep[b]) swap(a, b);
    update(in[a]+1, in[b], x);
}

signed main(){
    fastio;

    cin >> n >> m;
    for(int i=0, a, b, c; i<m; i++){
        cin >> a >> b >> c;
        Lnk[a].push_back({b, c});
        Lnk[b].push_back({a, c});
        ed.push_back({a, b, c});
    }
    mst();

    for(int i=0; i<m; i++){
        array<int, 3> p=ed[i]; if(p[0]>p[1]) swap(p[0], p[1]);
        if(st.find(p)!=st.end()){st.erase(st.find(p)); use[i]=1;}
    }

    tp[1]=1; dfs0(1, 0); dfs1(1); dfs2(1);

    for(int i=1; i<(1<<X+1); i++) seg[i]=inf;
    for(int i=0; i<m; i++){
        if(use[i]) continue;
        array<int, 3> p=ed[i];
        Update(p[0], p[1], p[2]);
    }

    int ret=-1;
    for(int i=0; i<m; i++){
        array<int, 3> p=ed[i];
        if(dep[p[0]]<dep[p[1]]) swap(p[0], p[1]);
        if(!use[i]){ret=max(ret, w); continue;}
        int vl=val(in[p[0]]);
        if(vl==inf) ret=max(ret, -1LL);
        else ret=max(ret, w-p[2]+vl);
    }
    cout << ret;

    return 0;
}
