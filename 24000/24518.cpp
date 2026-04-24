#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=4e18;

signed main(){
    fastio;

    int n, m, ans=0; cin >> n >> m;
    for(int i=1, j; i<=n; i=j+1){
        j=n/(n/i);
        if(i/m==j/m){
            int s=i%m, e=j%m, ret=0;
            ret+=(s+e)*(e-s+1)/2;
            ret%=mod;
            ret=ret*(n/i)%mod;
            ans+=ret;
        }
        else{
            int ret=0;
            ret+=(i%m+m-1)*(m-i%m)/2;
            ret+=(j%m)*(j%m+1)/2;
            ret%=mod;
            ret+=(j/m-i/m-1)*(m*(m-1)/2%mod);
            ret%=mod;
            ret=ret*(n/i)%mod;
            ans+=ret;
        }
    }
    cout << ans%mod;

    return 0;
}
