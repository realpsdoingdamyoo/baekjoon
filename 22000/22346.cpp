#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+8, MOD=998244353, inf=4e18;

int OC[65];
int PE[65][10101];

signed main() {
    fastio;

    int N, Q, A=1; cin >> N >> Q;
    while (A<N) A=A<<1|1;

    for (int i=0; i<62; i++) {
        int X=N>>i;
        for (int j=0; j<62; j++) if (X>=(1LL<<j)) {
            OC[i]+=(~X)&(1LL<<j);
        }
    }

    for (int i=0; i<62; i++) {
        for (int j=0; j<=10000; j++) {
            int L=j;
            for (int k=1; k<62; k++) {
                if (N>>(i+k-1)&1) {if (L>=OC[i+k]) L-=OC[i+k], PE[i][j]+=(A>>(i+k))+1;}
                else {
                    if (L>OC[i+k]) L-=OC[i+k]+1, PE[i][j]+=(A>>(i+k))+1;
                    else if (L==OC[i+k]) {PE[i][j]+=(A>>(i+k)); break;}
                }
            }
        }
    }

    for (int T=1; T<=Q; T++) {
        int L, R, K, F=0; cin >> L >> R >> K;
        for (int i=1; i<62; i++) {
            int X=(A>>i)+1;
            if (L<=X && X<=R) {
                if (N>>(i-1)&1) {
                    for (int j=0; j<=K; j++) {
                        F=max(F, min(X-L, PE[i][j])+1+min(R-X, PE[i][K-j]));
                    }
                }
                else {
                    for (int j=0; j<K; j++) {
                        F=max(F, min(X-L, PE[i][j])+1+min(R-X, PE[i][K-1-j]));
                    }
                }
                if (X-L>R-X) R=X-1;
                else L=1, R-=X;
                if (L>R) break;
            }
            else if (X<=L) {
                L=max(1LL, L-X);
                R-=X;
            }
        }
        cout << F << "\n";
    }

    return 0;
}
