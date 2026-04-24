#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

int main(){
    fastio;
    ll t; cin >> t;
    while(t--){
        priority_queue<ll> pq;
        ll n, k; cin >> n >> k;
        vi ans(n), arr(n);
        for(ll i=0; i<n; i++) cin >> arr[i];
        sort(arr.begin(), arr.end());
        for(ll i=0; i<n; i++){
            pq.push(max(0LL, arr[i]-i*k)); pq.push(max(0LL, arr[i]-i*k)); pq.pop();
            ans[i]=pq.top();
        }
        for(ll i=n-2; i>=0; i--) if(ans[i]>ans[i+1]) ans[i]=ans[i+1];
        //for(ll i=0; i<n; i++) cout << ans[i]+i*k << " ";
        ll s=0;
        for(ll i=0; i<n; i++) s+=abs(arr[i]-ans[i]-i*k);
        cout << s << "\n";
    }
    return 0;
}
