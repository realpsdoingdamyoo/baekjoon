#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;

int N;
int X[80], Y[80];
int D[80];
int S, M;

signed main() {
    fastio;

    cin >> N;
    cin >> X[N] >> Y[N];
    for (int i=1; i<N; i++) cin >> D[i];
    D[N]=abs(X[N])+abs(Y[N]);

    S=0; M=0;
    for (int i=1; i<=N; i++) S+=D[i], M=max(M, D[i]);
    if (M*2>S || S%2==1) {cout << "NO"; return 0;}

    for (int i=1; i<=N-2; i++) {
        S=0; M=0;

        for (int j=i+1; j<N; j++) S+=D[j], M=max(M, D[j]);
        int DN=max(2*M-S, abs(D[i]-D[N]));
        if (i==N-2) DN=D[N-1];

        int DX=X[N]-X[i], DY=Y[N]-Y[i];
        int K=(D[i]+DN-D[N])/2;

        if (abs(DX)>=D[i]-K) {
            if (DX>0) X[i+1]=X[i]+(D[i]-K), Y[i+1]=Y[i];
            else X[i+1]=X[i]-(D[i]-K), Y[i+1]=Y[i];

            if (DY<0) Y[i+1]+=K; else Y[i+1]-=K;
        }
        else {
            if (DY<0) X[i+1]=X[N], Y[i+1]=Y[N]+(DN-K);
            else X[i+1]=X[N], Y[i+1]=Y[N]-(DN-K);

            if (DX>0) X[i+1]+=K; else X[i+1]-=K;
        }
        D[N]=DN;
    }

    cout << "YES\n";
    for (int i=1; i<=N; i++) cout << X[i] << " " << Y[i] << "\n";

    return 0;
}
