#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;

void solve() {
    int n; cin >> n;
    if (n==2) cout << "2 1\n1 2\n";
    else if (n==3) cout << "2 3 1\n1 2\n";
    else if (n==4) cout << "2 3 4 1\n1 1\n";
    else if (n%2==1) {
        for (int i=1; i<=n/2; i++) cout << i%(n/2)+1 << " ";
        for (int i=1; i<=n/2+1; i++) cout << n/2+i%(n/2+1)+1 << " ";
        cout << "\n";
        cout << 1 << " " << n/2+1 << "\n";
    }
    else {
        int A=1;
        for (int i=1; i<n; i++) if (A*(n-A)/__gcd(A, n-A)<i*(n-i)/__gcd(i, n-i)) A=i;
        if (A*(n-A)/__gcd(A, n-A)<(n/2)*(n/2-1)+1) {
            for (int i=1; i<=n/2-1; i++) cout << i%(n/2-1)+1 << " ";
            for (int i=1; i<=n/2; i++) cout << n/2+i%(n/2) << " ";
            cout << n-1 << "\n";
        }
        else {
            for (int i=1; i<=A; i++) cout << i%A+1 << " ";
            for (int i=1; i<=n-A; i++) cout << A+1+i%(n-A) << " ";
            cout << "\n";
        }
        cout << 1 << " " << n << "\n";
    }
}

signed main(){
    fastio;

    int T; cin >> T;
    while (T--) solve();

    return 0;
}
