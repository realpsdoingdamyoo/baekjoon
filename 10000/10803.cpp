#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int dp[1003][4003];

int main() {
    int a, b; cin >> a >> b;

    for(int i=1; i<=100; i++){
        for(int j=1; j<=400; j++){
            dp[i][j]=i*j;
            if(i==j) dp[i][j]=1;
            for(int k=1; k<j; k++){
                dp[i][j]=min(dp[i][j], dp[i][j-k]+dp[i][k]);
            }
            for(int k=1; k<i; k++){
                dp[i][j]=min(dp[i][j], dp[i-k][j]+dp[k][j]);
            }
        }
    }
    if(a>b) swap(a, b);
    
    if(a*3<b) cout << (b/a-2)+dp[a][b%a+2*a];
    else cout << dp[a][b];
}
