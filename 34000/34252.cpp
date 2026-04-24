#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;

int n, m;
vector<array<int, 2>> lnk[101010];
array<int, 2> dp[101010];
bool vis[101010], vis2[101010];
int dist[101010];

int inv(int x){
    int ret=1, pw=MOD-2;
    while(pw){
        if(pw&1) ret=ret*x%MOD;
        x=x*x%MOD; pw>>=1;
    }
    return ret;
}

signed main(){
    fastio;

    cin >> n >> m;
    for(int i=0; i<m; i++){
        int a, b, c; cin >> a >> b >> c;
        lnk[a].push_back({b, c});
        lnk[b].push_back({a, c});
    }

    for(int i=2; i<=n; i++) dist[i]=inf;
    queue<int> q; q.push(1);

    dp[1][1]=1;
    while(q.size()){
        int p=q.front(); q.pop();
        if(vis[p]) continue;
        vis[p]=true;

        for(array<int, 2> i : lnk[p]){
            q.push(i[0]);
            dist[i[0]]=min(dist[i[0]], dist[p]+1);
            if(dist[i[0]]==dist[p]-1){
                dp[p][0]+=dp[i[0]][0]+i[1]*dp[i[0]][1]%MOD;
                dp[p][1]+=dp[i[0]][1];
            }
        }
        dp[p][0]%=MOD; dp[p][1]%=MOD;
    }

    for(int i=2; i<=n; i++){
        cout << dp[i][0]*inv(dp[i][1])%MOD << "\n";
    }

    return 0;
}
