#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2147483647202020;

int n, m, s, e, l;
vector<int> lp;
vector<array<int, 2>> lnk[2020];
vector<array<int, 3>> edge;
int lpord[2020];
vector<int> tree[2][2020];
int par[2][2020], dist[2][2020], vis[2][2020];

void dfs(int t, int p, int pr){
    vis[t][p]=1;
    par[t][p]=pr;
    for(array<int, 2> i : lnk[p]){
        if(lpord[i[0]]>=0 && lpord[p]==-1) continue;
        if(!vis[t][i[0]] && dist[t][i[0]]==i[1]+dist[t][p]){
            tree[t][p].push_back(i[0]);
            dfs(t, i[0], lpord[i[0]]>=0?i[0]:par[t][p]);
        }
    }
}

void dijk_tree(int t){
    for(int i=0; i<l-1; i++) for(array<int, 2>& j : lnk[lp[i]])
        if(j[0]==lp[i+1]) swap(lnk[lp[i]].back(), j);
    for(int i=1; i<=n; i++) dist[t][i]=inf;
    priority_queue<array<int, 2>, vector<array<int, 2>>, greater<array<int, 2>>> pq;

    dist[t][lp[0]]=0; pq.push({0, lp[0]});

    while(pq.size()){
        int d=pq.top()[0], p=pq.top()[1]; pq.pop();
        if(vis[t][p]) continue; vis[t][p]=1;

        for(array<int, 2> i : lnk[p]){
            int np=i[0], nd=i[1]+d;
            if(nd<dist[t][np]){
                dist[t][np]=nd;
                pq.push({nd, np});
            }
        }
    }

    for(int i=1; i<=n; i++) vis[t][i]=0;
    dfs(t, lp[0], lp[0]);

    /*for(int i=1; i<=n; i++){
        cout << i << " " << dist[t][i] << " " << par[t][i] << " ) ";
        for(int j : tree[t][i]) cout << j << " ";
        cout << "\n";
    }
    cout << "\n";*/
}

const int X=12;
int seg[1<<X+1];

void update(int s, int e, int x){
    s+=1<<X; e+=1<<X;
    while(s<=e){
        if(s&1) seg[s]=min(seg[s], x);
        if(~e&1) seg[e]=min(seg[e], x);
        ++s>>=1; --e>>=1;
    }
}

int minp(int p){
    int ret=inf; p+=1<<X;
    while(p) ret=min(seg[p], ret), p>>=1;
    return ret;
}

signed main() {
    fastio;

    cin >> n >> m >> s >> e;
    for(int i=0; i<m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        lnk[a].push_back({b, c});
        lnk[b].push_back({a, c});
        edge.push_back({a, b, c});
        edge.push_back({b, a, c});
    }

    cin >> l; lp.resize(l);
    for(int i=0; i<l; i++) cin >> lp[i];

    for(int i=1; i<=n; i++) lpord[i]=-1;
    for(int i=0; i<l; i++) lpord[lp[i]]=i;

    dijk_tree(0); reverse(lp.begin(), lp.end());
    dijk_tree(1); reverse(lp.begin(), lp.end());

    for(int i=1; i<(1<<X+1); i++) seg[i]=inf;

    for(array<int, 3> e : edge){
        int a=e[0], b=e[1];
        if(lpord[a]>=0 && lpord[b]>=0 && abs(lpord[a]-lpord[b])==1) continue;
        int D=dist[0][a]+dist[1][b]+e[2];

        a=par[0][e[0]]; b=par[1][e[1]];
        if(lpord[a]>lpord[b]) swap(a, b);
        update(lpord[a], lpord[b]-1, D);

    }

    for(int i=0, m=minp(0); i<l-1; i++, m=minp(i)) cout << (m==inf?-1:m) << "\n";

	return 0;
}
