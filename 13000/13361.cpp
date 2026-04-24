#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e9;

int n, m, ans;
vector<array<int, 2>> rec;
vector<int> pnt;
vector<int> lnk[505050];

bool vis[505050];
vector<int> unn;

void dfs(int p){
    unn.push_back(p); vis[p]=true;
    for(int i : lnk[p]) if(!vis[i]) dfs(i);
}

signed main(){
    fastio;

    cin >> n;
    for(int i=0; i<n; i++){
        int a, b; cin >> a >> b;
        rec.push_back({a, b});
        pnt.push_back(a);
        pnt.push_back(b);
        ans+=a+b;
    }

    sort(pnt.begin(), pnt.end());
    pnt.erase(unique(pnt.begin(), pnt.end()), pnt.end());
    m=pnt.size();

    for(array<int, 2> i : rec){
        int a=lower_bound(pnt.begin(), pnt.end(), i[0])-pnt.begin();
        int b=lower_bound(pnt.begin(), pnt.end(), i[1])-pnt.begin();
        lnk[a].push_back(b); lnk[b].push_back(a);
    }

    for(int i=0; i<m; i++){
        if(vis[i]) continue;

        unn.clear();
        dfs(i);

        int ed=0, mx=0, sum=0;
        for(int j : unn){
            ed+=lnk[j].size();
            mx=max(mx, pnt[j]);
            sum+=pnt[j];
        }
        if(ed/2==unn.size()) ans-=sum;
        else ans-=sum-mx;
    }

    cout << ans;

    return 0;
}
