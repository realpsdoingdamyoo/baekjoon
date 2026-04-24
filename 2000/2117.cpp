#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2147483647;

int n;

signed main(){
    fastio;

    cin >> n;
    cout << (n/2)*(n/2-1)/2+(n-n/2)*(n-n/2-1)/2;


	return 0;
}
