#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e15;

typedef priority_queue<array<int, 2>, vector<array<int, 2>>, greater<array<int, 2>>> PQ;

int n;
int c[202020];
vector<int> lnk[202020];

PQ dfs(int x, int p){
    PQ pq;
    for(int i : lnk[x]){
        if(i==p) continue;
        PQ t=dfs(i, x);
        if(t.size()>pq.size()) swap(t, pq);
        while(t.size()){
            pq.push(t.top());
            t.pop();
        }
    }

    array<int, 2> t={max(-c[x], 0LL), max(c[x], 0LL)};
    while(pq.size() && (t[1]<=t[0] || t[1]>=pq.top()[0])){
        array<int, 2> u=pq.top(); pq.pop();
        int a=t[1]-t[0]+u[1]-u[0];
        t[0]=max(t[0], t[0]-t[1]+u[0]); t[1]=a+t[0];
    }
    if(t[0]<t[1]) pq.push(t);
    return pq;
}

void solve(){
    int x; cin >> n >> x;
    for(int i=1; i<=n; i++) cin >> c[i]; c[n+1]=inf;
    for(int i=0; i<n-1; i++){
        int a, b; cin >> a >> b;
        lnk[a].push_back(b);
        lnk[b].push_back(a);
    }
    lnk[x].push_back(n+1);
    lnk[n+1].push_back(x);

    PQ ret=dfs(1, 0);
    int ans=0;
    while(ret.size()){
        array<int, 2> t=ret.top(); ret.pop();
        if(ans<t[0]) break;
        ans+=t[1]-t[0];
    }
    if(ans>inf/2) cout << "escaped\n";
    else cout << "trapped\n";

    for(int i=1; i<=n+1; i++) lnk[i].clear();
}

signed main(){
    fastio;

    int T; cin >> T;
    while(T--) solve();

    return 0;
}
