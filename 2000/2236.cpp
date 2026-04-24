#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;

signed main(){
    fastio;

    int n, k; cin >> n >> k;
    vector<array<int, 2>> v(n);
    vector<int> u(n);
    for(int i=0; i<n; i++){
        cin >> v[i][0]; v[i][1]=i+1;
    }
    sort(v.begin(), v.end());
    for(int i=n-1; i>n-1-min(k, n); i--){
        u[v[i][1]-1]=v[i][1];
        cout << v[i][1] << "\n";
    }
    for(int i=n; i<k; i++) cout << "0\n";
    for(int i=0; i<n; i++) cout << u[i] << "\n";

    return 0;
}
