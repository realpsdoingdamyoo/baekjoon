#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=4e18;

vector<int> v;
const int X=4050505;
bool av[X];

signed main(){
    fastio;

    int n; cin >> n;
    vector<int> v(n);
    for(int& i : v) cin >> i;
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for(int i=0; i<v.size(); i++){
        for(int j=i; j<v.size(); j++){
            if(v[i]*v[j]>X) break;
            av[v[i]*v[j]]=true;
        }
    }

    for(int i=0; i<X; i++) if(!av[i]){
        cout << i; return 0;
    }


    return 0;
}
