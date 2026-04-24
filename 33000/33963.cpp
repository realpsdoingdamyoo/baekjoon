#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e9;

signed main(){
    fastio;

    int n; cin >> n;
    int c=0;
    while((int)log10(n*2)==(int)log10(n)) n*=2, c++;
    cout << c;

    return 0;
}
