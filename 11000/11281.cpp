#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;

int N, M;
vector<int> lnk[20202], rlnk[20202], st;

int vis[20202], scc[20202], pv;
void dfs(int p) {
    vis[p]=1;
    for (int i : lnk[p]) if (!vis[i]) dfs(i);
    st.push_back(p);
}
void rdfs(int p) {
    scc[p]=pv;
    for (int i : rlnk[p]) if (!scc[i]) rdfs(i);
}

int Not(int x){return x>N?x-N:x+N;}
signed main(){
    fastio;

    cin >> N >> M;
    for (int i=1; i<N*2; i++) lnk[i].clear(), scc[i]=0;
    pv=0;

    for (int i=1; i<=M; i++) {
        int a, b; cin >> a >> b;
        a=a<0?-a:a+N; b=b<0?-b:b+N;
        lnk[Not(a)].push_back(b); lnk[Not(b)].push_back(a);
        rlnk[a].push_back(Not(b)); rlnk[b].push_back(Not(a));
    }

    for (int i=1; i<=N*2; i++) if (!vis[i]) dfs(i);
    reverse(st.begin(), st.end());
    for (int i : st) if (!scc[i]) pv++, rdfs(i);
    for (int i=1; i<=N; i++) if (scc[i]==scc[i+N]) {cout << "0"; return 0;}
    cout << "1\n";
    for (int i=1; i<=N; i++) cout << (scc[i]<scc[i+N]) << " ";

    return 0;
}
