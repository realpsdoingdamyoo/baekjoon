#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

vector<ll> v;
vector<array<ll, 4>> dp;

int main() {
    int n; cin >> n;
    v.resize(n); dp.resize(n+1);
    for(int i=0; i<n; i++) cin >> v[i];
    if(n==1){cout << v[0]; return 0;}
    if(n==2){cout << (v[0]^v[1]); return 0;}
    dp[1][1]=v[0];
    dp[2][2]=v[0]^v[1];
    dp[3][1]=(v[0]^v[1])+v[2];
    dp[3][2]=v[0]+(v[1]^v[2]);
    dp[3][3]=v[0]^v[1]^v[2];

    for(int i=4; i<=n; i++){
        dp[i][1]=v[i-1]+max(max(dp[i-1][2], dp[i-1][3]), dp[i-1][4]);
        dp[i][2]=(v[i-2]^v[i-1])+max(max(dp[i-2][1], dp[i-2][3]), dp[i-2][4]);
        dp[i][3]=(v[i-3]^v[i-2]^v[i-1])+max(max(dp[i-3][2], dp[i-3][1]), dp[i-3][4]);
        dp[i][4]=(v[i-4]^v[i-3]^v[i-2]^v[i-1])+max(max(dp[i-4][2], dp[i-4][3]), dp[i-4][1]);
    }
    cout << max(max(dp[n][1], dp[n][2]), max(dp[n][3], dp[n][4]));
    return 0;
}
