#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=4e18;

map<int, array<int, 2>> mp;

signed main(){
    fastio;

    int n, q; cin >> n >> q;
    vector<int> v(n);
    for(int& i : v) cin >> i;
    sort(v.begin(), v.end());

    while(q--){
        int a; cin >> a;
        if(mp.find(a)!=mp.end()){
            cout << mp[a][0] << " " << mp[a][1] << "\n";
            continue;
        }

        int d=a-1, u=0;
        for(int i=0; (i-1)*a<v.back(); i++){
            int D=lower_bound(v.begin(), v.end(), i*a)-v.begin();
            if(0<=D && D<n) d=min(d, v[D]%a);
            int U=lower_bound(v.begin(), v.end(), i*a)-1-v.begin();
            if(0<=U && U<n) u=max(u, v[U]%a);
        }
        cout << d << " " << u << "\n";
        mp[a]={d, u};
    }


    return 0;
}
