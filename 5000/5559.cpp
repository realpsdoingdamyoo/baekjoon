#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
const int mod=1e5, inf=2e18;

int N, M, R=1, MX;
int G[1<<20], K, DP[420][11000][2];
bool vis[420][11000][2];
char C[22][22];

int solve(int p, int b, int x) {
    assert(G[b]);
    if (p==N*M) return 1;
    if (vis[p][G[b]][x]) return DP[p][G[b]][x];
    vis[p][G[b]][x]=1;

    int i=p/M, j=p%M, &r=DP[p][G[b]][x];
    if (C[i][j]=='J' || C[i][j]=='?') r+=solve(p+1, b<<1&MX, 1);
    if (C[i][j]=='O' || C[i][j]=='?') r+=solve(p+1, (b|x)<<1&MX, 0);
    if (C[i][j]=='I' || C[i][j]=='?') if ((b>>M-1&1)==0 || j==M-1) r+=solve(p+1, b<<1&MX, 0);
    return r%=mod;
}

signed main() {
    fastio;

    cin >> N >> M; MX=(1<<M)-1;
    for (int i=0; i<N; i++) for (int j=0; j<M; j++) {
        cin >> C[i][j];
        if (C[i][j]=='?') R=R*3%mod;
    }
    for (int i=0; i<(1<<M); i+=2) if (!(i&i<<1)) G[i]=++K;

    cout << (R-solve(0, 0, 0)+mod)%mod;

    return 0;
}
