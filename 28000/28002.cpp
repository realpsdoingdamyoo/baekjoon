#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e17;

int N, M, Q, X[202020], R, mp, mn[202020], A[202020];
vector<array<int, 3>> vec, mst;

int g[202020];
int Find(int x){return g[x]==x?x:g[x]=Find(g[x]);}

int cost(int i) {
    return mst[i][0]-max(mn[Find(mst[i][1])], mn[Find(mst[i][2])])-X[mp];
}

signed main() {
    fastio;

    cin >> N >> M >> Q;
    for (int i=1; i<=N; i++) g[i]=i, cin >> X[i];
    for (int i=1; i<=M; i++) {
        int a, b; cin >> a >> b;
        vec.push_back({X[a]+X[b], a, b});
    }

    sort(vec.begin(), vec.end());
    for (array<int, 3> i : vec) if (Find(i[1])!=Find(i[2])) g[Find(i[1])]=Find(i[2]), mst.push_back(i);
    mp=min_element(X+1, X+N+1)-X;
    A[N-1]=X[mp]*(N-2)+*max_element(X+1, X+N+1);

    for (int i=1; i<=N; i++) g[i]=i, mn[i]=X[i];
    priority_queue<array<int, 2>, vector<array<int, 2>>, greater<array<int, 2>>> pq;
    for (int i=0; i<N-1; i++) pq.push({cost(i), i});

    int id=N-2;
    while (pq.size()) {
        int c=pq.top()[0], p=pq.top()[1]; pq.pop();
        if (cost(p)!=c) {pq.push({cost(p), p}); continue;}
        int u=mst[p][1], v=mst[p][2];
        mn[Find(v)]=min(mn[Find(u)], mn[Find(v)]); g[Find(u)]=Find(v);
        A[id]=A[id+1]+c; id--;
    }

    for (int i=0; i<=Q; i++) cout << A[min(i, N-1)] << "\n";

    return 0;
}
