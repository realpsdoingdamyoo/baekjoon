#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef stack<int> si;
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

int dp[100005][3];

int main(){
    int n; cin >> n;
    vi v(n);
    for(int i=0; i<n; i++) cin >> v[i];
    dp[0][0]=dp[0][1]=1;
    int mx=1;
    for(int i=1; i<n; i++){
        if(v[i]!=v[i-1]){
            dp[i][0]=dp[i-1][0]+1;
            dp[i][1]=dp[i-1][1]+1;
            dp[i][2]=dp[i-1][2]+1;
        }
        else{
            dp[i][0]=1;
            dp[i][1]=dp[i-1][0]+1;
            dp[i][2]=dp[i-1][1]+1;
        }
        mx=max(max(mx, dp[i][0]), max(dp[i][1], dp[i][2]));
    }
    cout << mx << endl;
    return 0;
}
