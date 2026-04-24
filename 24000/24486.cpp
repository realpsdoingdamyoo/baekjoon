#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e17;

int N, V[5050], O, E, C[5050], olp[5050], elp[5050], DP[5050][5050];

void solve() {
    cin >> N; O=E=0;
    for (int i=1; i<=N; i++) olp[i]=elp[i]=0;
    for (int i=1; i<=N; i++) cin >> V[i], C[i]=++(V[i]%2?O:E);
    for (int i=1; i<=N; i++) for (int j=i+1; j<=N; j++) if (V[i]%2!=V[j]%2 && abs(V[i]-V[j])>1)
        (V[j]%2?elp:olp)[C[j]]=max((V[j]%2?elp:olp)[C[j]], C[i]);

    for (int i=0; i<=E; i++) for (int j=0; j<=O; j++) {
        DP[i][j]=!(i||j);
        if (i && j>=olp[i]) DP[i][j]+=DP[i-1][j];
        if (j && i>=elp[j]) DP[i][j]+=DP[i][j-1];
        DP[i][j]%=mod;
    }

    cout << DP[E][O] << "\n";
}

signed main() {
    fastio;

    int T; cin >> T;
    while (T--) solve();

    return 0;
}
