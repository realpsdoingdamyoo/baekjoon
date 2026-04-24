#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
const int mod=1e9+7, MOD=998244353, inf=2e17;

int N, M, Q;
vector<array<int, 2>> lnk[101010];
int D[101010];
vector<int> gf, r;

int vis[101010];
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
int ts2(int x, int y) {
    while (y>1) x>>=1, y>>=1;
    return x&1;
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
    for (int i=0; i<r.size(); i++) {
        for (int j=i+1; j<r.size(); j++) if (ts2(r[i], r[j])) r[i]^=r[j];
    }

    for (int i=1; i<=N; i++) {
        for (int j : r) if ((D[i]^j)<D[i]) D[i]^=j;
        D[i]^=D[i-1];
    }

    int A=0;
    for (int i : r) A^=i;

    while (Q--) {
        int a, b; cin >> a >> b;
        if ((b-a+1)%4==0) cout << (D[b]^D[a-1]) << "\n";
        if ((b-a+1)%4==1) cout << 0 << "\n";
        if ((b-a+1)%4==2) cout << (D[b]^D[a-1]^A) << "\n";
        if ((b-a+1)%4==3) cout << A << "\n";
    }


    return 0;
}
