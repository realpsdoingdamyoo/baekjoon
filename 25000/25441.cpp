#include "circuit.h"
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+2022, MOD=998244353, inf=4e18;

int N, M, A;
vector<int> lnk[202020];
int dm[202020], v[202020];

const int X=18;
array<int, 3> seg[1<<X+1];

void init(signed _N, signed _M, vector<signed> P, vector<signed> A) {
    N=_N; M=_M;
    for (int i=1; i<N+M; i++) lnk[P[i]].push_back(i);
    fill(dm, dm+202020, 1);
    for (int i=N+M-1; i>=1; i--) {
        dm[i]=dm[i]*(i<N?lnk[i].size():1)%mod;
        dm[P[i]]=dm[P[i]]*dm[i]%mod;
    }
    dm[0]=dm[0]*lnk[0].size()%mod;

    v[0]=1;
    for (int i=0; i<N; i++) {
        vector<int> L(lnk[i].size()), R(lnk[i].size());
        L[0]=1;
        for (int j=1; j<L.size(); j++) L[j]=L[j-1]*dm[lnk[i][j-1]]%mod;
        R[R.size()-1]=1;
        for (int j=R.size()-2; j>=0; j--) R[j]=R[j+1]*dm[lnk[i][j+1]]%mod;

        for (int j=0; j<lnk[i].size(); j++) {
            v[lnk[i][j]]=v[i];
            v[lnk[i][j]]=v[lnk[i][j]]*L[j]%mod;
            v[lnk[i][j]]=v[lnk[i][j]]*R[j]%mod;
        }
    }

    for (int i=N; i<N+M; i++) {
        if (A[i-N]) seg[i+(1<<X)]={v[i], v[i], 0};
        else seg[i+(1<<X)]={v[i], 0, 1};
    }
    for (int i=(1<<X)-1; i>=1; i--) {
        seg[i][0]=seg[i<<1][0]+seg[i<<1|1][0];
        seg[i][1]=seg[i<<1][1]+seg[i<<1|1][1];
    }
}

void prop(int p) {
    if (!seg[p][2]) return;
    seg[p][2]=0; seg[p][1]=seg[p][0]-seg[p][1];
    seg[p<<1][1]=seg[p<<1][0]-seg[p<<1][1]; seg[p<<1][2]^=1;
    seg[p<<1|1][1]=seg[p<<1|1][0]-seg[p<<1|1][1]; seg[p<<1|1][2]^=1;
}

void segup(int p) {
    seg[p][1]=seg[p<<1][1]+seg[p<<1|1][1];
    if (seg[p][2]) seg[p][1]=seg[p][0]-seg[p][1];
}

signed count_ways(signed s, signed e) {
    int S=s+=1<<X, E=e+=1<<X;
    for (int i=X; i>=1; i--) prop(S>>i), prop(E>>i);
    while (s<=e) {
        if (s&1) seg[s][1]=seg[s][0]-seg[s][1], seg[s][2]^=1; ++s>>=1;
        if (~e&1) seg[e][1]=seg[e][0]-seg[e][1], seg[e][2]^=1; --e>>=1;
    }
    for (int i=1; i<=X; i++) segup(S>>i), segup(E>>i);

    return seg[1][1]%mod;
}
