#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=1e18;

signed main(){
    fastio;

    int T, N, M, A, B, C, D; cin >> T;
    while (T--) {
        cin >> N >> M >> A >> B >> C >> D;
        if (N>M) swap(N, M), swap(A, B), swap(C, D);
        if (B>D) swap(A, C), swap(B, D);

        int pmx=N*M;
        if (N%2==1 && M%2==1) pmx-=(A+B)%2+(C+D)%2;
        else pmx-=(A+B+C+D+1)%2;

        if (N==1) cout << D-B+1 << "\n";
        else if (N==2) {
            if (A!=C && B==D) cout << max(B*2, (M-B+1)*2) << "\n";
            else if (A!=C && B+1==D) cout << max(B*2+1, (M-B)*2+1) << "\n";
            else cout << pmx << "\n";
        }
        else if (N==3) {
            if (M%2==0 && B!=D && (A+B)%2==1 && (C+D)%2==0 && !((A==1 || A==3) && D==B+1))
                cout << pmx-2 << "\n";
            else cout << pmx << "\n";
        }
        else cout << pmx << "\n";
    }

    return 0;
}
