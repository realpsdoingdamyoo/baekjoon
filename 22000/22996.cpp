#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+8, MOD=998244353, inf=4e18;

int N, M, Q;
int P[303030], V[303030];
vector<int> lnk[303030];

void dfs(int p) {
    for (int i : lnk[p]) {
        dfs(i);
        cout << "1 " << i << " " << p << "\n";
        Q--;
    }
}

signed main() {
    fastio;

    cin >> N >> Q;
    cout << N << " " << Q << "\n";
    for (int i=1; i<=N; i++) cin >> P[i];
    cin >> M;
    for (int i=1; i<=M; i++) {
        int a; cin >> a;
        cout <<"2 " << a << "\n";
        Q--;
    }

    for (int i=1; i<=N; i++) {
        if (i!=P[i]) lnk[P[i]].push_back(i);
    }

    for (int i=1; i<=N; i++) if (i==P[i]) dfs(i);
    int X=1;
    for (int i=1; i<=N; i++) if (i==P[i]) X=i;
    while (Q--) cout << "1 " << X << " " << X << "\n";

    return 0;
}
