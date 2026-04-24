#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
const int mod=1e9+7, inf=2e18;

int N, DP[1010101][3]={};
char A[1010101], B[1010101];

signed main() {
    fastio;

    cin >> N;
    for (int i=1; i<=N; i++) cin >> A[i];
    for (int i=1; i<=N; i++) cin >> B[i];
    for (int i=0; i<=N; i++) for (int j : {0, 1, 2}) DP[i][j]=(i||j)*inf;

    for (int i=1; i<=N; i++) {
        for (int j=0; j<3; j++) {
            for (int k=0; k<3; k++) {
                int a=((j==0 && A[i]=='0') || j==1)==(B[i]=='0');
                int b=((k==0 && A[i-1]=='0') || k==1)==(B[i-1]=='0') || i==1;
                DP[i][j]=min(DP[i][j], DP[i-1][k]+(j!=0 && j!=k)+(a==0 && b==1));
            }
        }
    }
    cout << min({DP[N][0], DP[N][1], DP[N][2]});

    return 0;
}
