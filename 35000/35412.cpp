#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=1e18;

signed main(){
    fastio;

    string s, r; cin >> s >> s;
    for (char i : s) {
        if (r.size()>1 && r[r.size()-2]==i) r.pop_back();
        if (r.size() && r.back()==i) r.pop_back();
        else r+=i;
    }
    cout << (r.size()?r:"-1");


    return 0;
}
