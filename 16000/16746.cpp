#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e8;

int n, m;
array<int, 3> v[10101];
int RV[10101];
vector<array<int, 2>> edg;
vector<int> lnk[10101], L[10101];
int C[10101], X[5];

int vis[10101];
void dfs(int p, int x, int y, int lmt) {
    vis[p]=1;
    if (C[p]==x || C[p]==y) C[p]^=x^y;
    for (int i : L[p]) if (i<lmt && X[C[p]]==X[C[i]] && !vis[i]) dfs(i, x, y, lmt);
}

signed main() {
    fastio;

    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        cin >> v[i][0] >> v[i][1];
        v[i][2]=i;
    }

    for (int i=1; i<=m; i++) {
        int a, b; cin >> a >> b;
        edg.push_back({a, b});
    }

    sort(v+1, v+n+1);
    for (int i=1; i<=n; i++) RV[v[i][2]]=i;

    for (array<int, 2>& i : edg) {
        i[0]=RV[i[0]], i[1]=RV[i[1]];
        lnk[max(i[0], i[1])].push_back(min(i[0], i[1]));
        L[i[0]].push_back(i[1]); L[i[1]].push_back(i[0]);
    }


    for (int i=1; i<=n; i++) {
        int col[5]={0, 1, 1, 1, 1};
        for (int j : lnk[i]) col[C[j]]=0;
        for (int j=1; j<=4; j++) if (col[j]) C[i]=j;
        if (C[i]) continue;

        for (int j=0; j<4; j++) if (v[i][0]==v[lnk[i][j]][0]) swap(lnk[i][0], lnk[i][j]);
        for (int j=1; j<4; j++) if (v[i][0]-v[i][1]==v[lnk[i][j]][0]-v[lnk[i][j]][1]) swap(lnk[i][1], lnk[i][j]);
        for (int j=2; j<4; j++) if (v[i][1]==v[lnk[i][j]][1]) swap(lnk[i][2], lnk[i][j]);

        X[C[lnk[i][0]]]=X[C[lnk[i][2]]]=1;
        X[C[lnk[i][1]]]=X[C[lnk[i][3]]]=2;

        for (int j=1; j<=i; j++) vis[j]=0;
        dfs(lnk[i][0], 0, 0, i);
        if (vis[lnk[i][2]]) {
            for (int j=1; j<=i; j++) vis[j]=0;
            C[i]=C[lnk[i][1]];
            dfs(lnk[i][1], C[lnk[i][1]], C[lnk[i][3]], i);
        }
        else {
            for (int j=1; j<=i; j++) vis[j]=0;
            C[i]=C[lnk[i][0]];
            dfs(lnk[i][0], C[lnk[i][0]], C[lnk[i][2]], i);
        }
    }

    for (int i=1; i<=n; i++) cout << C[RV[i]] << "\n";

    return 0;
}
