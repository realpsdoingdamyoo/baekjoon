#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=4e18;

int n, m;
int t[1010][1010], d[1010][1010], vis[1010][1010];
vector<array<int, 2>> dir={{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

signed main(){
    fastio;

    cin >> m >> n;
    queue<array<int, 2>> q;
    for(int i=0; i<n; i++) for(int j=0; j<m; j++){
        cin >> t[i][j];
        d[i][j]=inf;
        if(t[i][j]==1){q.push({i, j}); d[i][j]=0;}
    }

    while(q.size()){
        array<int, 2> p=q.front(); q.pop();
        if(vis[p[0]][p[1]]++) continue;
        for(array<int, 2> v : dir){
            int x=p[0]+v[0], y=p[1]+v[1];
            if(x<0 || n<=x || y<0 || m<=y) continue;
            if(t[x][y]==-1) continue;
            if(d[x][y]<=d[p[0]][p[1]]) continue;
            d[x][y]=d[p[0]][p[1]]+1;
            q.push({x, y});
        }
    }

    int ret=0;
    for(int i=0; i<n; i++) for(int j=0; j<m; j++)
        if(t[i][j]!=-1) ret=max(ret, d[i][j]);

    cout << (ret==inf?-1:ret);


    return 0;
}
