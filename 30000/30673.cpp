#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=4e18;

int s[10101010];

bool solve(){
    int n, c; cin >> n >> c;
    vector<int> v(n);
    for(int& i : v) cin >> i;
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    for(int i=1; i<=c; i++) s[i]=0;
    for(int i : v) s[i]=1;
    for(int i=1; i<=c; i++) s[i]+=s[i-1];

    for(int i : v){
        for(int j=i; j<=c; j+=i){
            int e=min(j+i-1, c);
            if(s[e]-s[j-1]==0) continue;
            if(s[j/i]-s[j/i-1]==0) return false;
        }
    }
    return true;
}

signed main(){
    fastio;

    int t; cin >> t;
    while(t--){
        cout << (solve()?"Yes\n":"No\n");
    }

    return 0;
}
