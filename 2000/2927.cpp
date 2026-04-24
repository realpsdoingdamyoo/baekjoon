#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;

int g[30303];
int Find(int x){return g[x]<0?x:Find(g[x]);}
void Union(int a, int b){
    a=Find(a); b=Find(b);
    if(a==b) return;
    if(-g[a]<-g[b]) swap(a, b);
    g[a]+=g[b]; g[b]=a;
}

int n, q, c[30303];
vector<int> lnk[30303];
vector<array<int, 3>> qry;

int par[30303], sz[30303], dep[30303];
int tp[30303], in[30303], out[30303], cn;

void dfs0(int p, int pre){
    for(vector<int>::iterator it=lnk[p].begin(); it!=lnk[p].end(); it++)
        if(*it==pre){lnk[p].erase(it); break;}
    for(int i : lnk[p]) dfs0(i, p);
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
    in[p]=++cn;
    for(int i : lnk[p]){
        if(i==lnk[p][0]) tp[i]=tp[p]; else tp[i]=i;
        dfs2(i);
    }
    out[p]=cn;
}

const int X=17;
int seg[1<<X+1];
void update(int p, int x){
    p+=1<<X; seg[p]=x; p>>=1;
    while(p) seg[p]=seg[p<<1]+seg[p<<1|1], p>>=1;
}
int sum(int s, int e){
    s+=1<<X; e+=1<<X; int r=0;
    while(s<=e){
        if(s&1) r+=seg[s];
        if(~e&1) r+=seg[e];
        ++s>>=1; --e>>=1;
    } return r;
}

int hq(int a, int b){
    int ret=0;
    while(tp[a]!=tp[b]){
        if(dep[tp[a]]<dep[tp[b]]) swap(a, b);
        ret+=sum(in[tp[a]], in[a]);
        a=par[tp[a]];
    }
    if(dep[a]>dep[b]) swap(a, b);
    ret+=sum(in[a], in[b]);
    return ret;
}

signed main(){
	fastio;

    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> c[i]; g[i]=-1;
    }

    cin >> q;
    for(int i=0; i<q; i++){
        string s; int a, b;
        cin >> s >> a >> b;
        if(s=="bridge"){
            qry.push_back({1, a, b});
            if(Find(a)!=Find(b)){
                Union(a, b);
                lnk[a].push_back(b);
                lnk[b].push_back(a);
            }
        }
        else if(s=="penguins") qry.push_back({2, a, b});
        else qry.push_back({3, a, b});
    }

    for(int i=2; i<=n; i++) if(Find(1)!=Find(i)){
        lnk[1].push_back(i);
        lnk[i].push_back(1);
        Union(1, i);
    }

    for(int i=1; i<=n; i++) g[i]=-1;

    dfs0(1, 0); dfs1(1); dfs2(1);
    for(int i=1; i<=n; i++) update(in[i], c[i]);


    for(array<int, 3> i : qry){
        if(i[0]==1){
            if(Find(i[1])==Find(i[2])) cout << "no\n";
            else{
                cout << "yes\n";
                Union(i[1], i[2]);
            }
        }
        else if(i[0]==2){
            update(in[i[1]], i[2]);
        }
        else{
            if(Find(i[1])!=Find(i[2])) cout << "impossible\n";
            else cout << hq(i[1], i[2]) << "\n";
        }

    }

    return 0;
}
