#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef array<ll, 2> pii;
typedef vector<pii> vpii;
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define vcin; for(int i=0; i<n; i++) cin >> v[i];
const int mod=1e9+7, MOD=998244353;
const int dir[4][2]={{0, 1}, {1, 0}, {-1, 0}, {0, -1}};


int main(){
    fastio;
    int n; cin >> n;
    vpii vp(n); vi v, dp(n);
    for(int i=0; i<n; i++) cin >> vp[i][0] >> vp[i][1];
    sort(vp.begin(), vp.end());
    for(int i=0; i<n; i++) v.push_back(vp[i][1]);
    ll mx=0;
    for(int i=0; i<n; i++){
        dp[i]=1;
        for(int j=0; j<i; j++) if(v[i]>=v[j]) dp[i]=max(dp[i], dp[j]+1);
        mx=max(mx, dp[i]);
    }
    cout << n-mx;
    return 0;
}
