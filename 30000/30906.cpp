#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;

map<int, int> mp;

signed main(){
    fastio;

    int N; cin >> N; N*=2;
    while (N--) {
        int a, b; cin >> a >> b; mp[a*mod+b]++;
    }
    for (pair<int, int> i : mp) if (i.second%2) {cout << "yes"; return 0;}
    cout << "no";

    return 0;
}
