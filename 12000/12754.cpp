#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, inf=4e18;

int N, A[404040];

int G[404040];
map<int, int> mp[202020];

int dp(int p, int x) {
    if (p>N) return p;
    if (x<min(A[p<<1], A[p<<1|1])) return p;
    if (mp[p].find(x)!=mp[p].end()) return mp[p][x];
    if (A[p<<1]<A[p<<1|1]) return dp(p<<1, x);

    if (x<A[p<<1]) {
        if (dp(p<<1, x)<dp(p<<1|1, x)) return mp[p][x]=dp(p<<1, x);
        return mp[p][x]=dp(p<<1|1, x);
    }
    else {
        if (dp(p<<1, A[p<<1])<dp(p<<1|1, A[p<<1])) return mp[p][x]=dp(p<<1|1, x);
        return mp[p][x]=dp(p<<1, x);
    }
}

void solve(int p) {
    if (p>N) return;
    if (A[p<<1|1]>min(A[p], A[p<<1])) {
        if (A[p]>A[p<<1]) swap(A[p], A[p<<1]);
        solve(p<<1); solve(p<<1|1); return;
    }

    if (A[p<<1]<A[p<<1|1]) swap(A[p], A[p<<1]);
    else swap(A[p], A[p<<1|1]);

    int u=A[p<<1], v=A[p<<1|1]; if (u>v) swap(u, v);
    if (dp(p<<1, u)>dp(p<<1|1, u)) swap(u, v);
    A[p<<1]=u; A[p<<1|1]=v; solve(p<<1); solve(p<<1|1);
}

signed main(){
    fastio;
    
    cin >> N;
    for (int i=1; i<=N; i++) cin >> A[i];
    for (int i=N+1; i<=2*N+10; i++) A[i]=N+1;
    solve(1);

    for (int i=1; i<=N; i++) cout << A[i] << " ";

    return 0;
}
