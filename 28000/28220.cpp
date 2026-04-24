#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;

int n, L, R;
int c[101], s[101];
int dp[101][101][10101];

signed main(){
    fastio;

    cin >> n >> L >> R;
    for(int i=1; i<=n; i++){
        cin >> c[i];
        c[i]-=L;
        s[i]=s[i-1]+c[i];
    }

    for(int i=0; i<=n; i++) for(int j=0; j<=R-L; j++)
        for(int k=0; k<=10000; k++) dp[i][j][k]=inf;

    if(s[n]<0 || s[n]>(R-L)*n){
        cout << "-1\n";
        return 0;
    }

    dp[0][0][0]=0;

    for(int i=1; i<=n; i++) for(int j=0; j<=R-L; j++) for(int k=0; k<=s[n]; k++){
        if(j>0) dp[i-1][j][k]=min(dp[i-1][j][k], dp[i-1][j-1][k]);
        if(k+j>10000) continue;
        if(i==n && k+j!=s[n]) continue;
        dp[i][j][k+j]=min(dp[i][j][k+j], dp[i-1][j][k]+abs(s[i]-k-j));
    }

    int ans=inf;
    for(int i=0; i<=R-L; i++) ans=min(ans, dp[n][i][s[n]]);
    cout << ans;

    return 0;
}
