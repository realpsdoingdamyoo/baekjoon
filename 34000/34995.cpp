#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e9;

signed main() {
    fastio;

    int N; cin >> N;
    string a, b; cin >> a >> b;
    for (char& i : a) if (i=='?') i='9';
    if (a.length()<b.length() || (a.length()==b.length() && a<b)) cout << -1;
    else cout << a;

    return 0;
}
