#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, inf=1e18;

string S;
int N, M, H[6060], pv[6060], nx[6060], DP[3030][6060];

void add(int& x, int y){x=(x+y)%mod;}

signed main() {
    fastio;

    cin >> S >> N; M=S.length();
    for (int i=1; i<=M; i++) H[i]=H[i-1]+(S[i-1]=='(')*2-1;
    for (int i=M+1; i<=N+M+1; i++) H[i]=H[i-1]-1;

    for (int i=0; i<=N+M; i++) {
        pv[i]=nx[i]=N+M+10;
        for (int j=i-1; j>=0; j--) if (H[j]>=H[i]+1) {pv[i]=j; break;}
        for (int j=i+1; j<=N+M; j++) if (H[j]<=H[i]-2) break; else nx[i]=j;
    }

    for (int i=0; i<=N+M; i++) if (H[i+1]<0) {DP[0][i]=1; break;}

    for (int i=0; i<N; i++) for (int j=0; j<=N+M; j++)
        add(DP[i+1][nx[j]], DP[i][j]), add(DP[i+1][pv[j]], DP[i][j]);

    cout << DP[N][M]%mod;

    return 0;
}
