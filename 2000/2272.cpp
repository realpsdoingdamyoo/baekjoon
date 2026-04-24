#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

int a[1010101], b[1010101];

int main(){
    fastio;

    ll n, m; cin >> n >> m;
    for(ll i=0; i<n; i++) cin >> a[i];
    for(ll i=0; i<31; i++){
        if((m&(1LL<<i))==0) continue;
        for(ll j=0; j<n; j++) b[j]=a[j];
        for(ll j=0; j<n; j++) a[j]=a[j]^b[(j+(1LL<<i))%n];
    }
    for(ll i=0; i<n; i++) cout << a[i] << "\n";

    return 0;
}
