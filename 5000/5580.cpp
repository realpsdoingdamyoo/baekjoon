#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll n, s, m, dp[50][3001]={};
    cin >> n >> m >> s;
    dp[0][0] = 1;
    for (int k=1; k<=m; k++)
    for (int i=n*n; i; i--)
    for (int j=k; j<=s; j++)
        dp[i][j]=(dp[i][j]+dp[i-1][j-k])%100000;
    cout << dp[n*n][s];
    return 0;
}
