#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=4e18;

const int X=1010101;
vector<int> dv[X];
int dp[X], ans;

signed main(){
    fastio;

    int n; cin >> n;
    dp[1]=1; for(int i=3; i<=n; i++) dp[i]=1;
    for(int i=1; i<=n; i++){
        dp[i+1]%=mod;
        for(int j=i; j<=n; j+=i) if(j>i+1) dp[j]+=dp[i+1];
        if(i>=2) for(int j=i+1; j<=n; j+=i) if(j>i+1) dp[j]+=dp[i+1];
        if(i>=3) for(int j=i+2; j<=n; j+=i) if(j>i+1) dp[j]+=dp[i+1];
    }

    for(int i=1; i<=n; i++) ans+=dp[i];

    cout << ans%mod*n%mod;


    return 0;
}
