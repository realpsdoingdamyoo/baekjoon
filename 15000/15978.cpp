#include <bits/stdc++.h>
using namespace std;
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=4e18, bnd=1e10;

int g[303030];
int Find(int x){return g[x]>0?Find(g[x]):x;}
void Union(int a, int b){
    a=Find(a); b=Find(b);
    if(a==b) return;
    if(-g[a]<-g[b]) swap(a, b);
    g[a]+=g[b]; g[b]=a;
}

struct tree{
    int n, k, r;
    int siz[303030], id[303030];
    vector<int> c[303030];

    void input(){
        for(int i=1; i<=n; i++){
            int a; cin >> a;
            if(a==0) r=i;
            else c[a].push_back(i);
        }
    }

    void dfs(int p){
        siz[p]=(p<=k);
        for(int i : c[p]) dfs(i), id[p]=id[i], siz[p]+=siz[i];
        if(p<=k) id[p]=p;
    }

} t1, t2;

signed main(){
    fastio;

    int k;
    cin >> t1.n >> t2.n >> k;
    t1.k=t2.k=k;
    t1.input(); t2.input();

    for(int i=1; i<=303000; i++) g[i]=-1;

    t1.dfs(t1.r); t2.dfs(t2.r);

    vector<array<int, 3>> ord;

    for(int i=k+1; i<=t1.n; i++) ord.push_back({t1.siz[i], 1, i});
    for(int i=k+1; i<=t2.n; i++) ord.push_back({t2.siz[i], 2, i});
    sort(ord.begin(), ord.end());

    for(array<int, 3> i : ord){
        tree& t=(i[1]==1)?t1:t2;
        int p=i[2], sz=i[0];

        for(int j : t.c[p]) Union(t.id[p], t.id[j]);
        if(-g[Find(t.id[p])]>sz){
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";

    return 0;
}
