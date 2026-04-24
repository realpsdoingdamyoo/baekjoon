#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, inf=1e18;


signed main() {
    fastio;

    int T; cin >> T;
    while (T--) {
        int N, M; cin >> N >> M;
        vector<array<int, 2>> ans;
        if (N<=M) {
            for (int i=N; i>=1; i--) for (int j=1; j<i; j++) ans.push_back({i, j});
            for (int i=1; i<N; i++) for (int j=M; j>i; j--) ans.push_back({i, j});
            for (int i=N+1; i<M; i+=2) ans.push_back({N, i});
        }
        else {
            for (int i=M; i>=1; i--) for (int j=1; j<i; j++) ans.push_back({j, i});
            for (int i=1; i<M; i++) for (int j=N; j>i; j--) ans.push_back({j, i});
            for (int i=M+1; i<N; i+=2) ans.push_back({i, M});
        }

        cout << ans.size() << "\n";
        for (array<int, 2> i : ans) cout << i[0] << " " << i[1] << "\n";
    }


    return 0;
}
