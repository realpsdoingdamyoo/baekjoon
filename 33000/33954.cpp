#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e9;

signed main(){
    fastio;

    int n; cin >> n;
    vector<int> a(n), b(n);
    for(int i=0; i<n; i++){
        int x; cin >> x; x--;
        a[i]=x; b[x]=i;
    }

    int p=0, q=0;
    for(int i=0; i<n-1; i++){
        p=max(p, abs(a[i]-a[i+1]));
        q=max(q, abs(b[i]-b[i+1]));
    }
    cout << p << "/1\n1/" << q;

    return 0;
}
