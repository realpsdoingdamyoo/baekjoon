#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e9;

bool isp(string s) {
    string p;
    for (char i : s) {
        p+=i;
        if (p.length()>=2) {
            string x=p.substr(p.length()-2, 2);
            if (x=="{}" || x=="()" || x=="[]") p.pop_back(), p.pop_back();
        }
    }
    return p=="";
}

signed main() {
    fastio;

    int T; cin >> T;
    while (T--) {
        string s; cin >> s;
        if (isp(s)) {
            cout << "YES 0\n";
            continue;
        }
        for (int i=0; i<s.length(); i++) {
            for (char j : "{}()[]") {
                swap(j, s[i]);
                if (isp(s)) {
                    cout << "YES 1\n" << i+1 << " " << s[i] << "\n";
                    goto nx;
                }
                swap(j, s[i]);
            }
        }
        cout << "NO\n";
        nx: T+=0;
    }

    return 0;
}
