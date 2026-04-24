#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define vcin; for(int i=0; i<n; i++) cin >> v[i];
const int mod=1e9+7;
const int MOD=998244353;

int main(){
    fastio;
    int n; cin >> n;
    vi v1(n), v2(n);
    for(int i=0; i<n; i++) cin >> v1[i];
    for(int i=0; i<n; i++) cin >> v2[i];
    for(int i=1; i<n; i++) v1[i]+=v1[i-1];
    for(int i=1; i<n; i++) v2[i]+=v2[i-1];
    vi v(1);
    for(int i=0; i<n; i++) v.push_back(v1[i]-v2[i]);
    sort(v.begin(), v.end());
    ll s=100000000000000, q=0, ans=0;
    while(v.size()){
        if(v[v.size()-1]==s){
            v.pop_back();
            ans+=(++q);
        }
        else{
            s=v[v.size()-1];
            v.pop_back();
            q=0;
        }
    }
    cout << ans;

    return 0;
}
