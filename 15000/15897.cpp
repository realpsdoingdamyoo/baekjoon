#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;

int n, a;

signed main(){
    fastio;

    cin >> n;
    for (int i=1, j; i<n; i=j+1) {
        j=(n-1)/((n-1)/i);
        a+=(j-i+1)*((n-1)/i);
    }
    cout << a+n;

    return 0;
}
