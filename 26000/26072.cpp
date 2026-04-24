#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

int main(){
    fastio;
    ll n, l, s=0, sw=0; cin >> n >> l;
    vi x(n), w(n);
    for(int i=0; i<n; i++) cin >> x[i];
    for(int i=0; i<n; i++) {cin >> w[i]; s+=x[i]*w[i]; sw+=w[i];}
    double ss=s;
    printf("%lf", ss/sw);
    return 0;
}
