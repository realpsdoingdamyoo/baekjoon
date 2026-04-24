#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

int n;
vector<int> lnk[2020];
int sz[2020], dep[2020];
vector<vector<int>> v[2020];
vector<int> ch[2020];

void dfs(int p, int pre){
    for(int i : lnk[p]) if(i!=pre) dfs(i, p);
    
    for(int i : lnk[p]) if(i!=pre)
        if(v[p].size()<v[i].size()) swap(v[p], v[i]);
    
    for(int i : lnk[p]) if(i!=pre){
        int s=v[p].size()-v[i].size();
        for(int j=0; j<v[i].size(); j++){
            v[p][j+s].push_back(v[i][j][0]);
        }
    }
    
    for(int i=(int)v[p].size()-1; i>=0; i--){
        if(v[p][i].size()==1) break;
        sort(v[p][i].begin(), v[p][i].end());
        reverse(v[p][i].begin(), v[p][i].end());
        for(int j=0; j<v[p][i].size(); j++)
            v[p][i][j]+=j;
        v[p][i]={*max_element(v[p][i].begin(), v[p][i].end())};    
    }
    
    v[p].push_back({0});
}

int solve(int p){
    for(int i=1; i<=n; i++) v[i].clear();
        
    dfs(p, 0);
    int ret=0;
    for(vector<int> i : v[p]) ret=max(ret, i[0]);
    return ret+1;
}

signed main() {
    //fastio;
    
    cin >> n;
    for(int i=0; i<n-1; i++){
        int a, b; cin >> a >> b;
        lnk[a].push_back(b);
        lnk[b].push_back(a);
    }
    
    int ret=74828928;
    for(int i=1; i<=n; i++) ret=min(ret, solve(i));
    cout << ret << "\n";
    
    return 0;
}
