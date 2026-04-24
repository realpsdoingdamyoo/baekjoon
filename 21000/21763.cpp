#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e9;

signed main() {
    fastio;

    int N, K; cin >> N >> K;
    if (K>N*N-N-(N==2)) {cout << "NO"; return 0;} cout << "YES\n";
    for (int i=1; i<=N; i++, cout << "\n") for (int j=1; j<=N; j++) {
        if (!K || (i!=1 && i!=N && i==j) || ((i==1 || i==N) && i+j==N+1)) cout << ".";
        else K--, cout << "#";
    }

    return 0;
}
