#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;

signed main(){
    fastio;

    int T; cin >> T;
    while (T--) {
        int N, M, K=0; cin >> N >> M;
        for (int i=1; i<=M; i++) {
            int a, b; cin >> a >> b;
            K+=(a<b);
        }
        if (K>M-K) for (int i=1; i<=N; i++) cout << i << " ";
        else for (int i=N; i>=1; i--) cout << i << " ";
        cout << "\n";
    }

    return 0;
}
