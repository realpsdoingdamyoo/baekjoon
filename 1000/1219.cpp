#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=4e18;

int n, m, s, e;
vector<int> lnk[55];
vector<array<int, 3>> ed;
vector<int> dist, Dist, cst;

vector<bool> dv;

void dfs(int p){
    if(dv[p]) return;
    dv[p]=1;
    for(int i : lnk[p]) dfs(i);
}

signed main() {
    fastio;

    cin >> n >> s >> e >> m;
    ed.resize(m); dist.resize(n); cst.resize(n);
    dv.resize(n);
    for(array<int, 3>& i : ed){
        cin >> i[0] >> i[1] >> i[2];
        lnk[i[0]].push_back(i[1]);
    }
    for(int& i : cst) cin >> i;
    for(array<int, 3>& i : ed) i[2]-=cst[i[1]];

    for(int i=0; i<n; i++) dist[i]=inf;
    dist[s]=0;

    for(int t=0; t<n-1; t++)
        for(array<int, 3> i : ed)
            if(dist[i[0]]!=inf && dist[i[0]]+i[2]<dist[i[1]])
                dist[i[1]]=dist[i[0]]+i[2];

    if(dist[e]==inf){cout << "gg\n"; return 0;}

    Dist=dist;
    for(array<int, 3> i : ed)
        if(Dist[i[0]]!=inf && Dist[i[0]]+i[2]<Dist[i[1]])
            Dist[i[1]]=Dist[i[0]]+i[2];

    for(int i=0; i<n; i++) if(Dist[i]!=dist[i]) dfs(i);
    if(dv[e]){cout << "Gee\n"; return 0;}

    int ret=-dist[e]+cst[s];
    cout << ret << "\n";

    return 0;
}
