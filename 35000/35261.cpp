#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, inf=1e18;

signed main() {
    fastio;

    int g=0, a;
    string s; cin >> a >> s;
    for (int i=0; i<(int)s.length()-4; i++) {
        int c=0;
        if (s[i]=='e') c++;
        if (s[i+1]=='a') c++;
        if (s[i+2]=='g') c++;
        if (s[i+3]=='l') c++;
        if (s[i+4]=='e') c++;
        g=max(g, c);
    }
    cout << 5-g;

    return 0;
}
