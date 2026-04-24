#include "towns.h"
#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;

int n;
int r[2];

map<array<int, 2>, int> mem;
int get(int a, int b){
    if(a>b) swap(a, b);
    if(a==b) return 0;
    if(mem.find({a, b})==mem.end())
        return mem[{a, b}]=getDistance(a, b);
    return mem[{a, b}];
}

int dis[2][111];
int R=inf;

int iss(int a, int b, int d){
    int dra=dis[0][r[0]]+(dis[1][a]-dis[0][a])>>1;
    int drb=dis[0][r[0]]+(dis[1][b]-dis[0][b])>>1;
    if(dra<d && drb<d) return true;
    if(dra<d || drb<d) return false;

    int lca=get(r[0], a)+get(r[0], b)-get(a, b);
    return lca!=d*2;
}

vector<int> lnk[111];
bool vis[111];

int dfs(int p){
    vis[p]=true;
    int c=1;
    for(int i : lnk[p]) if(!vis[i]) c+=dfs(i);
    return c;
}

int hubDistance(int N, int sub){
    n=N; R=inf; mem.clear();
    for(int i=0; i<n; i++) lnk[i].clear(), vis[i]=false;

    array<int, 2> mx={0, 0};
    for(int i=0; i<n; i++){
        dis[0][i]=get(0, i);
        mx=max(mx, {dis[0][i], i});
    }
    r[0]=mx[1];
    mx={0, 0};
    for(int i=0; i<n; i++){
        dis[1][i]=get(r[0], i);
        mx=max(mx, {dis[1][i], i});
    }
    r[1]=mx[1];

    map<int, int> cnt;
    map<int, int> sum;

    for(int i=0; i<n; i++){
        int d0=dis[0][r[0]]+(dis[1][i]-dis[0][i])>>1;
        R=min(R, max(d0, dis[1][r[1]]-d0));
        cnt[d0]++;
    }

    int prvs=0;
    for(auto it=prev(cnt.end());; it--){
        int p=(*it).first;
        sum[p]=cnt[p]+prvs;
        prvs=sum[p];
        if(it==cnt.begin()) break;
    }

    int cen=-1, xv=inf;
    for(int i=0; i<n; i++){
        int d0=dis[0][r[0]]+(dis[1][i]-dis[0][i])>>1;
        if(R!=max(d0, dis[1][r[1]]-d0)) continue;
        int bc=sum[d0]-cnt[d0], fr=n-sum[d0];
        if(max(max(bc, fr), cnt[d0])>n/2 && max(max(bc, fr), cnt[d0])<xv){
            cen=d0;
            xv=min(xv, max(max(bc, fr), cnt[d0]));
        }
        else if(max(max(bc, fr), cnt[d0])<=n/2) return R;
    }

    int mxv=0, mxc=1;
    for(int i=1; i<n; i++){
        if(iss(mxv, i, cen)){
            mxc++;
            lnk[mxv].push_back(i);
            lnk[i].push_back(mxv);
        }
        else if(mxc) mxc--;
        else mxv=i, mxc=1;
    }

    int cn=0, dn=0;
    for(int i=0; i<n; i++){
        if(vis[i]) continue;
        if(iss(i, mxv, cen)) cn+=dfs(i);
        else dn+=dfs(i);
        if(cn>n/2) return -R;
        if(dn>=n-n/2) return R;
    }

    return R;
}
