#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;

int N, A;
int v[2222222], u[4444444];

signed main(){
    fastio;

    cin >> N;
    for (int i=2; i<(1<<N+1); i++) cin >> v[i];
    for (int i=(1<<N+1)-1; i>=3; i-=2) {
        u[i/2]=max(u[i]+v[i], u[i-1]+v[i-1]);
        A+=abs(u[i]+v[i]-u[i-1]-v[i-1])+v[i]+v[i-1];
    }
    cout << A << "\n";


    return 0;
}
