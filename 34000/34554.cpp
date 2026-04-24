#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;

void solve() {
    int N; cin >> N;
    for (int i=2; i<=N; i++) {
        if ((N+1)%i==0) {cout << "0\n"; return;}
    }
    cout << "1\n1 " << N+1 << "\n";
}

signed main(){
    fastio;

    int T; cin >> T;
    while (T--) solve();

    return 0;
}
