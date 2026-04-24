#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;

array<int, 4> mul(array<int, 4> a, array<int, 4> b) {
    return {(a[0]*b[0]+a[1]*b[2])%mod, (a[0]*b[1]+a[1]*b[3])%mod, (a[2]*b[0]+a[3]*b[2])%mod, (a[2]*b[1]+a[3]*b[3])%mod};
}

int fib(int p) {
    array<int, 4> x={1, 1, 1, 0}, r={1, 0, 0, 1};
    while (p) {
        if (p%2) r=mul(r, x);
        p>>=1; x=mul(x, x);
    }
    return r[0];
}

signed main(){
    fastio;

    int n; cin >> n;
    cout << fib(n+n%2-1);


    return 0;
}
