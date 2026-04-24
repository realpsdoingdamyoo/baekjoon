#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;

signed main() {
    fastio;

    int n; cin >> n;
    vector<int> u, v;
    for (int i=0; i<1; i++) {
        string s; cin >> s;
        for (char a : s) {
            if (u.size() && u.back()<inf && '0'<=a && a<='9') {
                u.back()=u.back()*10+(a-'0');
            }
            else if ('0'<=a && a<='9') u.push_back(a-'0');
            else u.push_back(a+inf);
        }
    }

    for (int i=0; i<n; i++) {
        v.clear();
        string s; cin >> s;
        for (char a : s) {
            if (v.size() && v.back()<inf && '0'<=a && a<='9') {
                v.back()=v.back()*10+(a-'0');
            }
            else if ('0'<=a && a<='9') v.push_back(a-'0');
            else v.push_back(a+inf);
        }
        cout << (u<=v?"+\n":"-\n");
    }

    return 0;
}
