#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
const int mod=1e9+7, MOD=998244353, inf=2e17;

int N, M, Q;
vector<array<int, 2>> lnk[10101];
int D[10101];
vector<int> gf, r;

int vis[10101];
void dfs(int p) {
    vis[p]=1;
    for (array<int, 2> i : lnk[p]) {
        if (vis[i[0]]) gf.push_back(D[p]^D[i[0]]^i[1]);
        else D[i[0]]=D[p]^i[1], dfs(i[0]);
    }
}

int ts(int x, int y) {
    while (x&&y) x>>=1, y>>=1;
    return x==y;
}

signed main() {
    fastio;

    cin >> N >> M >> Q;
    for (int i=1; i<=M; i++) {
        int a, b, c; cin >> a >> b >> c;
        lnk[a].push_back({b, c});
        lnk[b].push_back({a, c});
    }

    dfs(1);

    while (gf.size()) {
        sort(gf.begin(), gf.end());
        int x=gf.back(); r.push_back(x); gf.pop_back();
        for (int& i : gf) if (ts(i, x)) i^=x;
        for (int i=0; i<gf.size(); i++) if (!gf[i])
            swap(gf[i], gf.back()), gf.pop_back(), i--;
    }

    while (Q--) {
        int a, b, x; cin >> a >> b;
        x=D[a]^D[b];
        for (int i : r) if ((i^x)<x) x^=i;
        cout << x << "\n";
    }


    return 0;
}
