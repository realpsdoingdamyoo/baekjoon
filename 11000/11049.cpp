#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

int n, dp[504][504];

int main() {
    cin >> n; vector<int> v(n+1);
    for(int i=0; i<n; i++) cin >> v[i] >> v[i+1];
    for(int i=0; i<n; i++) dp[i][i+2]=v[i]*v[i+1]*v[i+2];
    for(int sz=3; sz<=n; sz++){
        for(int i=0; i+sz<=n; i++){
            dp[i][i+sz]=1000000000;
            for(int j=i+1; j<i+sz; j++){
                dp[i][i+sz]=min(dp[i][i+sz], dp[i][j]+v[i]*v[j]*v[i+sz]+dp[j][i+sz]);
            }
        }
    }
    cout << dp[0][n];
    fastio;
}
