#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;

int n, dep[101010], ds[101010], dp[101010][18];
vector<array<int, 2>> lnk[101010];

void dfs(int p, int pre){
    for(int i=1; i<18; i++) dp[p][i]=dp[dp[p][i-1]][i-1];
    for(array<int, 2> i : lnk[p]) if(i[0]!=pre){
        dep[i[0]]=dep[p]+1; ds[i[0]]=ds[p]+i[1];
        dp[i[0]][0]=p; dfs(i[0], p);
    }
}

int lca(int a, int b){
    if(dep[a]<dep[b]) swap(a, b);
    for(int i=0; i<18; i++) if(dep[a]-dep[b]&(1<<i)) a=dp[a][i];
    if(a==b) return a;
    for(int i=17; i>=0; i--) if(dp[a][i]!=dp[b][i]) a=dp[a][i], b=dp[b][i];
    return dp[a][0];
}

int up(int a, int x){for(int i=0; i<18; i++) if(x&(1<<i)) a=dp[a][i]; return a;}

signed main(){
    fastio;
    cin >> n;
    for(int i=0; i<n-1; i++){
        int a, b, c; cin >> a >> b >> c;
        lnk[a].push_back({b, c});
        lnk[b].push_back({a, c});
    }
    dfs(1, 0);

    int q; cin >> q;
    while(q--){
        int a; cin >> a;
        if(a==1){
            int b, c; cin >> b >> c;
            cout << ds[b]+ds[c]-2*ds[lca(b, c)] << "\n";
        } else{
            int b, c, d; cin >> b >> c >> d;
            cout << (dep[b]-dep[lca(b, c)]+1>=d?up(b, d-1):up(c, dep[b]+dep[c]-2*dep[lca(b, c)]-d+1)) << "\n";
        }
    }

    return 0;
}
