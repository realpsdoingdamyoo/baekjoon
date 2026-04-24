#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9, MOD=998244353, inf=4e18;

vector<int> w;
vector<array<int, 3>> dp;
vector<vector<int>> lnk;

void dfs(int p, int pre){
    dp[p]={w[p], 0, 0};
    for(int i : lnk[p]) if(i!=pre){
        dfs(i, p);
        dp[p][0]+=dp[i][0];
        dp[p][1]+=(dp[i][1]+dp[i][0])%mod;
        dp[p][2]+=dp[i][2];
    }
    for(int i : lnk[p]) if(i!=pre)
        dp[p][2]+=(dp[p][0]-dp[i][0])*(dp[i][1]+dp[i][0])%mod;
}

int solve(vector<array<int, 2>> v){
    sort(v.begin(), v.end());
    map<int, vector<array<int, 4>>> u;
    w.clear();

    int c=0;
    for(array<int, 2> i : v){
        if(u[i[0]].size() && u[i[0]].back()[2]+1==i[1])
            u[i[0]].back()[2]++, u[i[0]].back()[3]++, w.back()++;
        else u[i[0]].push_back({c++, i[1], i[1], 1}), w.push_back(1);
    }

    dp.clear(); lnk.clear();
    dp.resize(c); lnk.resize(c);

    for(int i=v[0][0]; i<v.back()[0]; i++){
        int s=0, e=0;
        while(s<u[i].size() && e<u[i+1].size()){
            array<int, 4>& S=u[i][s], E=u[i+1][e];
            if(max(S[1], E[1])<=min(S[2], E[2])){
                lnk[S[0]].push_back(E[0]);
                lnk[E[0]].push_back(S[0]);
            }
            if(S[2]<E[2]) s++; else e++;
        }
    }

    dfs(0, -1);

    return dp[0][2];
}

signed main() {
    fastio;

    int n; cin >> n;
    vector<array<int, 2>> v(n);
    for(array<int, 2>& i : v) cin >> i[0] >> i[1];
    int x=solve(v);
    for(array<int, 2>& i : v) swap(i[0], i[1]);
    int y=solve(v);
    cout << (x+y)%mod;

    return 0;
}
