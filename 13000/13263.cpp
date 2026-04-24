#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2147483647;

int n;
int a[101010], b[101010];
int dp[101010];
vector<array<int, 2>> dq;
int stt=0;

double meet(array<int, 2> a, array<int, 2> b){
    return (b[1]-a[1]+0.0)/(a[0]-b[0]);
}

signed main(){
    fastio;

    cin >> n;
    for(int i=1; i<=n; i++) cin >> a[i];
    for(int i=1; i<=n; i++) cin >> b[i];

    dq.push_back({b[1], 0});

    for(int i=2; i<=n; i++){
        int ret=0;
        while(dq.size()-stt>1 && dq[stt][0]*a[i]+dq[stt][1]>dq[stt+1][0]*a[i]+dq[stt+1][1]) stt++;
        ret=dq[stt][0]*a[i]+dq[stt][1];
        dp[i]=ret;
        while(dq.size()-stt>1 && meet(dq[dq.size()-2], {b[i], dp[i]})>meet(dq[dq.size()-1], {b[i], dp[i]})) dq.pop_back();
        dq.push_back({b[i], dp[i]});

    }
    cout << dp[n];


    return 0;
}
