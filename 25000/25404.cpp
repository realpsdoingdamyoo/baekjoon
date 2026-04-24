#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e14;

int n;
int v[101010], h;
vector<int> comp;
vector<int> cn[101010];
int dist[202020], vis[202020];
vector<array<int, 2>> lnk[202020];

signed main() {
    fastio;

    cin >> n;
    for (int i=1; i<=n; i++) {cin >> v[i]; comp.push_back(v[i]);}
    sort(comp.begin(), comp.end());
    comp.erase(unique(comp.begin(), comp.end()), comp.end());
    for (int i=1; i<=n; i++) {
        v[i]=lower_bound(comp.begin(), comp.end(), v[i])-comp.begin()+1;
        cn[v[i]].push_back(i);
        h=max(h, v[i]);
    }

    for (int i=1; i<=n; i++) {
        int k=cn[v[i]].size();
        int id=lower_bound(cn[v[i]].begin(), cn[v[i]].end(), i)-cn[v[i]].begin();
        int pid=cn[v[i]][(id+k-1)%k], nid=cn[v[i]][(id+1)%k];
        lnk[i].push_back({pid, (i-pid+n)%n}); lnk[i].push_back({nid, (nid-i+n)%n});
        lnk[i].push_back({pid+n, (pid-i+n)%n}); lnk[i].push_back({nid+n, (i-nid+n)%n});
    }
    for (int i=1; i<=n; i++) {
        if (v[i]==h) continue;
        int k=cn[v[i]+1].size();
        int pid=cn[v[i]+1][(lower_bound(cn[v[i]+1].begin(), cn[v[i]+1].end(), i)-cn[v[i]+1].begin())%k];
        int nid=cn[v[i]+1][(lower_bound(cn[v[i]+1].begin(), cn[v[i]+1].end(), i)-cn[v[i]+1].begin()+k-1)%k];
        lnk[i+n].push_back({pid, min((i-pid+n)%n, (pid-i+n)%n)}); lnk[i+n].push_back({nid, min((i-nid+n)%n, (nid-i+n)%n)});
    }

    priority_queue<array<int, 2>, vector<array<int, 2>>, greater<array<int, 2>>> pq;
    for (int i=1; i<=n; i++) if (v[i]==1) pq.push({min((i-1)%n, (n-i+1)%n), i});
    for (int i=1; i<=2*n; i++) dist[i]=inf;
    for (int i=1; i<=n; i++) if (v[i]==1) dist[i]=min((i-1)%n, (n-i+1)%n);

    while (pq.size()) {
        int d=pq.top()[0], p=pq.top()[1]; pq.pop();
        if (vis[p]++) continue;
        for (array<int, 2> i : lnk[p]) {
            pq.push({d+i[1], i[0]});
            dist[i[0]]=min(dist[i[0]], d+i[1]);
        }
    }

    int ans=inf;
    for (int i=1; i<=n; i++) if (v[i]==h) ans=min(ans, dist[i+n]);
    cout << ans;


    return 0;
}
