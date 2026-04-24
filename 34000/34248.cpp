#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;


signed main(){
    fastio;

    int n, c[3]={};
    cin >> n;
    while (n--) {int a; cin >> a; c[a]++;}
    if ((c[1]+2*c[2])%3==0 && c[1]>=c[2]) cout << "Yes"; else cout << "No";

    return 0;
}
