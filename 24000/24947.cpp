#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
const int mod=1e9+7, inf=2e18;
const int MX=151515;

int N, A[MX], B[MX], C[MX];
array<int, 2> X[MX], Y[MX], Z[MX];

signed main() {
    fastio;

    cin >> N;
    for (int i=1; i<=N; i++) cin >> A[i] >> B[i] >> C[i], X[i]={A[i], i}, Y[i]={B[i], i}, Z[i]={C[i], i};
    sort(X+1, X+N+1); sort(Y+1, Y+N+1); sort(Z+1, Z+N+1);

    int a=N, b=N, c=N;
    for (int i=1; i<=3*N; i++) {
        while (a && (B[X[a][1]]>=Y[b][0] || C[X[a][1]]>=Z[c][0])) a--;
        while (b && (A[Y[b][1]]>=X[a][0] || C[Y[b][1]]>=Z[c][0])) b--;
        while (c && (A[Z[c][1]]>=X[a][0] || B[Z[c][1]]>=Y[b][0])) c--;
    }
    cout << (min({a, b, c})?X[a][0]+Y[b][0]+Z[c][0]:-1);

    return 0;
}
