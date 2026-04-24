#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, inf=1e18;

int N, M=5000, ans, v;
int P[5050], DP[5050][5050], A[5050];

signed main() {
    fastio;

    for (int i=1; i<=M; i++) for (int j=2; j<=i; j++) if (i%j==0){P[i]=j; break;}
    for (int i=0; i<=M; i++) for (int j=0; j<=M; j++) {
        if (i==0 || j==0) DP[i][j]=max(i, j);
        else if (i==1 || j==1) DP[i][j]=1;
        else if (j%P[i]) DP[i][j]=DP[i/P[i]][j];
        else DP[i][j]=P[i]*DP[i/P[i]][j/P[i]];
    }

    cin >> N;
    for (int i=1, x; i<=N; i++) cin >> x, A[x]=1, v=max(v, x);

    for (int i=1; i<=M; i++) if (A[i]) {
        int g=0;
        for (int j=1; j<=M; j++) if (j%i && A[j]) g=DP[g][j];
        if (g==0 && N>1) g=v;
        ans=max(ans, i+g);
    }
    cout << ans;

    return 0;
}
