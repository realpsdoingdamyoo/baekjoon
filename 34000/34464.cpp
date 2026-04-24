#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, inf=4e18;

void solve() {
    int N, M, C=0; cin >> N >> M;
    vector<vector<int>> V(N+2, vector<int>(M+2, inf));
    vector<vector<int>> D(N+2, vector<int>(M+2, 0LL));
    priority_queue<array<int, 3>> pq;
    for (int i=1; i<=N; i++) for (int j=1; j<=M; j++) cin >> V[i][j], pq.push({-V[i][j], i, j});
    while (pq.size()) {
        int x=pq.top()[1], y=pq.top()[2]; pq.pop();
        for (array<int, 2> p : vector<array<int, 2>>{{x, y-1}, {x, y+1}, {x-1, y}, {x+1, y}}) {
            int i=p[0], j=p[1];
            if (V[i][j]<V[x][y]) D[x][y]=max(D[x][y], D[i][j]+1);
        }
        C+=V[x][y]-D[x][y];
    }

    cout << (C%2?"Yes":"No") << "\n";
}

signed main(){
    fastio;

    int T; cin >> T;
    while (T--) solve();

    return 0;
}
