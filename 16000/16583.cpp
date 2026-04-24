#include <bits/stdc++.h>
#define int long long
using namespace std;
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
const int mod=1e9+7, MOD=998244353, inf=1e18;

vector<int> lnk[202020];
int vis[202020], avs[202020];
map<int, int> del[202020];
int dmy[202020];
int dm;
vector<array<int, 3>> ans;

void dfs(int p, int x){
    vis[p]=true;
    for(int& i : lnk[p]){
        if(i==x || del[p][i]) continue;
        if(vis[i]){
            del[i][p]=1;
            dmy[dm]=i;
            i=dm++;
        }
        else dfs(i, p);
    }
}

bool adfs(int p, int x){
    avs[p]=true;
    vector<int> it;
    for(int i : lnk[p]){
        if(i==x || del[p][i]) continue;
        if(adfs(i, p)) it.push_back(i);
    }
    while(it.size()>=2){
        int a=it.back(); it.pop_back();
        int b=it.back(); it.pop_back();
        ans.push_back({dmy[a], dmy[p], dmy[b]});
    }
    if(it.size()==0) return true;
    if(x==0) return false;
    ans.push_back({dmy[x], dmy[p], dmy[it.back()]});
    return false;
}

signed main(){
    fastio;

    int N, M; cin >> N >> M;
    for (int i=1; i<=N; i++) dmy[i]=i;
    dm=N+1;

    for (int i=1; i<=M; i++) {
        int a, b; cin >> a >> b;
        lnk[a].push_back(b); lnk[b].push_back(a);
    }
    for (int i=1; i<=N; i++) if(!vis[i]) dfs(i, 0);
    for (int i=1; i<=N; i++) if(!avs[i]) adfs(i, 0);
    cout << ans.size() << "\n";
    for(array<int, 3> i : ans) cout << i[0] << " " << i[1] << " " << i[2] << "\n";

    return 0;
}
