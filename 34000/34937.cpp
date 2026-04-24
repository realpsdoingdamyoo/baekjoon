#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e17;

signed main() {
    fastio;

    int N, M; cin >> N >> M;
    int X=N*M*2-N-M;
    int R=1;
    for (int i=1; i<=X; i++) R=R*3%mod;
    cout << R;

    return 0;
}
