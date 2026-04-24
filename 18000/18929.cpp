#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
const int mod=1e9+7, inf=2e18;

int N, A[1010101];
char X[1010101];
void dfs(int p) {
    for (int i : {p^1, A[p]}) if (!X[i]) X[i]='X'+'Y'-X[p], dfs(i);
}

signed main() {
    fastio;

    cin >> N;
    for (int i=1, x, y; i<=N; i++) cin >> x >> y, A[--x]=--y, A[y]=x;
    for (int i=0; i<N*2; i++) if (!X[i]) X[i]='X', dfs(i);
    cout << X;

    return 0;
}
