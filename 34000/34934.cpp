#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e17;

signed main() {
    fastio;

    int N; cin >> N;
    pair<int, string> ans={0, ""};
    for (int i=1; i<=N; i++) {
        string s; int n; cin >> s >> n;
        ans=max(ans, {n, s});
    }
    cout << ans.second;

    return 0;
}
