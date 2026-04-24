#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;

int N, R;
int V[202020][3];

signed main() {
    fastio;

    cin >> N;
    for (int i=1; i<=N*2; i++) {
        int X, Y; cin >> X >> Y;
        if (X<=1) R+=1-X, X=1;
        if (X>N) R+=X-N, X=N;
        if (Y<=1) R+=1-Y, Y=1; else R+=Y-2, Y=2;
        V[X][Y]++;
    }

    int A=0, B=0;
    for (int i=1; i<=N; i++) {
        R+=abs(A)+abs(B);
        A+=V[i][1]-1; B+=V[i][2]-1;
        if (A<0 && B>0) {
            int X=min(-A, B);
            A+=X; B-=X; R+=X;
        }
        if (A>0 && B<0) {
            int X=min(A, -B);
            A-=X; B+=X; R+=X;
        }
    }
    cout << R;

    return 0;
}
