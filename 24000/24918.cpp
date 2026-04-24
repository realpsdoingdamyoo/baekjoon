#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;

int N;
vector<array<int, 2>> lnk[202020];
int T[202020], C[202020], R[202020], A[202020];
int UL[202020], UR[202020], ANS[202020];

int D[202020], cmp[404040];
vector<array<int, 2>> et;

void DFS(int p, int pre) {
    et.push_back({p, 1});
    for (array<int, 2> i : lnk[p]) if (i[0]!=pre)
        D[i[0]]=D[p]+i[1], DFS(i[0], p);
    et.push_back({p, -1});
}

const int X=20;
int seg[1<<X+1];
void update(int s, int e, int x) {
    s+=1<<X; e+=1<<X;
    while (s<=e) {
        if (s&1) seg[s]+=x; ++s>>=1;
        if (~e&1) seg[e]+=x; --e>>=1;
    }
}
int val(int p) {
    p+=1<<X; int r=0;
    while (p) r+=seg[p], p>>=1;
    return r;
}

bool O[202020];
void DNC(vector<array<int, 2>> vec, int S, int E) {
    if (S==E) {for (array<int, 2> i : vec) ANS[i[0]]=S; return;}
    int M=S+E>>1;

    for (array<int, 2> i : vec) {
        int p=i[0];
        if (i[1]==1) {
            O[p]=(T[p]<=M || val(UL[p])>=C[p]);
            if (!O[p]) C[p]-=val(UL[p]);
        }
        if (O[p]) update(UL[p], UR[p], A[p]*i[1]);
    }

    vector<array<int, 2>> Lv, Rv;
    for (array<int, 2> i : vec) (O[i[0]]?Lv:Rv).push_back(i);
    DNC(Lv, S, M); DNC(Rv, M+1, E);
}

signed main(){
    fastio;

    cin >> N;
    for (int i=1; i<N; i++) {
        int a, b, c; cin >> a >> b >> c;
        lnk[a].push_back({b, c}); lnk[b].push_back({a, c});
    }
    for (int i=1, a; i<=N; i++) cin >> a, T[a]=i;
    for (int i=1; i<=N; i++) cin >> C[i] >> R[i] >> A[i];

    DFS(1, 0);

    for (int i=1; i<=N; i++) cmp[i*2-1]=D[i], cmp[i*2]=D[i]+R[i];
    sort(cmp+1, cmp+N*2+1);

    for (int i=1; i<=N; i++) {
        UL[i]=lower_bound(cmp+1, cmp+2*N+1, D[i])-cmp;
        UR[i]=lower_bound(cmp+1, cmp+2*N+1, D[i]+R[i])-cmp;
    }

    DNC(et, 1, N);

    for (int i=1; i<=N; i++) cout << ANS[i] << " ";

    return 0;
}
