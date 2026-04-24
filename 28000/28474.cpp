#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;

signed main(){
    fastio;

    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int m=n, k=n, r=n, s=n;

        for (int i=2; i*i<=k; i++) if (k%i==0) {
            while (k%i==0) k/=i; m=m*(i-1)/i;
        }
        if (k>1) m=m*(k-1)/k;

        if (n%2==0) {
            n/=2; r/=2;
            for (int i=2; i*i<=n; i++) if (n%i==0) {
                while (n%i==0) n/=i; r=r*(i-1)/i;
            }
            if (n>1) r=r*(n-1)/n;
        }
        else r=0;

        cout << m+r-(s<=2) << "\n";
    }


    return 0;
}
