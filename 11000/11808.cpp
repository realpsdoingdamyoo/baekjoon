#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2147483647202020;

int n, k;
vector<array<int, 2>> lnk[1010];
int d[1010][110];

void dfs(int p){
    for(int i=0; i<=k+1; i++) d[p][i]=-inf;
    if(p!=1) d[p][0]=0; d[p][1]=0;
    for(array<int, 2> c : lnk[p]){
        dfs(c[0]);
        for(int i=k+1; i>=0; i--) for(int j=0; j<=i; j++)
            d[p][i]=max(d[p][i], d[p][i-j]+d[c[0]][j]+2*c[1]*min(j, k-j+1));
    }
}

void solve(int T){
    cin >> n >> k;
    for(int i=1; i<=n; i++) lnk[i].clear();
    for(int i=2; i<=n; i++){
        int a, b; cin >> a >> b;
        lnk[a].push_back({i, b});
    }
    dfs(1);
    cout << "Case " << T << ": " << d[1][k+1] << "\n";
}

signed main() {
    fastio;

    int t; cin >> t;
    for(int i=1; i<=t; i++) solve(i);

    return 0;
}
