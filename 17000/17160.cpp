#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e17;

int N;
int F[105];

const int X=2520;
bool S[X][100][100];
int FIL[X][100];
double PR[X], PS=1;

signed main() {
    fastio;

    for (int i=1; i<=100; i++) F[i]=i;
    for (int i=0; i<X; i++) PR[i]=1;
    F[2]=F[4]=8; F[3]=9;

    cin >> N;
    for (int T=1; T<=N; T++) {
        int L, R, G; cin >> L >> R >> G; G+=R; L%=G;

        int P=F[G/__gcd(G, X)];
        double ret=0;
        for (int j=0; j<P*X; j++) {
            if ((j+L)%G<R && !S[j%X][P][j/X]) {
                S[j%X][P][j/X]=true;
                PR[j%X]/=(P-FIL[j%X][P]);
                FIL[j%X][P]++;
                ret+=PR[j%X]*P;
                PR[j%X]*=(P-FIL[j%X][P]);
            }
        }
        printf("%.10Lf\n", ret/(P*X)); PS-=ret/(P*X);
    }
    if (PS<1e-9) PS=0;
    printf("%.10Lf\n", PS);


    return 0;
}
