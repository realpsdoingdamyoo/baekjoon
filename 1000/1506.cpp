#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e17;

int N, e, cst[110], ans;
vector<int> edge[110], redge[110];
bool vsd[110], rvsd[110];
vector<int> vseq;
vector<int> scc;

void dfs(int pnt){
    vsd[pnt]=true;
    for(int i : edge[pnt]) if(!vsd[i]) dfs(i);
    vseq.push_back(pnt);
}

void rdfs(int pnt){
    rvsd[pnt]=true;
    for(int i : redge[pnt]) if(!rvsd[i]) rdfs(i);
    scc.push_back(pnt);
}

signed main(){
    fastio;

    cin >> N;
    for(int i=0; i<N; i++) cin >> cst[i];

    for(int i=0; i<N; i++){
        string s; cin >>s;
        for(int j=0; j<N; j++){
            if(s[j]=='1'){
                edge[i].push_back(j);
                redge[j].push_back(i);
            }
        }
    }

    for(int i=0; i<N; i++) if(!vsd[i]) dfs(i);

    while(vseq.size()) {
        int p=vseq.back(); vseq.pop_back();
        if(rvsd[p]) continue;
        scc.clear();
        rdfs(p);
        int c=inf;
        for(int i : scc) c=min(c, cst[i]);
        ans+=c;
    }
    cout << ans;

    return 0;
}
