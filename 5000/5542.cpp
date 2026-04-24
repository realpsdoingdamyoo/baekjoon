#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2147483647202020;

int n, m, k, q;
vector<array<int, 2>> lnk[101010], ed, que;
int dist[101010], vis[101010], ans[101010];
vector<array<int, 3>> edge;

int g[101010];
vector<array<int, 2>> vec, vvec;

int Find(int a){return g[a]<0?a:Find(g[a]);}

void Union(int a, int b){
    vvec.push_back({a, b});
    a=Find(a); b=Find(b);
    if(a==b){vvec.pop_back(); vec.push_back({0, 0}); vec.push_back({0, 0}); return;}

    if(-g[a]<-g[b]) swap(a, b);
    vec.push_back({a, g[a]});
    vec.push_back({b, g[b]});
    g[a]+=g[b]; g[b]=a;
}

void rollback(){
    if(vec.back()[0]) vvec.pop_back();
    g[vec.back()[0]]=vec.back()[1]; vec.pop_back();
    g[vec.back()[0]]=vec.back()[1]; vec.pop_back();
}

void solve(int s, int e, vector<int> q){
    if(s==e){
        for(int i : q){
            if(Find(que[i][0])==Find(que[i][1])) ans[i]=edge[s-1][0];
            else ans[i]=edge[s][0];
        }
        return;
    }
    vector<int> Lq, Rq;
    int m=s+e>>1;
    for(int i=s; i<=m; i++) Union(edge[i][1], edge[i][2]);

    for(int i : q){
        if(Find(que[i][0])==Find(que[i][1])) Lq.push_back(i);
        else Rq.push_back(i);
    } solve(m+1, e, Rq);
    for(int i=m; i>=s; i--) rollback();
    solve(s, m, Lq);
}

signed main() {
    fastio;

    cin >> n >> m >> k >> q;
    for(int i=1; i<=n; i++) dist[i]=inf, g[i]=-1;

    for(int i=0; i<m; i++){
        int a, b, c; cin >> a >> b >> c;
        lnk[a].push_back({b, c});
        lnk[b].push_back({a, c});
        ed.push_back({a, b});
    }

    priority_queue<array<int, 2>> pq;
    for(int i=0; i<k; i++){
        int a; cin >> a;
        pq.push({0, a});
        dist[a]=0;
    }

    while(pq.size()){
        int p=pq.top()[1], d=-pq.top()[0]; pq.pop();
        if(vis[p]++) continue;
        dist[p]=d;
        for(array<int, 2> i : lnk[p]){
            pq.push({-(d+i[1]), i[0]});
        }
    }

    for(array<int, 2> i : ed) edge.push_back({min(dist[i[0]], dist[i[1]]), i[0], i[1]});
    sort(edge.begin(), edge.end()); reverse(edge.begin(), edge.end());

    vector<int> tsv;
    for(int i=0; i<q; i++){
        int a, b; cin >> a >> b;
        que.push_back({a, b});
        tsv.push_back(i);
    }

    solve(0, edge.size()-1, tsv);

    for(int i=0; i<q; i++) cout << ans[i] << "\n";

    return 0;
}
