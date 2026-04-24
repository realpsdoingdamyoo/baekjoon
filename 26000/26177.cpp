#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define vcin; for(int i=0; i<n; i++) cin >> v[i];

const double cir=acos(-1)/4;

int main(){
    //fastio;

    int n, m; cin >> n >> m;
    vector<string> s(n); for(int i=0; i<n; i++) cin >> s[i];
    vector<vector<double>> dp(2*n+1);
    for(int i=0; i<=2*n; i++){
        dp[i].resize(2*m+1);
        for(int j=0; j<=2*m; j++){
            if(i%2==0 && j%2==0){
                if(i||j){
                    dp[i][j]=10000000;
                    if(i) dp[i][j]=min(dp[i-1][j]+0.5, dp[i][j]);
                    if(j) dp[i][j]=min(dp[i][j-1]+0.5, dp[i][j]);
                }
            }
            if(i%2==0 && j%2==1){
                dp[i][j]=dp[i][j-1]+0.5;
                if(i && (s[i/2-1][(j-1)/2]=='O')) dp[i][j]=min(dp[i-1][j-1]+cir, dp[i][j]);
            }
            if(i%2==1 && j%2==0){
                dp[i][j]=dp[i-1][j]+0.5;
                if(j && (s[(i-1)/2][j/2-1]=='O')) dp[i][j]=min(dp[i-1][j-1]+cir, dp[i][j]);
            }
        }
    }
    printf("%.10lf", dp[2*n][2*m]*10);

    return 0;
}
