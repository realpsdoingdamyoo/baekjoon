#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e9;

int N, A[10101];

signed main() {
    fastio;

    cin >> N;
    iota(A+1, A+N*2+2, -N);
    swap(A[1], A[N]); swap(A[N+2], A[N*2+1]);
    int ans=0;
    for (int i=1; i<=N*2; i++) ans+=abs(A[i]+A[i+1]);
    cout << ans/2.0 << "\n";
    for (int i=1; i<=N*2+1; i++) cout << A[i] << " ";

    return 0;
}
