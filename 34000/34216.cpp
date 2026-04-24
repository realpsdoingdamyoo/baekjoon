#include "worldmap.h"
#include <bits/stdc++.h>
using namespace std;
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e14;

vector<int> lnk[50];
vector<int> ord;
int vis[50], dep[50], par[50];

void dfs(int p) {
    vis[p]=1; ord.push_back(p);
    for (int i : lnk[p]) if (!vis[i]) {
        par[i]=p; dep[i]=dep[p]+1;
        dfs(i); ord.push_back(p);
    }
}

vector<vector<int>> create_map(int n, int m, vector<int> a, vector<int> b) {
    for (int i=1; i<=n; i++) lnk[i].clear(), vis[i]=dep[i]=par[i]=0, ord.clear();
    for (int i=0; i<m; i++) lnk[a[i]].push_back(b[i]), lnk[b[i]].push_back(a[i]);
    dfs(1);
    vector<vector<int>> ret(2*n-1, vector<int>(2*n-1, 0));

    for (int p=0, i=0; p<2*n-1; i++, p++) {
        for (int x=min(i, 2*n-2), y=i-x; 0<=x&&x<n*2-1&&0<=y&&y<n*2-1; x--, y++)
            ret[x][y]=ord[p];

        vector<int> tp;
        for (int j : lnk[ord[p]]) if (dep[j]<dep[ord[p]] && par[ord[p]]!=j) tp.push_back(j);
        lnk[ord[p]]=tp;
        if (!lnk[ord[p]].size()) continue;

        i++;
        for (int x=min(i, 2*n-2), y=i-x; 0<=x&&x<n*2-1&&0<=y&&y<n*2-1; x--, y++) {
            if (lnk[ord[p]].size()) {ret[x][y]=lnk[ord[p]].back(); lnk[ord[p]].pop_back();}
            else ret[x][y]=ord[p];
        }

        i++;
        for (int x=min(i, 2*n-2), y=i-x; 0<=x&&x<n*2-1&&0<=y&&y<n*2-1; x--, y++)
            ret[x][y]=ord[p];
    }
    for (vector<int>& i : ret) for (int& j : i) j=max(j, 1);

    return ret;
}
