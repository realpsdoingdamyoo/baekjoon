#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;

int TST(int x) {
    int r=0;
    while (x>1) r+=x&1, ++x>>=1;
    return r;
}

int RET(int x, int d) {
    if (d==0) return TST(x);
    return min(TST(x), TST(x^(1LL<<d-1)));
}

int solve(int a, int b) {

    for (int i=0; i<=60; i++) {
        if (a<=(1LL<<i) && (1LL<<i)<=b) return 0;
    }

    a+=1LL<<61, b+=1LL<<61; int e=0, ret=inf;
    while (a<=b) {
        if (a&1) ret=min(ret, RET(a-(1LL<<61-e)<<e, e));
        if (~b&1) ret=min(ret, RET(b-(1LL<<61-e)<<e, e));
        ++a>>=1; --b>>=1; e++;
    }
    return ret;
}

signed main(){
    fastio;

    int T; cin >> T;
    while (T--) {
        int a, b; cin >> a >> b;
        cout << solve(a, b) << "\n";
    }


    return 0;
}
