#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2147483647;

signed main(){
    fastio;

    int n, k; cin >> n >> k;
    int a[4]; for(int i=0; i<4; i++) cin >> a[i];
    vector<int> v[4];
    for(int i=0; i<n; i++){
        char c; int a;
        cin >> c >> a;
        v[c-'A'].push_back(a);
    }

    for(int i=0; i<4; i++) v[i].push_back(-1), sort(v[i].begin(), v[i].end());

    while(k--){
        int p=0;
        for(int i=0; i<4; i++){
            if(v[i].back()*a[p]>v[p].back()*a[i]) p=i;
        }
        cout << (char)('A'+p) << " " << v[p].back() << "\n";
        a[p]+=v[p].back();
        v[p].pop_back();
    }

    return 0;
}
