#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=4e18;

signed main(){
    fastio;

    int a, b; cin >> a >> b; a--;
    int ret=0;
    for(int i=1, j; i<=b; i=j+1){
        j=b/(b/i);
        ret+=(j-i+1)*(i+j)/2*(b/i);
    }
    for(int i=1, j; i<=a; i=j+1){
        j=a/(a/i);
        ret-=(j-i+1)*(i+j)/2*(a/i);
    }
    cout << ret;

    return 0;
}
