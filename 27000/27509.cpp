#include <bits/stdc++.h>
#define int long long
using namespace std;
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
const int mod=1e9+7, MOD=998244353, inf=1e18;

int N, K, pr[101010], nx[101010];
vector<int> v={0, 1};
vector<array<int, 2>> lnk[101010];
struct dp {int X[2][2][2]={};} DP[101010];

dp mrg(dp a, dp b, int x, int y) {
    dp r; for (int i : v) for (int j : v) for (int k : v) r.X[i][j][k]=inf;
    for (int i : v) for (int j : v) for (int k : v) for (int l : v) for (int m : v) for (int n : v)
        r.X[i][j][k]=min(r.X[i][j][k], a.X[i][j][l]+b.X[m][n][k]+(i==m?x:0)+(l==n?y:0));
    return r;
}

void dfs(int p, int x) {
    if (lnk[p].size()==0) {
        for (int i : v) for (int j : v) for (int k : v) DP[p].X[i][j][k]=inf;
        DP[p].X[0][0][0]=DP[p].X[1][1][1]=0;
    }
    int cx=0;
    for (array<int, 2> n : lnk[p]) if (n[0]!=x) {
        dfs(n[0], p);
        if (n==lnk[p][0])
            for (int i : v) for (int j : v) for (int k : v)
                DP[p].X[i][j][k]=min(DP[n[0]].X[i][j][k]+n[1], DP[n[0]].X[i^1][j][k]);
        else DP[p]=mrg(DP[p], DP[n[0]], n[1], cx);
        cx=nx[n[0]];
    }
}

int place_police(vector<signed> P, vector<int> C, vector<int> W) {
    N=P.size()+1; vector<int> V;
    for (int i=0; i<=N-2; i++) lnk[P[i]].push_back({i+1, C[i]}), pr[i+1]=P[i];
    for (int i=0; i<N; i++) if (!lnk[i].size()) V.push_back(i), K++;
    for (int i=0, p=V[0]; i<K; i++, p=V[i]) {while (p && p==lnk[pr[p]].back()[0]) p=pr[p]; nx[p]=W[i];}

    dfs(0, -1);
    int ans=inf;
    for (int i : v) for (int j : v) for (int k : v)
        ans=min(ans, DP[0].X[i][j][k]+(j==k?nx[0]:0));
    return ans;
}
