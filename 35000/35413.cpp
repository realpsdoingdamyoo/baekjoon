#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=1e18;

signed main(){
    fastio;

    int N, K; cin >> N >> K;
    if (K<=1) for (int i=1; i<=N; i++) cout << K << " ";
    else if (K==2) {
        if (N==1) cout << -1;
        else for (int i=1; i<=N; i++) cout << (i==1?0:2) << " ";
    }
    else for (int i=0; i<N; i++) cout << min(i, K-2) << " ";

    return 0;
}
