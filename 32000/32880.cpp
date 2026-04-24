#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e17;

int N, C[505050], ans=-inf;
vector<int> lnk[505050];
int DP1[505050], DP2[505050], DP3[505050], DP4[505050];
void push(array<int, 2>& p, int x){for (int i : {0, 1}) if (p[i]<x) swap(p[i], x);}

void dfs(int p, int x) {
    DP1[p]=DP2[p]=C[p];
    for (int i : lnk[p]) if (i!=x) dfs(i, p), DP1[p]+=max(DP1[i], 0LL), DP2[p]=max(DP2[p], DP2[i]);
    DP2[p]=max(DP2[p], DP1[p]);
}
void dfs2(int p, int x) {
    int pu=C[p]+max(DP3[p], 0LL); array<int, 2> mx={-inf, -inf};
    for (int i : lnk[p]) if (i!=x) pu+=max(DP1[i], 0LL), push(mx, DP2[i]);
    for (int i : lnk[p]) if (i!=x) {
        DP3[i]=max(pu-max(DP1[i], 0LL), C[p]);
        DP4[i]=max({DP3[i], DP4[p], mx[mx[0]==DP2[i]]});
        dfs2(i, p);
    }
}
void dfs3(int p, int x) {
    array<int, 2> ret={DP4[p], -inf};
    for (int i : lnk[p]) if (i!=x) dfs3(i, p), push(ret, DP2[i]);
    ans=max(ans, ret[0]+ret[1]);
}

int findSum(signed n, vector<signed> c, vector<signed> U, vector<signed> V) {
    N=n; for (int i=0; i<N; i++) C[i]=c[i];
    for (int i=0; i<N-1; i++) lnk[U[i]].push_back(V[i]), lnk[V[i]].push_back(U[i]);
    dfs(0, -1); DP3[0]=DP4[0]=-inf; dfs2(0, -1); dfs3(0, -1);
    return ans;
}
