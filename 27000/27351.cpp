#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
const int mod=1e9+7, inf=2e18;

int cp=0;
vector<vector<int>> ans;

bool avl(int N, int M, int K) {
    if (N==0 || M==0) return !K;
    if (N%2 || M%2) return false;
    if (K<max(N, M)/2 || K>N*M/4) return false;
    if (K==N*M/4-1) return false;
    if (N==M && K==N/2+1) return false;
    return true;
}

void sol(int x, int y, int N, int M, int K) {
    if (N==0 || M==0) return;
    if (avl(N-2, M-2, K-1)) {
        cp++;
        for (int i=x; i<x+N; i++) ans[i][y]=ans[i][y+M-1]=cp;
        for (int i=y; i<y+M; i++) ans[x][i]=ans[x+N-1][i]=cp;
        sol(x+1, y+1, N-2, M-2, K-1);
        return;
    }
    if (N<M) {
        sol(x, y+M-2, N, 2, N/2);
        sol(x, y, N, M-2, K-N/2);
    }
    else {
        sol(x+N-2, y, 2, M, M/2);
        sol(x, y, N-2, M, K-M/2);
    }
}

void solve() {
    int N, M, K; cp=0;
    cin >> N >> M >> K;
    if (!avl(N, M, K)) {cout << "NO\n"; return;}
    cout << "YES\n";
    ans=vector<vector<int>>(N, vector<int>(M, 0));
    sol(0, 0, N, M, K);
    for (vector<int>& i : ans) {
        for (int j : i) cout << j << " ";
        cout << "\n";
    }
}

signed main() {
    fastio;

    int T; cin >> T;
    while (T--) solve();

    return 0;
}
