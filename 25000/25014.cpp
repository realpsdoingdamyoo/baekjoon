#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll int
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef array<ll, 2> pii;
typedef array<ll, 3> tii;
typedef vector<pii> vpii;
typedef double lf;
#define V vector
#define PQ priority_queue
//#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define sortv(v) sort(v.begin(), v.end())
#define sortc(v, cmp) sort(v.begin(), v.end(), cmp)
const ll mod=1e7+7, MOD=998244353, inf=2147483647;

int n;
vi lnk[252525];
int dep[252525];
pii down[252525];
int sp[252525][20];
int BI=696969696969;

void Merge(pii& a, int b){
    if(a[0]<b) swap(a[0], b);
    if(a[1]<b) swap(a[1], b);
}

void dfs(int p, int pre, int D){
    sp[p][0]=pre; dep[p]=D;
    for(int i : lnk[p])
        if(i!=pre) dfs(i, p, D+1);
}

void DP(int p, int pre){
    for(int i : lnk[p]){
        if(i==pre) continue;
        DP(i, p);
        Merge(down[p], down[i][0]+1);
    }
}

void RRT(int p, int pre){
    int tm=(down[pre][0]==down[p][0]+1)?down[pre][1]:down[pre][0];
    Merge(down[p], tm+1);
    for(int i : lnk[p])
        if(i!=pre) RRT(i, p);
}

int lca(int a, int b){
    if(dep[a]<dep[b]) swap(a, b);
    for(int i=19; i>=0; i--)
        if(dep[a]-dep[b]&(1<<i)) a=sp[a][i];
    if(a==b) return a;

    for(int i=19; i>=0; i--){
        if(sp[a][i]!=sp[b][i])
            a=sp[a][i], b=sp[b][i];
    }
    return sp[a][0];
}
int dist(int a, int b){
    return dep[a]+dep[b]-2*dep[lca(a, b)];
}

void init(signed N, vector<signed> x, vector<signed> y){
    n=N;
    for(int i=0; i<n-1; i++){
        lnk[x[i]].push_back(y[i]);
        lnk[y[i]].push_back(x[i]);
    }
    dfs(1, 1, 0);

    for(int j=1; j<20; j++)
        for(int i=1; i<=n; i++)
            sp[i][j]=sp[sp[i][j-1]][j-1];

    down[0]={-2, -2};
    DP(1, 0); RRT(1, 0);
}

int clp(int a, int b, int c){
    return lca(a, b)^lca(b, c)^lca(c, a);
}


int fard(int a, int b){
    return (down[a][0]==down[b][0]+1)?down[a][1]:down[a][0];
}

vi trainfind(int a, int b){
    vi ret;
    int l=lca(a, b), d=dist(a, l);
    while(a!=l) ret.push_back(a), a=sp[a][0];
    while(b!=l) ret.push_back(b), b=sp[b][0];
    ret.push_back(l);
    reverse(ret.begin()+d, ret.end());
    return ret;
}

int tps(int a, int b, int m, vi tr){
    int s=m, e=m, len=tr.size()-1;

    int ret=0;
    int smn=m, emx=m-1;
    for(int i=0;; i++){
        if(e-s+1>=tr.size()) break;

        if(i%2==0){
            while(0<s && fard(tr[s-1], tr[s])+(e-s+1)>=len) s--;
            ret+=len-(e-s);
        }
        else{
            while(e<len && fard(tr[e+1], tr[e])+(e-s+1)>=len) e++;
            ret+=len-(e-s);
        }
        if(smn<=s && e<=emx) return BI;
        smn=min(s, smn); emx=max(e, emx);
    }
    return ret;
}

int onetrain(int a, int b, int m){
    int ret1=tps(a, b, dist(a, m), trainfind(a, b));
    int ret2=tps(b, a, dist(b, m), trainfind(b, a));
    return min(ret1, ret2);
}

int train(vector<signed> z){
    pii a={z[0], z[1]}, b={z[2], z[3]};
    int len=dist(a[0], a[1]);
    int ma=clp(a[0], a[1], b[0]), mb=clp(b[0], b[1], a[0]);
    int ta=onetrain(a[0], a[1], ma);
    int tb=onetrain(b[0], b[1], mb);
    int ret=ta+tb+len+dist(ma, mb);
    if(ret>BI) return -1;
    return ret;
}
