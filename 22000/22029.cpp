#include <bits/stdc++.h>
using namespace std;

vector<int> lnk[220], dsp[220];
int sz[220];
void getsz(int p, int x) {sz[p]=1; for (int i : lnk[p]) if (i!=x) getsz(i, p), sz[p]+=sz[i];}
int getc(int p, int x, int s){for (int i : lnk[p]) if (i!=x && sz[i]>s/2) return getc(i, p, s); return p;}
void dfs(int p, int x, int d){dsp[d].push_back(p); for (int i : lnk[p]) if (i!=x) dfs(i, p, d+1);}
vector<pair<int, int>> encode_map(int N, int K, int &X, vector<pair<int, int>> E) {
    for (int i=0; i<=N; i++) lnk[i].clear(), dsp[i].clear();
    for (pair<int, int> i : E) lnk[i.first].push_back(i.second), lnk[i.second].push_back(i.first);
    getsz(1, 0); X=getc(1, 0, sz[1]); dfs(X, 0, 0);
    vector<pair<int, int>> ret;
    for (int i=1; i<=N/2; i++) if (dsp[i].size()) for (int j : dsp[i])
        if (j!=dsp[i][0] && ret.size()<K) ret.push_back({dsp[i][0], j});
    return ret;
}

vector<pair<int, int>> decode_map(int N, int K, int X, vector<pair<int, int>> E) {
    for (int i=0; i<=N; i++) lnk[i].clear();
    for (pair<int, int> i : E) lnk[i.first].push_back(i.second), lnk[i.second].push_back(i.first);
    queue<int> q; q.push(X);
    int dis[220]={}, vis[220]={}; fill(dis+1, dis+N+1, N+1); dis[X]=0;

    while (q.size()) {
        int p=q.front(); q.pop();
        if (vis[p]++) continue;
        for (int i : lnk[p]) if (dis[i]>dis[p]) dis[i]=dis[p]+1, q.push(i);
    }
    vector<pair<int, int>> ret;
    for (pair<int, int> i : E) if (dis[i.first]!=dis[i.second]) ret.push_back(i);
    return ret;
}
