#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
const int mod=1e9+7, MOD=998244353, inf=2e18;

int K;
int F[303030];

int pw(int y) {
    if (y<0) return 0;
    int r=1, x=2;
    while (y) {
        if (y&1) r=r*x%MOD;
        y>>=1; x=x*x%MOD;
    } return r;
}

signed main() {
    fastio;

    cin >> K; K--;

    for (int i=1; i<=K; i++) F[i]=(int)log2(i)+1;

    int ans=0;
    for (int x=0; x<K; x++) {
        if (F[x]!=F[x+1]) {
            ans+=pw(x*2-F[x])*(pw(K-x-1)-1)%MOD;
        }
        else {
            ans+=pw(x*2-F[x])*(pw(K-x-1)-1)%MOD;
            ans+=pw(x*2-F[x])*(pw(K-x)-2)%MOD;
            ans+=pw(x-F[x])*2%MOD;
        }
        ans%=MOD;
    }
    cout << ans;


    return 0;
}
