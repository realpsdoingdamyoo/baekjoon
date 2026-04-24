#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
const int mod=1e9+7, inf=2e18;

int N, X[50], Y[50], DP[50][50][50][50], IC[50][50][50];
vector<int> IN[50][50][50];

inline int ccw(int a, int b, int c) {
    return X[a]*Y[b]+X[b]*Y[c]+X[c]*Y[a]-Y[a]*X[b]-Y[b]*X[c]-Y[c]*X[a]>0;
}
inline int In(int a, int b, int c, int x) {
    return ccw(a, b, x)==ccw(b, c, x) && ccw(b, c, x)==ccw(c, a, x);
}

int solve(int a, int b, int c, int n) {
    if (a>b) swap(a, b); if (b>c) swap(b, c); if (a>b) swap(a, b);
    if (IC[a][b][c]+3<n) return 0;
    if (n<=3) return 6;
    if (DP[a][b][c][n]) return DP[a][b][c][n];

    int S=0;
    S=solve(a, b, c, n-1)*(IC[a][b][c]+3-n+1)%mod;
    for (int i : IN[a][b][c]) {
        S+=solve(c, a, i, n-1)%mod;
        S+=solve(a, b, i, n-1)%mod;
        S+=solve(b, c, i, n-1)%mod;
    }
    return DP[a][b][c][n]=S%mod;
}

signed main() {
    fastio;

    cin >> N;
    for (int i=1; i<=N; i++) cin >> X[i] >> Y[i];

    int I=-1, J=-1, K=-1;
    for (int i=1; i<=N; i++) for (int j=i+1; j<=N; j++) for (int k=j+1; k<=N; k++) {
        for (int l=1; l<=N; l++) if (l!=i && l!=j && l!=k && In(i, j, k, l))
            IN[i][j][k].push_back(l), IC[i][j][k]++;
        if (IN[i][j][k].size()==N-3) I=i, J=j, K=k;
    }
    if (I==-1) {cout << "0"; return 0;}

    cout << solve(I, J, K, N);


    return 0;
}
