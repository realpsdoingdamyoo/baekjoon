#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e17;

int n;
array<int, 3> v[20202];

int odd(int s, int e) {
    int ret=0;
    for (int i=1; i<=n; i++) {
        int _e=min(e, v[i][2]);
        int _s=min(s-1, v[i][2]);
        if (v[i][0]<=_e) ret+=(_e-v[i][0])/v[i][1]+1;
        if (v[i][0]<=_s) ret-=(_s-v[i][0])/v[i][1]+1;
    }
    return ret%2;
}

int Count(int p){
    int ret=0;
    for (int i=1; i<=n; i++) {
        if (p<v[i][0] || p>v[i][2]) continue;
        if (p%v[i][1]==v[i][0]%v[i][1]) ret++;
    }
    return ret;
}

signed main() {
    fastio;

    cin >> n;
    for (int i=1; i<=n; i++) cin >> v[i][0] >> v[i][2] >> v[i][1];
    int s=1, e=1LL<<31;
    if (!odd(s, e)){cout << "NOTHING"; return 0;}
    while (s<e) {
        int m=s+e>>1;
        if (odd(s, m)) e=m;
        else s=m+1;
    }
    cout << s << " " << Count(s);

    return 0;
}
