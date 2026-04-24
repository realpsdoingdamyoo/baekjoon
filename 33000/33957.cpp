#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e9;

int l[101010], r[101010];

signed main(){
    fastio;

    int n; cin >> n;
    int Ll=0, Lr=0, Rl=0, Rr=0;
    for(int i=0; i<n; i++){
        cin >> l[i] >> r[i];
        Rl+=l[i]; Rr+=r[i];
    }

    int ans=0;
    for(int i=0; i<n-1; i++){
        Ll+=l[i]; Lr+=r[i];
        Rl-=l[i]; Rr-=r[i];
        if(max(Ll, Rl)<=min(Lr, Rr)) ans++;
    }
    cout << ans;

    return 0;
}
