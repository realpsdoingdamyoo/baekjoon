#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;

int n, m;
vector<int> lnk[101010];
array<int, 2> cyc[101010];
bool vis[101010], r[101010];
int dep[101010], npr[101010];

int oc=0;
vector<array<int, 2>> vec;

void dfs(int p, int pre, int d){
    vis[p]=true; dep[p]=d;
    for(int i : lnk[p]){
        if(i==pre){
            if(!npr[p]++) continue;
        }
        if(vis[i] && dep[i]<dep[p]){
            if((dep[p]-dep[i])%2) cyc[p][1]++, cyc[i][1]--, vec.push_back({0, 1});
            else cyc[p][0]++, cyc[i][0]--, oc++, vec.push_back({1, 0});
        }
        else if(!vis[i]) dfs(i, p, d+1);
    }
}

void dfs2(int p, int pre){
    vis[p]=true;
    for(int i : lnk[p]) if(i!=pre && !vis[i]){
        dfs2(i, p);
        cyc[p][0]+=cyc[i][0]; cyc[p][1]+=cyc[i][1];
    }
}

signed main(){
    fastio;

    cin >> n >> m;
    for(int i=0; i<m; i++){
        int a, b; cin >> a >> b;
        lnk[a].push_back(b);
        lnk[b].push_back(a);
    }

    for(int i=1; i<=n; i++) if(!vis[i]) dfs(i, 0, 0);
    for(int i=1; i<=n; i++) vis[i]=false;
    for(int i=1; i<=n; i++) if(!vis[i]) r[i]=1, dfs2(i, 0);

    int ans=0;
    for(int i=1; i<=n; i++)
        if(!r[i] && cyc[i][0]==oc && cyc[i][1]==0) ans++;
    for(array<int, 2> i : vec)
        if(i[0]==oc && i[1]==0) ans++;

    cout << ans;

    return 0;
}
