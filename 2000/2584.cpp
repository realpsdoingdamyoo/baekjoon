#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e10;

const int MX=1010;

int n, k;
vector<array<int, 2>> lnk[MX];
int dp[MX][MX], dp2[MX][MX], sz[MX];
vector<array<int, 2>> cut[MX][MX], cut2[MX][MX];
int col[MX];

void dfs(int p, int pre) {
    sz[p]=1; dp[p][1]=inf;
    for (array<int, 2> x : lnk[p]) if (x[0]!=pre) {
        dfs(x[0], p);
        for (int i=0; i<=sz[p]+sz[x[0]]; i++) dp2[p][i]=inf;

        for (int i=0; i<=sz[p]; i++) for (int j=0; j<=sz[x[0]]; j++) {
            dp2[p][i+j]=min(dp2[p][i+j], min(dp[p][i]+dp[x[0]][j]+x[1], dp[p][i]+dp[x[0]][sz[x[0]]-j]));
            if (dp2[p][i+j]==dp[p][i]+dp[x[0]][j]+x[1]) cut2[p][i+j]=cut[p][i], cut2[p][i+j].push_back({j, 0});
            if (dp2[p][i+j]==dp[p][i]+dp[x[0]][sz[x[0]]-j]) cut2[p][i+j]=cut[p][i], cut2[p][i+j].push_back({sz[x[0]]-j, 1});
        }
        swap(dp2[p], dp[p]); swap(cut2[p], cut[p]); sz[p]+=sz[x[0]];
    }
    dp[p][sz[p]]=inf;
}

void dfs2(int p, int pre, int s) {
    int id=0;
    for (array<int, 2> x : lnk[p]) if (x[0]!=pre) {
        if (cut[p][s][id][1]==0) col[x[0]]=col[p], dfs2(x[0], p, cut[p][s][id][0]);
        else col[x[0]]=col[p]^1, dfs2(x[0], p, cut[p][s][id][0]);
        id++;
    }
}

signed main() {
    fastio;

    cin >> n >> k;
    for (int i=1; i<n; i++) {
        int a, b, c; cin >> a >> b >> c;
        lnk[a].push_back({b, c});
        lnk[b].push_back({a, c});
    }

    dfs(1, 0);
    cout << min(dp[1][k], dp[1][n-k]) << "\n";
    if (dp[1][k]<=dp[1][n-k]) dfs2(1, 0, k); else dfs2(1, 0, n-k);

    int cnt=0;
    for (int i=1; i<=n; i++) cnt+=1-col[i];
    for (int i=1; i<=n; i++) if(col[i]^(cnt==k)) cout << i << " ";

    return 0;
}
