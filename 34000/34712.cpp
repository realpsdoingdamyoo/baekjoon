#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e17;

signed main() {
    //fastio;

    int N; cin >> N;
    cout << "? 100000\n" << endl;
    int x; cin >> x;

    int s=1, e=100000;
    while (s<=e) {
        int m=s+e>>1;
        cout << "? " << m << endl;
        int y; cin >> y;
        if (y==x-N*(100000-m)) e=m-1; else s=m+1;
    }
    cout << "! " << s << endl;

    return 0;
}
