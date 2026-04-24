#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;

map<array<int, 2>, int> mp;

int solve(int s, int e){
    if(s==0 && e==0) return 0;
    int ret=0;
    if(mp.find({s, e})!=mp.end()) return mp[{s, e}];
    for(int i=1; i<=40; i++){
        int l=(1LL<<i)-1, r=(1LL<<i+1)-2;
        l=max(l, s); r=min(r, e);
        if(l<=r) ret=max(ret, solve(l-(1<<i)+1, r-(1<<i)+1)+i);
    }
    return mp[{s, e}]=ret;
}

signed main(){
    fastio;

    int t; cin >> t;
    while(t--){
        int a, b; cin >> a >> b;
        cout << solve(a, b) << "\n";
    }

    return 0;
}
