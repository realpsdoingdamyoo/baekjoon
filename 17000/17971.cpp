#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
const int mod=1e9+7, MOD=998244353, inf=2e17;

int N, U[55];
vector<array<int, 3>> vec, ans;

signed main() {
    fastio;

    cin >> N;
    iota(U+1, U+N+1, 1);
    for (int i=1; i<N; i++) {
        int x, j=1;
        while (1) {
            cin >> x; if (!x) break;
            vec.push_back({x, i, j++});
        }
    }

    sort(vec.begin(), vec.end());
    for (int i=vec.size()-1; i>=0; i--) swap(U[vec[i][1]], U[vec[i][1]+1]);

    for (array<int, 3> i : vec) if (U[i[1]]>U[i[1]+1]) swap(U[i[1]], U[i[1]+1]), ans.push_back(i);

    cout << ans.size() << "\n";
    for (array<int, 3> i : ans) cout << i[1] << " " << i[2] << "\n";

    return 0;
}
