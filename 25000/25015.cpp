#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=4e18;
mt19937_64 rd(6974);

int N, M;
int U[252525], V[252525];
vector<int> lnk[252525];

int D[252525], X[252525], P[252525], CH[252525];
vector<int> vec; int AX;
map<int, int> cnt;

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

int count_ways(signed _N, vector<signed> _U, vector<signed> _V) {
    N=_N; M=_U.size();
    for (int i=1; i<=M; i++) U[i]=_U[i-1], V[i]=_V[i-1];
    
    for (int i=1; i<=M; i++) {
        lnk[U[i]].push_back(V[i]);
        lnk[V[i]].push_back(U[i]);
    }

    DFS(1, -1);
    for (int i=2; i<=N; i++) vec.push_back(X[i]);

    if (AX==0) return 1;

    int cnt=0;
    for (int i : vec) cnt+=(i==AX);
    if (cnt) return cnt;

    map<int, int> mp;
    for (int i : vec) cnt+=mp[i^AX], mp[i]++;
    return cnt;
}
