#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll dp[200][21];

void getnum(int i){

    int k;

    cin >> k;

    if(i==0) {dp[0][k]=1; return;}

    for(int j=0; j<=20-k; j++) dp[i][j+k]+=dp[i-1][j];

    for(int j=k; j<=20; j++) dp[i][j-k]+=dp[i-1][j];

    for(int j=0; j<=20; j++) dp[i][j];

}

int main() {

    int n; cin >> n;

    for(int i=0; i<n-1; i++) getnum(i);

    int m; cin >> m;

    cout << dp[n-2][m];

    return 0;

}
