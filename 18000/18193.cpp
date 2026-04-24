#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
const int mod=1e9+7, MOD=998244353, inf=2e17;

int N, M, K, pv;
vector<array<int, 2>> lnk[1010101];
int ld[1010101], rd[1010101], D[1010101], V[1010101];

int build(int s, int e, int x) {
    if (s==e) return s;
    int m=s+e>>1, p=++pv;
    ld[p]=build(s, m, x); rd[p]=build(m+1, e, x);
    if (x==0) lnk[ld[p]].push_back({p, 0}), lnk[rd[p]].push_back({p, 0});
    else lnk[p].push_back({ld[p], 0}), lnk[p].push_back({rd[p], 0});
    return p;
}

void gete(int p, int s, int e, int l, int r, int x, int n, int c) {
    if (r<s || e<l) return;
    if (l<=s && e<=r) {
        if (x==0) lnk[p].push_back({n, c});
        else lnk[n].push_back({p, 0});
    }
    else {
        int m=s+e>>1;
        gete(ld[p], s, m, l, r, x, n, c);
        gete(rd[p], m+1, e, l, r, x, n, c);
    }
}

signed main() {
    fastio;

    cin >> N >> M >> K; pv=N;
    int X1=build(1, N, 0), X2=build(1, N, 1);
    for (int i=1; i<=M; i++) {
        int a, b, c, d, e, p=++pv; cin >> e >> a >> b >> c >> d;
        gete(X1, 1, N, a, b, 0, p, e);
        gete(X2, 1, N, c, d, 1, p, e);
    }

    fill(D+1, D+pv+1, inf); D[K]=0;
    priority_queue<array<int, 2>, vector<array<int, 2>>, greater<array<int, 2>>> pq;
    pq.push({0, K});

    while (pq.size()) {
        int p=pq.top()[1], d=pq.top()[0]; pq.pop();
        if (V[p]++) continue;
        for (array<int, 2> i : lnk[p]) if (D[i[0]]>d+i[1]) {
            D[i[0]]=min(D[i[0]], d+i[1]);
            pq.push({D[i[0]], i[0]});
        }
    }

    for (int i=1; i<=N; i++) cout << (D[i]==inf?-1:D[i]) << " ";

    return 0;
}
