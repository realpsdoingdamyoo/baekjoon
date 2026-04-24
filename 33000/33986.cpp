#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;

int n, v[10101];

signed main(){
    fastio;

    vector<array<int, 2>> ans;
    cin >> n;
    for(int i=1; i<=n; i++) cin >> v[i];

    int c=0;
    for(int x=1; x<=n; x++){
        for(int i=x; i<=n; i+=2){
            if(v[i]%2!=i%2){
                c++;
                ans.push_back({x, i});
                reverse(v+x, v+i+1);
                break;
            }
        }
        if(c!=x) break;
    }

    if(c){
        ans.push_back({1, c});
        reverse(v+1, v+c+1);
    }

    for(int x=1; x<n; x++){
        for(int i=x; i<=n; i++){
            if(v[i]==x){
                c++;
                ans.push_back({x, i});
                reverse(v+x, v+i+1);
                break;
            }
        }
    }

    cout << ans.size() << "\n";
    for(array<int, 2> i : ans) cout << i[0] << " " << i[1] << "\n";


    return 0;
}
