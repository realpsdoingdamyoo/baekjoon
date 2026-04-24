#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;

int N, Q, D;
int X[202020], A[202020];
array<int, 2> L[202020], R[202020];

signed main(){
    fastio;

    cin >> N >> Q;
    for (int i=1; i<=N; i++) cin >> X[i];
    for (int i=1; i<=Q; i++) {
        int x; cin >> x; D+=x;
        int j=i-(x==0);
        L[i]=min(L[i-1], {D, j});
        R[i]=max(R[i-1], {D, j});
    }

    A[1]+=abs(L[Q][0]); A[N]+=abs(R[Q][0]);
    for (int i=2; i<=N; i++) {
        int S=1, E=Q, W=X[i]-X[i-1];
        while (S<=E) {
            int M=S+E>>1;
            if (R[M][0]-L[M][0]>=W) E=M-1;
            else S=M+1;
        }
        if (R[Q][0]-L[Q][0]<W) {
            A[i-1]+=abs(R[Q][0]);
            A[i]+=abs(L[Q][0]);
        }
        else if (L[S][1]<R[S][1]) {
            int x=min(abs(L[S][0]), W);
            A[i-1]+=W-x; A[i]+=x;
        }
        else {
            int x=min(abs(R[S][0]), W);
            A[i-1]+=x; A[i]+=W-x;
        }
    }

    for (int i=1; i<=N; i++) cout << A[i] << "\n";

    return 0;
}
