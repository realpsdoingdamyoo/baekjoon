#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e8;

signed main() {
    fastio;

    int n, c=0;
    string s, p;
    cin >> n >> p;
    for (int i=60; i>=0; i--) {
        if (n&(1LL<<i)) s+="1"; else if (s.length()) s+="0";
    }

    while (p.length()>s.length() || (p.length()==s.length() && p>s)) {
        string r=p;
        for (int i=1; i<r.length(); i++) if (r[i]=='1') {
            r.erase(r.begin()+i); break;
        }
        if (r==p) r.pop_back();
        p=r; c++;
    }
    cout << c;

    return 0;
}
