#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
const int mod=1e9+7, inf=2e18;

int N, K, A[101010], X[101010], pv;
vector<int> lnk[101010];

void dfs(int p, int dep) {
    X[p]=dep*K+pv--;
    for (int i : lnk[p]) dfs(i, dep-1);
}

signed main() {
    fastio;

    cin >> N; K=2*N; pv=N;
    for (int i=1; i<=N; i++) cin >> A[i]; A[N+1]=N+1;
    for (int i=N; i>=1; i--) lnk[A[i]+1].push_back(i);
    dfs(N+1, N+1);

    cout << K << "\n";
    for (int i=1; i<=N; i++) cout << X[i] << "\n";

    return 0;
}
