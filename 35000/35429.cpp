#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, inf=1e18;
 
signed main() {
    fastio;
 
    int N, V[400]={}; cin >> N;
    string S; cin >> S;
    for (char i : S) V[i]++;
 
    cout << min({V['G'], V['H'], V['S']/2});
 
    return 0;
}
