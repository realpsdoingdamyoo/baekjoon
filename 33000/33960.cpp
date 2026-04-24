#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;

int n;
int v[505], sm[505];
array<int, 2> dp[505][505];

signed main(){
    fastio;

    cin >> n;
    for(int i=1; i<=n; i++){cin >> v[i]; sm[i]=sm[i-1]+v[i];}

    for(int i=n; i>=1; i--) for(int j=i; j<=n; j++){
        dp[i][j]={0, sm[j]-sm[i-1]};
        for(int k=i; k<j; k++){
            dp[i][j]=max(dp[i][j], {dp[i][k][0]+dp[k+1][j][0], dp[i][k][1]+dp[k+1][j][1]});
        }
        if(dp[i][j][1]==10) dp[i][j][0]++, dp[i][j][1]=0;
    }

    cout << dp[1][n][0];



    return 0;
}
