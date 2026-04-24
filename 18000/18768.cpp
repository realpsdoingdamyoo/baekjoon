#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

vector<ll> ta, tb;

int main(){
    fastio;
    ll t; cin >> t;
    while(t--){
        ll n, k, s=0, mx=0;
        cin >> n >> k; ta.resize(n); tb.resize(n);
        for(int i=0; i<n; i++) cin >> ta[i];
        for(int i=0; i<n; i++) {cin >> tb[i]; s+=tb[i]; ta[i]-=tb[i];}
        sort(ta.begin(), ta.end());
        int i;
        for(i=n-1; i>n-i+k; i--) s+=ta[i];
        for(; i>=n-i-k; i--) {s+=ta[i]; mx=max(mx, s);}
        cout << mx << endl;
    }
}
