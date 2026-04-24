#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=4e18;

int n, m, w;
array<int, 2> ans={inf, inf};
vector<array<int, 2>> lnk[101010];
vector<array<int, 3>> ed;

vector<int> un[101010];
int upr[101010];

int dep[101010];
int dp[101010][20];
array<int, 2> sp[101010][20];

array<int, 2> mrg(array<int, 2> a, array<int, 2> b){
    vector<int> dd;
    dd.push_back(a[0]);
    dd.push_back(a[1]);
    dd.push_back(b[0]);
    dd.push_back(b[1]);
    sort(dd.begin(), dd.end());
    dd.erase(unique(dd.begin(), dd.end()), dd.end());
    reverse(dd.begin(), dd.end());
    dd.push_back(-inf);
    return {dd[0], dd[1]};
}

array<int, 2> mrg2(array<int, 2> a, array<int, 2> b){
    vector<int> dd;
    dd.push_back(a[0]);
    dd.push_back(a[1]);
    dd.push_back(b[0]);
    dd.push_back(b[1]);
    sort(dd.begin(), dd.end());
    dd.erase(unique(dd.begin(), dd.end()), dd.end());
    dd.push_back(inf);
    return {dd[0], dd[1]};
}

void dfs(int p, int pre, int Dep){
    dep[p]=Dep;
    for(array<int, 2> i : lnk[p]) if(i[0]!=pre){
        dp[i[0]][0]=p; sp[i[0]][0][0]=i[1];
        dfs(i[0], p, Dep+1);
    }
}

array<int, 2> spt(int a, int b){
    array<int, 2> ret={-inf, -inf};
    if(dep[a]<dep[b]) swap(a, b);
    int df=dep[a]-dep[b];
    for(int i=0; i<20; i++) if(df&(1<<i)){
        int ac0=sp[a][i][0]; ret=mrg(ret, {ac0, -inf});
        int ac1=sp[a][i][1]; ret=mrg(ret, {ac1, -inf});
        a=dp[a][i];
    }
    if(a==b) return ret;

    for(int i=19; i>=0; i--) if(dp[a][i]!=dp[b][i]){
        int ac0=sp[a][i][0]; ret=mrg(ret, {ac0, -inf});
        int ac1=sp[a][i][1]; ret=mrg(ret, {ac1, -inf});
        a=dp[a][i];
        int bc0=sp[b][i][0]; ret=mrg(ret, {bc0, -inf});
        int bc1=sp[b][i][1]; ret=mrg(ret, {bc1, -inf});
        b=dp[b][i];
    }
    int ac0=sp[a][0][0]; ret=mrg(ret, {ac0, -inf});
    int ac1=sp[a][0][1]; ret=mrg(ret, {ac1, -inf});
    int bc0=sp[b][0][0]; ret=mrg(ret, {bc0, -inf});
    int bc1=sp[b][0][1]; ret=mrg(ret, {bc1, -inf});

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

    int x=n-1;
    while(pq.size()){
        array<int, 3> t=pq.top(); pq.pop();
        int a=t[1], b=t[2];
        if(upr[a]==upr[b]) continue;

        lnk[a].push_back({b, -t[0]});
        lnk[b].push_back({a, -t[0]});
        a=upr[a]; b=upr[b]; x--;

        w-=t[0];
        if(un[a].size()<un[b].size()) swap(a, b);

        for(int i : un[b]){
            un[a].push_back(i);
            upr[i]=a;
        } un[b].clear();
    }

    if(x){cout << "-1"; return 0;}

    ans[w%2]=w;
    for(int i=0; i<=n; i++) for(int j=0; j<20; j++) sp[i][j]={-inf, -inf};

    dfs(1, 0, 0);

    for(int j=1; j<20; j++){
        for(int i=1; i<=n; i++){
            dp[i][j]=dp[dp[i][j-1]][j-1];
            sp[i][j]=mrg(sp[i][j-1], sp[dp[i][j-1]][j-1]);
        }
    }

    for(array<int, 3> i : ed){
        int a=i[0], b=i[1], c=i[2];
        if(dep[a]<dep[b]) swap(a, b);

        array<int, 2> mnl=spt(a, b);
        for(int j=0; j<=1; j++){
            int cst=w+c-mnl[j];
            ans=mrg2(ans, {cst, inf});
            //cout << cst << "\n";
        }
    }
    //cout << ans[0] << " " << ans[1] << "\n";
    cout << (ans[1]==inf?-1:ans[1]);

    return 0;
}
