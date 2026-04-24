#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;

int N, M;
int V[110][110], CO[110][110], DP[110][110];

void solve() {
    cin >> N >> M;
    for (int i=1; i<=N; i++) for (int j=1; j<=M; j++) cin >> V[i][j];
    for (int i=1; i<=N; i++) {
        int CC[110];
        fill(CC+1, CC+M+1, inf);
        fill(CO[i]+1, CO[i]+N+1, 0);
        for (int j=i; j<=N; j++) for (int k=1; k<=M; k++) CO[i][j]+=CC[k]=min(CC[k], V[j][k]);
    }

    for (int i=N; i>=1; i--) {
        DP[i][i]=2*CO[i][i];
        for (int j=i+1; j<=N; j++) {
            DP[i][j]=inf;
            for (int k=i; k<j; k++) DP[i][j]=min(DP[i][j], DP[i][k]+DP[k+1][j]-2*CO[i][j]);
        }
    }
    cout << DP[1][N] << "\n";
}

signed main(){
    fastio;

    int T; cin >> T;
    for (int i=1; i<=T; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}
