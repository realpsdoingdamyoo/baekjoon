#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e4+7, MOD=998244353, inf=2e18;

int cal(int n){
    int ret=0;
    for(int i=1, j; i<=n; i=j+1){
        j=n/(n/i);
        int p=((i^1)&1)-(j&1);
        ret+=p*(n/i);
    }
    return ret;
}

signed main(){
    fastio;

    int s, t; cin >> s >> t;
    cout << cal(t)-cal(s-1);

    return 0;
}
