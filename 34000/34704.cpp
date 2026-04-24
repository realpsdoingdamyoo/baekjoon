#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

signed main(){
    fastio;
    
    int a[5]={}, n, i, r=0; cin >> n;
    while(n--) cin>>i,a[i]++;
    r=a[4]+a[3]; a[1]=max(0LL, a[1]-a[3]);
    r+=a[2]+1>>1; if(a[2]&1) a[1]=max(0LL, a[1]-2);
    r+=a[1]+3>>2; cout<<r;
    
    return 0;
}
