#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;

int n;
array<int, 2> v[202020];

signed main(){
    fastio;

    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> v[i][0]; v[i][1]=i;
    }
    sort(v+1, v+n+1); reverse(v+1, v+n+1);

    int ans=0, ap=0, s=0;
    for (int i=1; i<=n; i++) {
        s+=v[i][0];
        int r=s+v[1][0]+v[i][0];
        if (r>ans) ans=r, ap=i;
    }

    cout << ap << "\n";
    for (int i=1; i<=ap; i++) cout << v[i][1] << ' ';


    return 0;
}
