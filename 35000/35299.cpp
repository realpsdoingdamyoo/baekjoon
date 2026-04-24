#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, inf=1e18;

int N, K;
string S;

int L[1004];
int DP[100][100][100];

signed main() {
    fastio;

    cin >> S >> K; N=S.length()/2; S=" "+S;
    int cnt=0;
    for (char i : S) if (i==')') cnt++;

    for (int i=2; i<10; i++) L[i]=1;
    for (int i=10; i<100; i++) L[i]=2;

    for (int j=0; j<=N; j++) for (int k=0; k<=K; k++) DP[0][j][k]=(j==0 && k==0?0:inf);
    for (int i=1; i<=N; i++) for (int j=0; j<=N; j++) for (int k=0; k<=K; k++) {
        int C[2]={}; DP[i][j][k]=inf;
        for (int p=i; p>=1; p--) {
            C[S[p*2]==')']++;
            int len=i-p+1;
            int g=2+L[len];
            if (C[1]<=k) DP[i][j][k]=min(DP[i][j][k], DP[p-1][j][k-C[1]]+g);
            if (len<=j && C[0]<=k) DP[i][j][k]=min(DP[i][j][k], DP[p-1][j-len][k-C[0]]+g);
        }
    }

    int ans=inf;
    for (int i=0; i<=K; i++) ans=min(ans, DP[N][cnt][i]);
    cout << ans;

    return 0;
}
