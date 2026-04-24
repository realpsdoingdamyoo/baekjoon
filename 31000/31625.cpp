#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;

int N, M, L, Q;
int CN[505050];
int V[1010], C[1010];
int DP[2][2][1010][1010];
int T[1010][1010];

signed main(){
    fastio;

    cin >> N >> L; M=N;
    for (int i=1; i<=N; i++) {
        int a; cin >> a;
        CN[a]++;
    }
    cin >> Q;

    N=0;
    for (int i=0; i<=L; i++) if (CN[i]) {
        V[++N]=i; C[N]=CN[i];

        if (N>1005) {
            while (Q--) cout << "No\n";
            return 0;
        }
    }

    for (int i=1; i<=N; i++) for (int j=1; j<=N; j++) DP[0][0][i][j]=DP[0][1][i][j]=inf;
    for (int i=1; i<=N; i++) for (int j=1; j<=N; j++) DP[1][0][i][j]=DP[1][1][i][j]=inf;
    DP[0][0][1][N]=DP[1][1][1][N]=0; DP[0][1][1][N]=DP[1][0][1][N]=V[N]-V[1]; T[1][N]=1;

    for (int i=1; i<=N; i++) for (int j=N; j>=i; j--) {
        if (i>1) {
            T[i][j]=T[i-1][j]+C[i-1];
            DP[0][0][i][j]=min(DP[0][0][i][j], DP[0][0][i-1][j]+T[i][j]*abs(V[i]-V[i-1]));
            DP[0][1][i][j]=min(DP[0][1][i][j], DP[0][0][i-1][j]+T[i][j]*abs(V[j]-V[i-1]));
            DP[1][0][i][j]=min(DP[1][0][i][j], DP[1][0][i-1][j]+T[i][j]*abs(V[i]-V[i-1]));
            DP[1][1][i][j]=min(DP[1][1][i][j], DP[1][0][i-1][j]+T[i][j]*abs(V[j]-V[i-1]));
        }
        if (j<N) {
            T[i][j]=T[i][j+1]+C[j+1];
            DP[0][0][i][j]=min(DP[0][0][i][j], DP[0][1][i][j+1]+T[i][j]*abs(V[i]-V[j+1]));
            DP[0][1][i][j]=min(DP[0][1][i][j], DP[0][1][i][j+1]+T[i][j]*abs(V[j]-V[j+1]));
            DP[1][0][i][j]=min(DP[1][0][i][j], DP[1][1][i][j+1]+T[i][j]*abs(V[i]-V[j+1]));
            DP[1][1][i][j]=min(DP[1][1][i][j], DP[1][1][i][j+1]+T[i][j]*abs(V[j]-V[j+1]));
        }
        DP[0][0][i][j]=min(DP[0][0][i][j], DP[0][1][i][j]+(V[j]-V[i])*T[i][j]);
        DP[0][1][i][j]=min(DP[0][1][i][j], DP[0][0][i][j]+(V[j]-V[i])*T[i][j]);
        DP[1][0][i][j]=min(DP[1][0][i][j], DP[1][1][i][j]+(V[j]-V[i])*T[i][j]);
        DP[1][1][i][j]=min(DP[1][1][i][j], DP[1][0][i][j]+(V[j]-V[i])*T[i][j]);
    }


    for (int i=1; i<=Q; i++) {
        int x, y, t, R=inf; cin >> x >> y >> t;
        int X=upper_bound(V+1, V+N+1, y)-V-1;
        for (int p=max(1LL, X); p<=min(X+1, N); p++) {
            R=min(R, abs(V[1]-x)+DP[0][0][p][p]+(M+1)*abs(V[p]-y));
            R=min(R, abs(V[N]-x)+DP[1][0][p][p]+(M+1)*abs(V[p]-y));
        }
        R+=M;
        cout << (R<=t?"Yes\n":"No\n");
    }

    return 0;
}
