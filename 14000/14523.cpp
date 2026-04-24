#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=4e10, bnd=1e10;

int n, m, k, q;
vector<array<int, 2>> lnk[202020];
vector<int> child[202020];
bool mstin[202020];

struct NODE{
    int par, dist, col;
} node[202020];

map<int, multiset<int>> pst[202020]; // child / color -> dist_set
map<int, int> mp[202020]; // child / color -> mindist
multiset<array<int, 2>> cst[202020]; // child / {dist, color}
multiset<int> ast;

void MST(){
    priority_queue<array<int, 3>> mpq;
    mpq.push({0, 1, 0});
    while(mpq.size()){
        int d=mpq.top()[0], p=mpq.top()[1], an=mpq.top()[2]; mpq.pop();
        if(mstin[p]) continue;
        mstin[p]=true;
        node[p].par=an; node[p].dist=-d;
        if(an) child[an].push_back(p);
        for(array<int, 2> i : lnk[p])
            mpq.push({-i[1], i[0], p});
    }
}

int cst_top(int p){
    if(cst[p].size()==0) return inf;
    if(cst[p].size()==1 && (*cst[p].begin())[1]==node[p].col) return inf;

    if((*cst[p].begin())[1]==node[p].col) return (*next(cst[p].begin()))[0];
    else return (*cst[p].begin())[0];
}

void init_dfs(int p){
    for(int i : child[p]){
        init_dfs(i);
        pst[p][node[i].col].insert(node[i].dist);
        mp[p][node[i].col]=*pst[p][node[i].col].begin();
    }
    for(pair<int, int> pr : mp[p])
        cst[p].insert({pr.second, pr.first});

    int x=cst_top(p);
    ast.insert(x);
}


void query(int p, int x){
    int a=node[p].par;
    if(a!=0){
        ast.erase(ast.find(cst_top(a)));
        cst[a].erase(cst[a].find({mp[a][node[p].col], node[p].col}));
        pst[a][node[p].col].erase(pst[a][node[p].col].find(node[p].dist));
        if(pst[a][node[p].col].size()==0) pst[a].erase(pst[a].find(node[p].col));
        else{
            mp[a][node[p].col]=*pst[a][node[p].col].begin();
            cst[a].insert({mp[a][node[p].col], node[p].col});
        }
    }

    ast.erase(ast.find(cst_top(p)));
    node[p].col=x;
    ast.insert(cst_top(p));

    if(a!=0){
        if(pst[a][node[p].col].size())
            cst[a].erase(cst[a].find({mp[a][node[p].col], node[p].col}));
        pst[a][node[p].col].insert(node[p].dist);
        mp[a][node[p].col]=*pst[a][node[p].col].begin();
        cst[a].insert({mp[a][node[p].col], node[p].col});
        ast.insert(cst_top(a));
    }
}

signed main(){
    fastio;

    cin >> n >> m >> k >> q;
    for(int i=0; i<m; i++){
        int a, b, c; cin >> a >> b >> c;
        lnk[a].push_back({b, c});
        lnk[b].push_back({a, c});
    }

    MST();

    for(int i=1; i<=n; i++) cin >> node[i].col;

    init_dfs(1);

    for(int i=0; i<q; i++){
        int a, b; cin >> a >> b;
        query(a, b);
        cout << *ast.begin() << "\n";
    }

    return 0;
}
