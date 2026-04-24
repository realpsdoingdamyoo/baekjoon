#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
const int mod=1e9+7, inf=2e18;

int N, A[303030];
int K, P[303030];
vector<int> lnk[303030];
array<int, 2> go[303030], go2[303030];

void dfs(int p, int x) {
    for (int i : lnk[p]) if (i!=x) {
        dfs(i, p);
        go[p]=max({go[p], go[i], {A[i], -i}});
    }
    go[p][0]--;
}

void rrt(int p, int x) {
    array<int, 2> g[2]={go2[p], {A[p], -p}};
    if (g[0]<g[1]) swap(g[0], g[1]);

    for (int i : lnk[p]) if (i!=x) {
        array<int, 2> v=go[i]; v[0]--;
        v=max(v, {A[i]-1, -i});
        if (g[0]<v) swap(g[0], v);
        if (g[1]<v) swap(g[1], v);
    }

    for (int i : lnk[p]) if (i!=x) {
        go2[i]=g[g[0][1]==go[i][1] || g[0][1]==-i]; go2[i][0]--;
        rrt(i, p);
    }
}

signed main() {
    fastio;

    cin >> N >> K;
    for (int i=1; i<=N; i++) go[i]=go2[i]={-mod, -mod}, cin >> A[i];
    for (int i=1; i<N; i++) {
        int a, b; cin >> a >> b;
        lnk[a].push_back(b); lnk[b].push_back(a);
    }

    dfs(1, 0); rrt(1, 0);
    for (int i=1; i<=N; i++) go[i]=max(go[i], go2[i]);

    int p=1;
    for (int i=K-1; i>=0; i--) {
        p=-go[p][1];
        if (P[p]>0) i%=P[p]-i;
        P[p]=i;
    }
    cout << p;

    return 0;
}
