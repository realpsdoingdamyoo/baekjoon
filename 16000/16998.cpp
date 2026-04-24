#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;

int gcd(int a, int b){return b?gcd(b, a%b):a;}

int solve(int n, int p, int q){
    int d=gcd(p, q); p/=d; q/=d;
    int ret=n*(n+1)/2*(p/q);
    p%=q;

    if(p==0) return ret;

    ret+=n*(n*p/q)+n/q;
    return ret-solve(n*p/q, q, p);
}
signed main(){
    fastio;

    int t; cin >> t;
    while(t--){
        int p, q, n; cin >> p >> q >> n;
        cout << n*(n+1)/2*p-q*solve(n, p, q) << "\n";
    }

    return 0;
}
