#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e9;

signed main() {
    fastio;

    int T; cin >> T;
    while (T--) {
        int N, c=0; cin >> N;
        for (int i=1, x; i<=N; i++) cin >> x, c+=(x==1);
        cout << ((N>=2&&c%2==1&&c!=N) ||(N==c&&N%2==0)?"Bob\n":"Alice\n");
    }

    return 0;
}
