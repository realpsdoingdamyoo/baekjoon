#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=998244353, inf=4e18;

int N;
int A[303030], B[303030], C[303030], P[303030];

void solve() {
    cin >> N;
    for (int i=1; i<=N; i++) {
        cin >> A[i] >> B[i] >> C[i] >> P[i];
    }
    int a=0, b=0, c=0, p=0;
    for (int i=1; i<=N; i++) {
        if (a<A[i]) p+=A[i]-a, a=A[i];
        if (b<B[i]) p+=B[i]-b, b=B[i];
        if (c<C[i]) p+=C[i]-c, c=C[i];
        p++;
        if (p>P[i]) {cout << "NO\n"; return;}
    }
    cout << "YES\n";
}

signed main() {
    fastio;

    int T; cin >> T;
    while (T--) solve();

    return 0;
}
