#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e17;

int A[101010];

signed main() {
    fastio;

    int N; cin >> N;

    for (int i=1; i<=N; i++) {
        int j=1;
        while (j<=N) j+=++A[j];
    }

    for (int i=1; i<=N; i++) cout << A[i] << " "; cout << "\n";

    return 0;
}
