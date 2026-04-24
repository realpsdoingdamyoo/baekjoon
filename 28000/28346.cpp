#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+8, MOD=998244353, inf=4e18;


signed main() {
    fastio;

    int T; cin >> T;
    while (T--) {
        int N, R=0; cin >> N;
        vector<int> v(N);
        for (int& i : v) cin >> i;
        for (int i=0; i<N; i++) R+=v[i]^v[(i+1)%N];
        cout << R << "\n";
    }

    return 0;
}
