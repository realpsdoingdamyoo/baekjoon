#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e9;

int n, c[3030];

signed main(){
    fastio;

    cin >> n;
    vector<string> s(n);
    for(string& i : s) cin >> i;
    for(int i=0; i<n; i++) for(int j=0; j<n; j++) c[i+1]+=(s[i][j]=='W');

    int p=0;
    for(int i=1; i<=n; i++) if(c[i]>c[p]) p=i;

    if(c[p]==n-1) cout << "1 " << p << "\n";
    else cout << "2 " << p << "\n";

    return 0;
}
