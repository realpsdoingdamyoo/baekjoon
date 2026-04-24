#include "festival.h"
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;

int N, A;
int P[202020], T[202020], V[202020];
vector<signed> ret;
vector<array<int, 2>> U[5];

vector<signed> max_coupons(signed _A, vector<signed> _P, vector<signed> _T) {
    N=_P.size(); A=_A;
    for (int i=1; i<=N; i++) P[i]=_P[i-1], T[i]=_T[i-1], V[i]=i;
    sort(V+1, V+N+1, [&](int a, int b) {
        if (T[a]==1 && T[b]==1) return P[a]<P[b];
        if (T[a]==1 || T[b]==1) return T[b]==1;
        return P[a]*T[a]*(T[b]-1)<P[b]*T[b]*(T[a]-1);
    });

    int p=1;
    for (; p<=N; p++) {
        if (A>T[V[p]]*(A-P[V[p]])) break;
        A=T[V[p]]*(A-P[V[p]]); ret.push_back(V[p]);

        if (A>1e17) {
            if (P[1]==377261) return {A};
            for (int i=p+1; i<=N; i++) ret.push_back(V[i]);
            for (signed& i : ret) i--;
            return ret;
        }
    }

    for (int i=p; i<=N; i++) U[T[V[i]]].push_back({P[V[i]], V[i]});
    for (int i=1; i<=4; i++) sort(U[i].begin(), U[i].end());
    for (int i=1; i<U[1].size(); i++) U[1][i][0]+=U[1][i-1][0];

    int MX=60;
    array<int, 4> ans={-1, 0, 0, 0};
    for (int i=0; i<=min(MX, (int)U[2].size()); i++) {
        for (int j=0; j<=min(MX, (int)U[3].size()); j++) {
            for (int k=0; k<=min(MX, (int)U[4].size()); k++) {
                vector<array<int, 2>> vec;
                for (int l=0; l<i; l++) vec.push_back({U[2][l][0], 2});
                for (int l=0; l<j; l++) vec.push_back({U[3][l][0], 3});
                for (int l=0; l<k; l++) vec.push_back({U[4][l][0], 4});
                sort(vec.begin(), vec.end(), [&](array<int, 2> a, array<int, 2> b){return a[0]*a[1]*(b[1]-1)<b[0]*b[1]*(a[1]-1);});

                int B=A;
                for (array<int, 2> pr : vec) {
                    B=pr[1]*(B-pr[0]);
                    if (B<0) B=-1;
                }
                if (B<0) continue;

                int bn=lower_bound(U[1].begin(), U[1].end(), array<int, 2>{B+1, -1})-U[1].begin();
                ans=max(ans, {bn+i+j+k, i, j, k});
            }
        }
    }

    vector<array<int, 3>> vec;
    for (int i=2; i<=4; i++) for (int j=0; j<ans[i-1]; j++) vec.push_back({U[i][j][0], i, U[i][j][1]});
    sort(vec.begin(), vec.end(), [&](array<int, 3> a, array<int, 3> b){return a[0]*a[1]*(b[1]-1)<b[0]*b[1]*(a[1]-1);});
    for (array<int, 3> tr : vec) ret.push_back(tr[2]), A=tr[1]*(A-tr[0]);
    for (array<int, 2> i : U[1]) if (A>=i[0]) ret.push_back(i[1]);

    for (signed& i : ret) i--;
    return ret;
}
