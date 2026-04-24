#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2147483647;

int n;
int dp[101010];
int h[101010], w[101010];
vector<array<int, 2>> con;
int s=0;

double meet(array<int, 2> a, array<int, 2> b){
    return (b[1]-a[1]+0.0)/(a[0]-b[0]);
}

signed main(){
    fastio;

    cin >> n;
    vector<array<int, 2>> u(n), v;
    for(int i=0; i<n; i++) cin >> u[i][0] >> u[i][1];
    sort(u.begin(), u.end());
    for(array<int, 2> i : u){
        while(v.size() && v.back()[1]<=i[1]) v.pop_back();
        v.push_back(i);
    } n=v.size();
    for(int i=1; i<=n; i++) w[i]=v[i-1][1], h[i]=v[i-1][0];

    con.push_back({w[1], 0});
    for(int i=1; i<=n; i++){
        while(con.size()>s+1 && con[s][0]*h[i]+con[s][1]>con[s+1][0]*h[i]+con[s+1][1]) s++;
        dp[i]=con[s][0]*h[i]+con[s][1];
        array<int, 2> p={w[i+1], dp[i]};
        while(con.size()>s+1 && meet(con[con.size()-2], p)>meet(con[con.size()-1], p)) con.pop_back();
        con.push_back(p);
    }

    cout << dp[n];


    return 0;
}
