#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;

vector<array<int, 2>> v;
int x[1010101], h[1010101];
int dp[1010101];

int stt=0;
vector<array<int, 2>> con;

double crs(array<int, 2> a, array<int, 2> b){
    return (b[1]-a[1]+0.0)/(a[0]-b[0]);
}

void solve(){
    int n; cin >> n;
    for(int i=1; i<=n; i++){
        int X, H; cin >> X >> H;
        while(v.size() && v.back()[1]-v.back()[0]<=H-X) v.pop_back();
        if(v.size()==0 || v.back()[0]+v.back()[1]<X+H) v.push_back({X, H});
    }

    n=v.size();
    for(int i=0; i<n; i++) x[i+1]=v[i][0], h[i+1]=v[i][1];

    dp[1]=h[1]*h[1]*4;
    con.push_back({2*(h[1]-x[1]), (h[1]-x[1])*(h[1]-x[1])+dp[0]});

    for(int i=2; i<=n; i++){
        while(con.size()-stt>=2 && crs(con[stt], con[stt+1])<(x[i]+h[i])) stt++;
        dp[i]=(x[i]+h[i])*(x[i]+h[i])+(x[i]+h[i])*con[stt][0]+con[stt][1];
        dp[i]=min(dp[i], dp[i-1]+h[i]*h[i]*4);
        array<int, 2> c={(h[i]-x[i])*2, (h[i]-x[i])*(h[i]-x[i])+dp[i-1]};
        while(con.size()-stt>=2 && crs(con[con.size()-2], con[con.size()-1])>crs(con[con.size()-1], c)) con.pop_back();
        con.push_back(c);
    }
    cout << dp[n]/4 << ".";
    if(dp[n]%4==0) cout << "00\n";
    else cout << dp[n]*25%100 << "\n";

    stt=0;
    v.clear();
    con.clear();
}

signed main(){
    fastio;

    int t; cin >> t;
    while(t--) solve();

    return 0;
}
