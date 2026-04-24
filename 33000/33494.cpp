#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
const int mod=1e9+7, inf=2e18;
const int MX=2020202, X=2000, Y=1010;

int N, K, Q, L[Y], R[Y], C[MX];

int A[MX], U[MX], LZ[Y], S[Y], P[Y], pv[MX];

void update1(int p, int s, int e) {
    LZ[p]++; S[p]+=e-s+1;
    while (U[P[p]]+LZ[p]>=K) {
        U[P[p]]-=K;
        if (pv[P[p]]<P[p]) S[p]-=K*(P[p]-pv[P[p]]);
        else S[p]-=K*(P[p]-pv[P[p]]+(e-s+1));
        P[p]=pv[P[p]];
    }
}
void update2(int p, int s, int e, int l, int r) {
    for (int i=s; i<=e; i++) A[i]=(A[i]+LZ[p])%K; LZ[p]=0;
    for (int i=l; i<=r; i++) A[i]=(A[i]+1)%K;
    S[p]=0; for (int i=s; i<=e; i++) U[i]=A[i], S[p]+=A[i];
    sort(U+s, U+e+1); P[p]=e;
    pv[s]=e; for (int i=s+1; i<=e; i++) pv[i]=(U[i]==U[i-1]?pv[i-1]:i-1);
}

signed main() {
    fastio;

    cin >> N >> K;
    for (int i=1; i<=N; i++) cin >> A[i], A[i]%=K;

    for (int i=1; i<=N; i++) C[i]=i/X;
    for (int i=1; i<=N; i++) R[C[i]]=i;
    for (int i=N; i>=1; i--) L[C[i]]=i;
    for (int i=0; i<Y; i++) update2(i, L[i], R[i], 0, -1);

    cin >> Q;
    while (Q--) {
        int q, s, e; cin >> q >> s >> e;

        if (q==1) {
            if (C[s]==C[e]) update2(C[s], L[C[s]], R[C[s]], s, e);
            else {
                update2(C[s], L[C[s]], R[C[s]], s, R[C[s]]);
                update2(C[e], L[C[e]], R[C[e]], L[C[e]], e);
                for (int i=C[s]+1; i<=C[e]-1; i++) update1(i, L[i], R[i]);
            }
        }
        else {
            int ans=0;
            if (C[s]==C[e]) for (int i=s; i<=e; i++) ans+=(A[i]+LZ[C[i]])%K;
            else {
                for (int i=s; i<=R[C[s]]; i++) ans+=(A[i]+LZ[C[i]])%K;
                for (int i=L[C[e]]; i<=e; i++) ans+=(A[i]+LZ[C[i]])%K;
                for (int i=C[s]+1; i<=C[e]-1; i++) ans+=S[i];
            }
            cout << ans << "\n";
        }
    }


    return 0;
}
