#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;

namespace icing {
    mt19937_64 rd(1557);
    int N, M;
    vector<int> lnk[252525];

    int D[252525], X[252525], P[252525], CH[252525];
    vector<int> vec; int AX;

    void init() {
        N=0; M=0;
        for (int i=0; i<252525; i++) {
            D[i]=X[i]=P[i]=CH[i]=0;
            lnk[i].clear();
        }
        vec.clear(); AX=0;
    }

    void DFS(int p, int x) {
        CH[p]=1;
        for (int i : lnk[p]) if (i!=x) {
            if (CH[i]==0) {
                D[i]=!D[p]; P[i]=p; DFS(i, p);
                X[p]^=X[i];
            }
            if (CH[i]==1) {
                int t=rd();
                X[p]^=t; X[i]^=t; vec.push_back(t);
                if (D[i]==D[p]) AX^=t;
            }
        }
        CH[p]=2;
    }

    int count_ways(int _N, vector<int> U, vector<int> V) {
        init();
        N=_N; M=U.size();

        for (int i=0; i<M; i++) {
            lnk[U[i]].push_back(V[i]);
            lnk[V[i]].push_back(U[i]);
        }

        DFS(1, -1);
        for (int i=2; i<=N; i++) vec.push_back(X[i]);

        if (AX==0) return 0;
        for (int i : vec) if (i==AX) return 1;
        return 2;
    }
}

int N, M, C=1;
array<int, 3> edg[505050];
vector<array<int, 2>> lnk[252525];

int g[252525];
int Find(int x){return g[x]==x?x:g[x]=Find(g[x]);}
int Union(int a, int b) {
    a=Find(a); b=Find(b);
    g[a]=b; return a!=b;
}

signed main() {
    fastio;

    cin >> N >> M;
    for (int i=1; i<=M; i++) {
        int a, b, c; cin >> a >> b >> c;
        edg[i]={a, b, c};
        lnk[a].push_back({b, c});
        lnk[b].push_back({a, c});
    }
    sort(edg+1, edg+M+1, [&](array<int, 3> a, array<int, 3> b){return a[2]<b[2];});

    for (int i=1; i<=N; i++) g[i]=i;
    int enp=M;
    while (C<N) C+=Union(edg[enp][0], edg[enp][1]), enp--; enp++;

    int s=1, e=enp;
    while (s<=e) {
        int m=s+e>>1;
        vector<int> U, V;
        for (int i=m; i<=M; i++) U.push_back(edg[i][0]), V.push_back(edg[i][1]);
        if (icing::count_ways(N, U, V)<=1) e=m-1; else s=m+1;
    }
    if (s==enp+1) cout << -1;
    else cout << e;

    return 0;
}
