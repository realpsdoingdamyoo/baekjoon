#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, inf=1e18;

signed main() {
    fastio;

    int N, K, p=0;
    string s; cin >> N >> K >> s;
    for (char i : s) {
        if (i=='0') p++;
        else p=0;
        if (p==K) {cout << 0; return 0;}
    }
    cout << 1;

    return 0;
}
