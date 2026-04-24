#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
const int mod=1e9+7, MOD=998244353, inf=2e18;

int n;
string s;

signed main() {
    fastio;

    cin >> s; n=s.length(); s=" "+s;
    int p=1, ans=0;
    while (1) {
        int LH=0, RH=0, P=1;
        for (int i=p; i<=n/2+1; i++) {
            if (i>=n-i+1) {
                cout << max(ans, n-p*2+2);
                return 0;
            }
            LH=(LH+s[i]*P)%MOD; P=P*1557%MOD;
            RH=(RH*1557+s[n-i+1])%MOD;
            if (LH==RH) {
                ans=max(ans, i-p+1);
                p=i+1;
                break;
            }
        }
    }

    return 0;
}
