#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define mod 1000000007
ll n, m, from;
ll minarr[5000000];
ll maxarr[5000000];


ll min_(ll a, ll b){return a>b?b:a;}
ll max_(ll a, ll b){return a>b?a:b;}

ll mini(ll l, ll r, ll idx = 1, ll L=1, ll R=from) {
    if (l>R or r<L) return 1000000000;
    else if (l<=L and r>=R) return minarr[idx];
    ll m=(L+R)/2;
    return min_(mini(l, r, idx*2, L, m), mini(l, r, idx*2+1, m+1, R));
}

ll maxi(ll l, ll r, ll idx = 1, ll L=1, ll R=from) {
    if (l>R or r<L) return 1;
    else if (l<=L and r>=R) return maxarr[idx];
    ll m=(L+R)/2;
    return max_(maxi(l, r, idx*2, L, m), maxi(l, r, idx*2+1, m+1, R));
}

int main() {
    scanf("%lld %lld", &n, &m);
    from = ((n&(n-1)) == 0)?pow(2,(int)log2(n)):pow(2,(int)log2(n)+1);
    for (int i=1; i<from+n; i++) minarr[i] = 1000000000;
    for (int i=1; i<from+n; i++) maxarr[i] = 0;
    
    for (ll i=from; i<from+n; i++){cin >> minarr[i]; maxarr[i]=minarr[i];}
    
    for (ll i=from-1; i>=1; --i) minarr[i] = min_(minarr[i*2], minarr[i*2+1]);
    for (ll i=from-1; i>=1; --i) maxarr[i] = max_(maxarr[i*2], maxarr[i*2+1]);
    for (ll i=0; i<m; i++){
        ll b, c;
        scanf("%lld %lld", &b, &c);
        
    	printf("%lld\n", mini(b, c));
        
    }
}
