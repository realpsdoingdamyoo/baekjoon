#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

signed main(){
    fastio;
    
    int n, v[6]={}; cin>>n;
    while(n--){int a; cin>>a; v[a]=1;}
    if(v[1]+v[2]+v[3]+v[4]+v[5]==5)cout<<"NO";else cout<<"YES";
    
    return 0;
}
