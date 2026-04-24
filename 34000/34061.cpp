#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;

int bfs(int p, int t, int s, int e, int mx){

    vector<int> dist(p+10, inf), vis(p+10, 0);
    dist[s]=0;
    queue<int> q; q.push(s);
    while(q.size()){
        int x=q.front(); q.pop();
        if(vis[x]++) continue;
        for(int i=(x^t); i<=(x^t)+1; i++){
            if(i>min(mx, p+9)) continue;
            if(dist[i]>dist[x]){
                dist[i]=dist[x]+1;
                q.push(i);
            }
        }
    }
    return dist[e];
}

signed main(){
    fastio;

    int n, x, y, t; cin >> n >> x >> y >> t;
    int p=1; while(p<=t*2) p<<=1;
    if(x/p==y/p){
        int ans=bfs(p, t, x%p, y%p, n-1-(y/p)*p);
        if(ans>=inf) cout << "-1";
        else cout << ans;
    }
    else if(x/p>y/p) cout << "-1";
    else{
        int ans=0;
        ans+=bfs(p, t, x%p, p, inf);
        ans+=bfs(p, t, 0, p, inf)*(y/p-x/p-1);
        ans+=bfs(p, t, 0, y%p, n-1-(y/p)*p);
        if(ans>=inf) cout << "-1";
        else cout << ans;
    }

	return 0;
}
