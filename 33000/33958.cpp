#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;

int n, m, k;
vector<array<int, 2>> lnk[303030], ed;
int dist[303030], vis[303030];
vector<int> dis, prf;

signed main(){
    fastio;

    cin >> n >> m >> k;
    for(int i=0; i<m; i++){
        int a, b, c; cin >> a >> b >> c;
        lnk[a].push_back({b, c});
        lnk[b].push_back({a, c});
        ed.push_back({a, b});
    }
    for(int i=2; i<=n; i++) dist[i]=inf;

    priority_queue<array<int, 2>> pq;
    pq.push({0, 1});

    while(pq.size()){
        int d=-pq.top()[0], p=pq.top()[1]; pq.pop();
        if(vis[p]++) continue;
        for(array<int, 2> i : lnk[p]){
            dist[i[0]]=min(dist[i[0]], d+i[1]);
            pq.push({-dist[i[0]], i[0]});
        }
    }

    for(int i=1; i<=n; i++) dis.push_back(dist[i]);
    dis.push_back(inf);
    sort(dis.begin(), dis.end());

    prf.push_back(dis[0]);
    for(int i=1; i<dis.size(); i++) prf.push_back(prf.back()+dis[i]);

    int ans=0;
    for(int i=0; i<n; i++){
        int s=i+1, e=upper_bound(dis.begin(), dis.end(), dis[i]+k)-dis.begin()-1;
        int cnt=e-s+1, sum=prf[e]-prf[s-1]-dis[i]*cnt;
        ans+=k*cnt+cnt-sum;
    }

    for(array<int, 2> i : ed){
        ans-=max(0LL, k+1-abs(dist[i[0]]-dist[i[1]]));
    }

    cout << ans;


    return 0;
}
