#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;

int N, P, S;

signed main(){
    fastio;

    cin >> N >> P >> S;
    while (S--) {
        int K, x=0; cin >> K;
        while (K--) {
            int a; cin >> a;
            if (a==P) x=1;
        }
        cout << (x?"KEEP\n":"REMOVE\n");
    }

    return 0;
}
