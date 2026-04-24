#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e17;

int N, M, R;

vector<int> lnk[1010];
int mt[1010], cs[1010];

bool dfs(int p) {
    for (int i : lnk[p]) {
        if (cs[i]++) continue;
        if (!mt[i] || dfs(mt[i])) {mt[i]=p; return true;}
    }
    return false;
}

signed main(){
    fastio;

    cin >> N >> M;
    for (int i=1; i<=M; i++) {
        int a, b; cin >> a >> b;
        lnk[a].push_back(b);
    }

    for (int i=1; i<=N; i++) {
        fill(cs+1, cs+N+1, 0);
        if (dfs(i)) R++;
    }
    cout << R;

    return 0;
}
