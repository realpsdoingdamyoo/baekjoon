#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll n, s=0; cin >> n;
    vector<ll> v(n);
    for(int i=0; i<n; i++) cin >> v[i];
    sort(v.begin(), v.end());
    for(int i=0; i<n; i++){
        if(v[i]==1 || v[i]-1<=s) s+=v[i];
        else {cout << s+1; break;}
        if(i==n-1) cout << s+1;
    }
    return 0;
}
