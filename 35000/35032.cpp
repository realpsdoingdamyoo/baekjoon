#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e17;

int N;
array<int, 4> V[2020];
int A[2020];

signed main() {
    fastio;

    cin >> N;
    for (int i=1; i<=N; i++) cin >> V[i][0] >> V[i][1] >> V[i][2], V[i][3]=i;
    sort(V+1, V+N+1, [&](array<int, 4> a, array<int, 4> b){return a[2]>b[2];});

    for (int i=1; i<=N; i++) {
        int u=1;
        for (int j=1; j<i; j++) if (A[j]) {
            if (max(abs(V[i][0]-V[j][0]), abs(V[i][1]-V[j][1]))<V[i][2]+V[j][2]) u=0;
        }
        A[i]=u;
    }

    cout << accumulate(A+1, A+N+1, 0LL) << "\n";
    for (int i=1; i<=N; i++) if (A[i]) cout << V[i][3] << "\n";

    return 0;
}
