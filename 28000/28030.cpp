#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=4e18;

int n, m, r;
bool dp[1010][1010], root[1010], val[1010];
int dep[1010], par[1010];
vector<int> lnk[1010][2], arr[1010][2];
vector<array<int, 2>> ans;

void dfs(int t, int p){
    arr[dep[p]][t].push_back(p);
    for(int i : lnk[p][t]) dep[i]=dep[p]+1, dfs(t, i);
}

void Add(int a, int b){
    ans.push_back({a, b});
    for(int i : lnk[a][0]) lnk[b][0].push_back(i);
    lnk[a][0].clear();
}

void af(int p){
    vector<int> tmp[2];
    for(int i : lnk[p][0])
        tmp[val[i]].push_back(i);

    for(int i : tmp[0]) for(int j : tmp[1])
        if(dp[i][j]){Add(i, j); break;}
    for(int i : tmp[1]) af(i);
}

void solve(){
    cin >> n;
    for(int i=1; i<=n; i++) root[i]=true;
    for(int i=1; i<n; i++){
        int a, b; cin >> a >> b;
        lnk[b][0].push_back(a);
        root[a]=false;
    }
    cin >> m;
    for(int i=1; i<m; i++){
        int a, b; cin >> a >> b;
        lnk[b][1].push_back(a); par[a]=b;
        val[a]=val[b]=true;
    }

    for(int i=1; i<=n; i++) if(root[i]) r=i;
    dfs(0, r); dfs(1, r);

    for(int d=n; d>=1; d--){
        for(int i : arr[d][0]){
            vector<int> st;
            for(int j : lnk[i][0]){
                if(val[j]) continue;
                bool fl=false;

                for(int k : lnk[i][1]) if(k!=j) fl|=dp[j][k];
                if(!fl) st.push_back(j);
            }

            for(int j : arr[d][1]){
                if(val[i]) dp[i][j]=(i==j);
                else if(i>j) dp[i][j]=false;
                else{
                    dp[i][j]=true;
                    for(int k : lnk[i][0]) if(val[k])
                        dp[i][j]&=(par[k]==j);
                    for(int k : st){
                        bool fl=false;
                        for(int l : lnk[j][1]) fl|=dp[k][l];
                        dp[i][j]&=fl;
                    }
                }
            }
        }
    }
    af(r);

    cout << ans.size() << "\n";
    for(array<int, 2> i : ans) cout << i[0] << " " << i[1] << "\n";

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++) dp[i][j]=false;
        root[i]=val[i]=false;
        dep[i]=par[i]=0;
        lnk[i][0].clear(); lnk[i][1].clear();
        arr[i][0].clear(); arr[i][1].clear();
    } ans.clear();
}

signed main(){
    fastio;

    int t; cin >> t;
    while(t--) solve();

    return 0;
}
