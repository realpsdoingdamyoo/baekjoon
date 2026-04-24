#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=4e18;

int N, R;
vector<int> lnk[10101];
int C[10101][2], pv=1;

void dfs(int p, int pre) {
    int x=pv++;
    C[p][1]=C[pre][0];
    for (int i : lnk[p]) if (i!=pre) {
        C[i][0]=C[p][1]=x;
        dfs(i, p);
    }
}

signed main() {
    fastio;

    cin >> N;
    for (int i=1; i<N; i++) {
        int a, b; cin >> a >> b;
        lnk[a].push_back(b);
        lnk[b].push_back(a);
    }

    for (int i=1; i<=N; i++) if (lnk[i].size()==1) R=i;
    dfs(R, 0); C[R][0]=C[lnk[R][0]][1];

    for (int i=1; i<=N; i++) cout << C[i][0] << " " << C[i][1] << "\n";

    return 0;
}
