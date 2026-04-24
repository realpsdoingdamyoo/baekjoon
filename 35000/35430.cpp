#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, inf=1e18;
 
signed main() {
    fastio;
 
    int N, M, X; cin >> N >> M >> X;
    for (int i=1; i<=N; i++) if (X%i==0 && X/i<=M) {
        cout << "1\n0 0 " << i << " " << X/i << "\n";
        return 0;
    }
 
    cout << "2\n";
    cout << "0 0 " << N << " " << X/N << "\n";
    cout << "0 " << X/N << " " << X%N << " " << X/N+1 << "\n";
 
    return 0;
}
