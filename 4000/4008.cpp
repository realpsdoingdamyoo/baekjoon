#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2147483647;

int n, a, b, c;
int x[1010101], dp[1010101];
vector<array<int, 2>> con;
int s=0;

double meet(array<int, 2> a, array<int, 2> b){
    return (b[1]-a[1]+0.0)/(a[0]-b[0]);
}

signed main(){
    fastio;

    cin >> n;
    cin >> a >> b >> c;

    for(int i=1; i<=n; i++) cin >> x[i];
    for(int i=1; i<=n; i++) x[i]+=x[i-1];

    con.push_back({b, 0});
    for(int i=1; i<=n; i++){
        while(con.size()>s+1 && con[s][0]*x[i]+con[s][1]<con[s+1][0]*x[i]+con[s+1][1]) s++;
        dp[i]=con[s][0]*x[i]+con[s][1]+a*x[i]*x[i]+c;
        array<int, 2> p={-2*a*x[i]+b, dp[i]+a*x[i]*x[i]-b*x[i]};
        while(con.size()>s+1 && meet(con[con.size()-2], p)>meet(con[con.size()-1], p)) con.pop_back();
        con.push_back(p);
    }

    cout << dp[n];


    return 0;
}
