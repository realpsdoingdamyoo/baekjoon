#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;

signed main(){
    fastio;

    int n; string s; cin >> n >> s;
    int lb=0, ld=0, rb=0, rd=0;
    for(int i=0; i<n; i++){
        if(s[i]=='B') rb++;
        if(s[i]=='D') rd++;
    }

    int ans=inf;
    for(int i=0; i<n; i++){
        ans=min(ans, ld+rb);
        lb+=(s[i]=='B'); rb-=(s[i]=='B');
        ld+=(s[i]=='D'); rd-=(s[i]=='D');
        ans=min(ans, ld+rb);
    }
    cout << ans;


    return 0;
}
