#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=4e18;

int n, m;
vector<int> lnk[101010], rlnk[101010], slnk[101010], srlnk[101010];
int vis[101010], rvis[101010], scl[101010], lor[101010];
array<int, 2> dist[101010], dvis[101010];
vector<int> dor;
vector<vector<int>> scc;

void dfs(int p){
    vis[p]=1;
    for(int i : lnk[p]) if(!vis[i]) dfs(i);
    dor.push_back(p);
}

void rdfs(int p){
    rvis[p]=1;
    for(int i : rlnk[p]) if(!rvis[i]) rdfs(i);
    scc.back().push_back(p);
}

bool Find(vector<int>& v){
    for(int i : v) dist[i]={inf, inf}, dvis[i]={0, 0}, lor[i]=-1; dist[v[0]][0]=0;
    queue<array<int, 2>> q; q.push({v[0], 0});
    while(q.size()){
        int p=q.front()[0], x=q.front()[1]; q.pop();
        if(dvis[p][x]++) continue;

        for(int i : slnk[p]){
            dist[i][x^1]=min(dist[i][x^1], dist[p][x]+1);
            q.push({i, x^1});
        }
    }

    if(!dvis[v[0]][1]) return false;

    vector<int> u;
    int p=v[0], x=1;
    while(p!=v[0] || x!=0){
        for(int i : srlnk[p]){
            if(dist[i][x^1]==dist[p][x]-1){
                u.push_back(p);
                p=i; x^=1;
                break;
            }
        }
    } u.push_back(v[0]);

    reverse(u.begin(), u.end());

    vector<int> st;

    for(int i=0; i<u.size(); i++){
        if(lor[u[i]]==-1){
            lor[u[i]]=st.size();
            st.push_back(u[i]);
        }
        else if((st.size()-lor[u[i]])%2==1){
            cout << "1\n";
            cout << (st.size()-lor[u[i]]) <<"\n";
            for(int j=lor[u[i]]; j<st.size(); j++){
                cout << st[j] << "\n";
            }
            return true;
        }
        else{
            while(st.back()!=u[i]){
                lor[st.back()]=-1;
                st.pop_back();
            }
        }
    }

    cout << "1\n";
    cout << st.size() << "\n";
    for(int i : st) cout << i << "\n";

    return true;
}

void solve(){
    cin >> n >> m;

    for(int i=1; i<=n; i++){
        lnk[i].clear(); rlnk[i].clear();
        slnk[i].clear(); srlnk[i].clear();
        vis[i]=rvis[i]=0;
    }
    dor.clear(); scc.clear();

    for(int i=1, a, b; i<=m; i++){
        cin >> a >> b;
        lnk[a].push_back(b);
        rlnk[b].push_back(a);
    }
    for(int i=1; i<=n; i++) if(!vis[i]) dfs(i);
    reverse(dor.begin(), dor.end());
    for(int i : dor) if(!rvis[i]){
        scc.push_back({}); rdfs(i);
        for(int j : scc.back()) scl[j]=scc.size()-1;
    }

    for(int i=1; i<=n; i++) for(int j : lnk[i]) if(scl[i]==scl[j]){
        slnk[i].push_back(j); srlnk[j].push_back(i);
    }

    for(vector<int>& i : scc) if(Find(i)) return;
    cout << "-1\n";
}

signed main(){
    fastio;

    int t; cin >> t;
    while(t--) solve();

	return 0;
}
