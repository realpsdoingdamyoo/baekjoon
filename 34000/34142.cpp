#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e15;

int n, m, k, p, q, a;
int S1[2020][2020], S2[2020][2020], V[2020][2020], R[2020][2020];

signed main() {
    fastio;

    cin >> n >> m >> k >> p >> q;
    for (int i=1; i<=k; i++) {
        int r, c, d; cin >> r >> c >> d;
        V[r][c+1]++; V[r+d][c+d+1]--;
        S1[r-d][c-d]++; S1[r+1][c+1]+=2; S1[r+d+2][c+d+2]++;
        S2[r-d][c+d+1]--; S2[r+1][c]-=2; S2[r+d+2][c-d-1]--;
    }

    for (int i=1; i<=n; i++) for (int j=1; j<=m; j++) V[i][j]+=-V[i-1][j-1];
    for (int i=1; i<=n; i++) for (int j=1; j<=m; j++) S1[i][j]+=-S1[i-1][j-1], S2[i][j]+=-S2[i-1][j+1], R[i][j]=S1[i][j]+S2[i][j];
    for (int i=1; i<=n; i++) for (int j=1; j<=m; j++) R[i][j]+=R[i][j-1];
    for (int i=1; i<=n; i++) for (int j=1; j<=m; j++) R[i][j]+=R[i-1][j];
    for (int i=1; i<=n; i++) for (int j=1; j<=m; j++) R[i][j]+=V[i][j];

    for (int i=1; i<=n; i++) for (int j=1; j<=m; j++) a+=i*p^j*q^R[i][j];
    cout << a;

    return 0;
}
