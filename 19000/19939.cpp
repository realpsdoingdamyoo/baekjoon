#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;

signed main(){
    fastio;

    int n, k; cin >> n >> k;
    vector<int> v(k);

    for(int i=0; i<k; i++){
        v[i]=i+1;
        n-=i+1;
    }

    if(n<0){
        cout << "-1\n";
        return 0;
    }

    for(int i=0; i<n; i++){
        v[k-i%k-1]++;
    }
    cout << v.back()-v[0] << "\n";

    return 0;
}
