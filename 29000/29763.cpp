#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;

int n, m;
string s;

signed main(){
    fastio;

    cin >> n >> m >> s;
    if (n==1) {
        int r=0, p=1;
        while (s.size()) {
            r=(r+p*(s.back()-'0'))%mod;
            p=p*2%mod; s.pop_back();
        }
        cout << r;
        return 0;
    }

    int r=0; n%=mod;
    for (int i=0; i<m; i++) r=(r*2+1)%mod;
    cout << r*n%mod*500000004%mod;


    return 0;
}
