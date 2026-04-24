#include <bits/stdc++.h>
#define int long long
using namespace std;
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
const int mod=1e9+7, MOD=998244353, inf=1e18;

signed main(){
    fastio;

    int N; cin >> N;
    for (int i=N; i>=2; i-=2) cout << i << " ";
    if (N%2) cout << "1 1 ";
    for (int i=1+N%2; i<=N; i+=2) cout << i << " " << i+1 << " " << i << " ";

    return 0;
}
