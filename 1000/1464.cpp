#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;

signed main(){
    fastio;

    string s, p; cin >> s;
    for (char i : s) {
        if (p+i<i+p) p+=i; else p=i+p;
    }
    cout << p;

    return 0;
}
