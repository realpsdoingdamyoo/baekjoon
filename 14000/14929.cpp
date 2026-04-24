#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;

signed main(){
    fastio;

    int N, A=0, B=0; cin >> N;
    while (N--) {
        int a; cin >> a;
        A+=a; B+=a*a;
    }
    cout << (A*A-B)/2;

    return 0;
}
