#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e9;

int n, m, s, p;
vector<int> lnk[2][505050];
bool vsd[2][505050];
vector<int> seq;
vector<vector<int>> scc;

void dfs(int t, int pnt){
    vsd[t][pnt]=true;
    for(int i : lnk[t][pnt]) if(!vsd[t][i]) dfs(t, i);
    if(t==0) seq.push_back(pnt);
    else scc.back().push_back(pnt);
}

vector<int> amg;
int unn[505050];
int cst[505050];
vector<int> res;

set<int> ed[505050];
int dp[505050], rp[505050];
int in[505050], Cg[505050];

signed main(){
    fastio;

    cin >> n >> m;
    for(int i=0; i<m; i++){
        int a, b; cin >> a >> b;
        lnk[0][a].push_back(b);
        lnk[1][b].push_back(a);
    }
    for(int i=1; i<=n; i++) cin >> cst[i];
    cin >> s >> p;
    for(int i=0; i<p; i++){int a; cin >> a; res.push_back(a);}

    for(int i=1; i<=n; i++) if(!vsd[0][i]) dfs(0, i);

    while(seq.size()){
        if(vsd[1][seq.back()]){
            seq.pop_back();
            continue;
        }
        scc.push_back({});
        dfs(1, seq.back());
    }

    for(vector<int>& c : scc){
        unn[c[0]]=c[0]; amg.push_back(c[0]); dp[c[0]]=cst[c[0]];
        for(int i=1; i<c.size(); i++){
            unn[c[i]]=c[0]; dp[c[0]]+=cst[c[i]];
            for(int j : lnk[0][c[i]]){
                lnk[0][c[0]].push_back(j);
            }
        }
    }

    Cg[unn[s]]=1;

    for(int i : amg){
        for(int j : lnk[0][i]) ed[i].insert(unn[j]);
        if(ed[i].find(i)!=ed[i].end()) ed[i].erase(i);
        for(int j : ed[i]) in[j]++;
    }

    vector<int> inz;
    for(int i : amg) if(in[i]==0) inz.push_back(i);

    while(inz.size()){
        int p=inz.back(); inz.pop_back();
        dp[p]+=rp[p]; dp[p]*=Cg[p];
        for(int i : ed[p]){
            if(!--in[i]) inz.push_back(i);
            rp[i]=max(rp[i], dp[p]);
            Cg[i]=max(Cg[i], Cg[p]);
        }
    }

    int ans=0;
    for(int i : res) ans=max(ans, dp[unn[i]]);
    cout << ans;

    return 0;
}
