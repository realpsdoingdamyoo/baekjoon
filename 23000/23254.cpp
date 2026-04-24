#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef array<ll, 2> pii;
typedef vector<pii> vpii;
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define vcin; for(int i=0; i<n; i++) cin >> v[i];
const int mod=1e9+7;
const int MOD=998244353;


int main(){
    fastio;

    int t, n, s=0; cin >> t >> n; t*=24;
    vi a(n), b(n);
    vpii v;
    for(int i=0; i<n; i++) {cin >> a[i]; s+=a[i];}
    for(int i=0; i<n; i++) cin >> b[i];
    for(int i=0; i<n; i++){
        v.push_back({b[i], (100-a[i])/b[i]});
        if((100-a[i])%b[i]){
            v.push_back({(100-a[i])%b[i], 1});
        }
    }

    sort(v.begin(), v.end());
    while(v.size() && t){
        pii vt=v[v.size()-1];
        if(vt[1]>t){
            s+=t*vt[0];
            t=0;
        }
        else{
            t-=vt[1];
            s+=vt[0]*vt[1];
            v.pop_back();
        }
    }
    cout << s;
    return 0;
}
