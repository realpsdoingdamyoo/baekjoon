#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=4e18;

int n, m, w;
int ans[2]={inf, inf};
vector<array<int, 2>> lnk[101010];
vector<array<int, 3>> ed;

vector<int> un[101010];
int upr[101010];

int dep[101010];
int dp[101010][20];
array<int, 2> sp[101010][20];

void dfs(int p, int pre, int Dep){
    dep[p]=Dep;
    for(array<int, 2> i : lnk[p]) if(i[0]!=pre){
        dp[i[0]][0]=p; sp[i[0]][0][i[1]%2]=i[1];
        dfs(i[0], p, Dep+1);
    }
}

array<int, 2> spt(int a, int b){
    array<int, 2> ret={-inf, -inf};
    if(dep[a]<dep[b]) swap(a, b);
    int df=dep[a]-dep[b];
    for(int i=0; i<20; i++) if(df&(1<<i)){
        int ac0=sp[a][i][0]; ret[0]=max(ret[0], ac0);
        int ac1=sp[a][i][1]; ret[1]=max(ret[1], ac1);
        a=dp[a][i];
    }
    if(a==b) return ret;

    for(int i=19; i>=0; i--) if(dp[a][i]!=dp[b][i]){
        int ac0=sp[a][i][0]; ret[0]=max(ret[0], ac0);
        int ac1=sp[a][i][1]; ret[1]=max(ret[1], ac1);
        a=dp[a][i];
        int bc0=sp[b][i][0]; ret[0]=max(ret[0], bc0);
        int bc1=sp[b][i][1]; ret[1]=max(ret[1], bc1);
        b=dp[b][i];
    }
    int ac0=sp[a][0][0]; ret[0]=max(ret[0], ac0);
    int ac1=sp[a][0][1]; ret[1]=max(ret[1], ac1);
    int bc0=sp[b][0][0]; ret[0]=max(ret[0], bc0);
    int bc1=sp[b][0][1]; ret[1]=max(ret[1], bc1);

    return ret;
}

signed main(){
    fastio;

    cin >> n >> m;
    for(int i=0; i<m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        ed.push_back({a, b, c});
    }

    for(int i=1; i<=n; i++) un[i].push_back(i), upr[i]=i;
    priority_queue<array<int, 3>> pq;
    for(array<int, 3> i : ed) pq.push({-i[2], i[0], i[1]});

    while(pq.size()){
        array<int, 3> t=pq.top(); pq.pop();
        int a=t[1], b=t[2];
        if(upr[a]==upr[b]) continue;

        lnk[a].push_back({b, -t[0]});
        lnk[b].push_back({a, -t[0]});
        a=upr[a]; b=upr[b];

        w-=t[0];
        if(un[a].size()<un[b].size()) swap(a, b);

        for(int i : un[b]){
            un[a].push_back(i);
            upr[i]=a;
        } un[b].clear();
    }

    ans[w%2]=w;
    for(int i=0; i<=n; i++) for(int j=0; j<20; j++) sp[i][j]={-inf, -inf};

    dfs(1, 0, 0);

    for(int j=1; j<20; j++){
        for(int i=1; i<=n; i++){
            dp[i][j]=dp[dp[i][j-1]][j-1];
            sp[i][j][0]=max(sp[i][j-1][0], sp[dp[i][j-1]][j-1][0]);
            sp[i][j][1]=max(sp[i][j-1][1], sp[dp[i][j-1]][j-1][1]);
        }
    }

    for(array<int, 3> i : ed){
        int a=i[0], b=i[1], c=i[2];
        if(dep[a]<dep[b]) swap(a, b);
        array<int, 2> mnl=spt(a, b);
        for(int j=0; j<=1; j++){
            int cst=w+c-mnl[j];
            ans[cst%2]=min(ans[cst%2], cst);
        }
    }

    cout << (ans[1]==inf?-1:ans[1]) << " " << (ans[0]==inf?-1:ans[0]);

    return 0;
}
