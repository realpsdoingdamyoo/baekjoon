#include <bits/stdc++.h>
using namespace std;
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e17;

int n;
vector<int> lnk[202020];
vector<int> rlnk[202020];
int vis[202020], rvis[202020];

int psc, scc[202020];
vector<int> st;
int NOT[202020];

void dfs(int p) {
    vis[p]=1;
    for (int i : lnk[p]) if (!vis[i]) dfs(i);
    st.push_back(p);
}
void rdfs(int p, int c) {
    rvis[p]=1; scc[p]=c;
    for (int i : rlnk[p]) if (!rvis[i]) rdfs(i, c);
}

array<int, 2> v[101010];
array<int, 2> P[202020];
vector<int> adj[202020];

int RET[202020];
bool sccfind() {
    for (int i=1; i<=n*2; i++) if (!vis[i]) dfs(i);
    reverse(st.begin(), st.end());
    for (int i : st) if (!rvis[i]) rdfs(i, ++psc);
    for (int i=1; i<=n*2; i++) if (scc[i]==scc[NOT[i]]) return false;

    for (int i=1; i<=n*2; i++) RET[i]=-1;
    vector<array<int, 2>> ts;
    for (int i=1; i<=n*2; i++) ts.push_back({scc[i], i});
    sort(ts.begin(), ts.end());
    for (array<int, 2> i : ts) {
        if (RET[i[1]]==-1) {
            RET[i[1]]=0; RET[NOT[i[1]]]=1;
        }
    }
    return true;
}

void DFS(int p, int pre) {
    for (int i : adj[p]) if (i!=pre) {
        DFS(i, p);
        lnk[i].push_back(p);
        lnk[NOT[p]].push_back(NOT[i]);
        rlnk[p].push_back(i);
        rlnk[NOT[i]].push_back(NOT[p]);
    }
}

bool solve(int p) {
    for (int i=1; i<=n*2; i++) {lnk[i].clear(); rlnk[i].clear(); vis[i]=rvis[i]=0;}
    DFS(p, 0);

    if (!sccfind()) return false;
    return true;
}

vector<int> meeting(vector<int> C, vector<int> U, vector<int> V) {
    n=C.size()/2;
    for(int i=1; i<=n*2; i++){
        lnk[i].clear(); rlnk[i].clear();
        vis[i]=0; rvis[i]=0;
        scc[i]=0; NOT[i]=0;
        adj[i].clear();
        P[i]={0, 0};
        v[i/2]={0, 0};
        RET[i]=-1;
    }
    psc=0; st.clear();


    for (int i=0; i<n*2; i++) {
        if (v[C[i]][0]) v[C[i]][1]=i+1;
        else v[C[i]][0]=i+1;
        P[i+1]={C[i], i+1==v[C[i]][1]};
    }
    for (int i=1; i<=n; i++) {
        NOT[v[i][0]]=v[i][1];
        NOT[v[i][1]]=v[i][0];
    }

    for (int i=0; i<U.size(); i++) {
        adj[U[i]].push_back(V[i]);
        adj[V[i]].push_back(U[i]);
    }

    if (solve(v[1][0])) {
        vector<int> ret;
        for (int j=1; j<=n*2; j++) {
            if (RET[j]) ret.push_back(j);
        }
        return ret;
    }
    if (solve(v[1][1])) {
        vector<int> ret;
        for (int j=1; j<=n*2; j++) {
            if (RET[j]) ret.push_back(j);
        }
        return ret;
    }

    return {};
}

int _N;
vector<int> _C, _U, _V;

void solve(){
    _C.clear(); _U.clear(); _V.clear();
    cin >> _N;
    for(int i=1; i<=_N*2; i++){
        int a; cin >> a;
        _C.push_back(a);
    }
    for(int i=1; i<_N*2; i++){
        int a, b; cin >> a >> b;
        _U.push_back(a);
        _V.push_back(b);
    }
    vector<int> ANS=meeting(_C, _U, _V);
    if(ANS.size()){
        for(int i : ANS) cout << i << " ";
        cout << "\n";
    }
    else cout << "-1\n";
}

int main(){
    fastio;
    int t; cin >> t;
    while(t--) solve();
}
