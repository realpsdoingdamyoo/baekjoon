#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
const int mod=1e9+7, MOD=998244353, inf=2e18;

int n, k, z;
bool vis[1<<20];

void dfs(int p) {
    vis[p]=true;
    for (int i=0; i<k; i++) if ((p&(1<<i)) && !vis[p^(1<<i)]) dfs(p^(1<<i));
}

signed main() {
    fastio;

    cin >> n >> k;
    for (int i=1; i<=n; i++) {
        string s; cin >> s;
        if (z) reverse(s.begin(), s.end());
        int a=0;
        while (s.length()) a=a*2+s.back()-'0', s.pop_back();
        z=!vis[a];
        cout << (vis[a]?"WellKnown\n":"AdHoc\n");
        if (!vis[a]) dfs(a);
    }

    return 0;
}
