#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e17;

set<array<int, 2>> st;

signed main() {
    fastio;

    int N, T, K, R=0; cin >> N >> T >> K;
    for (int i=1; i<=N; i++) {
        int a, b, c; cin >> a >> b;
        if (a==1) {cin >> c; st.insert({c, -b});}
        else {
            for (int j=0; j<K && st.size();) {
                array<int, 2> p=*prev(st.end()); st.erase(prev(st.end()));
                if (-p[1]<b-T) continue;
                R+=p[0]; j++;
            }
        }
    }
    cout << R << "\n";

    return 0;
}
