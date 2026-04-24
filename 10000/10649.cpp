#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e15;

int N, tt, R=-1;
int T[22], W[22], P[22];
int A[1<<20], S[1<<20], H[1<<20];

signed main(){
    fastio;

    cin >> N >> tt;
    for (int i=0; i<N; i++) cin >> T[i] >> W[i] >> P[i];
    A[0]=inf; S[0]=H[0]=0; fill(A+1, A+(1<<N), -1);
    for (int i=1; i<1<<N; i++) for (int j=0; j<N; j++) if (i&(1<<j)) {
        int k=i^(1<<j);
        A[i]=max(min(A[k], P[j]-S[k]), A[i]); S[i]=S[k]+W[j]; H[i]=H[k]+T[j];
        if (H[i]>=tt) R=max(R, A[i]);
    }
    if (R>=0) cout << R << "\n";
    else cout << "Mark is too tall\n";

    return 0;
}
