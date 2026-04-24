#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;

int N, P;
string A[11], B[11];

signed main(){
    fastio;

    cin >> N;
    for (int i=1; i<=N; i++) cin >> A[i];
    for (int i=1; i<=N; i++) cin >> B[i];
    sort(B+1, B+N+1);

    do {
        int R=0;
        for (int i=1; i<=N; i++) {
            for (int j=0; j<4; j++) R+=(A[i][j]!=B[i][j]);
        }
        P=max(P, R);
    }while (next_permutation(B+1, B+N+1));
    cout << P;


    return 0;
}
