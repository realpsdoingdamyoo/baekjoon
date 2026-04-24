#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e17;

int n, m;
vector<int> lnk[20202];
vector<int> rlnk[20202];
int vis[20202], rvis[20202];

int psc, scc[20202];
vector<int> st;
int NOT(int x){return x>n?x-n:x+n;}

void dfs(int p) {
    vis[p]=1;
    for (int i : lnk[p]) if (!vis[i]) dfs(i);
    st.push_back(p);
}
void rdfs(int p, int c) {
    rvis[p]=1; scc[p]=c;
    for (int i : rlnk[p]) if (!rvis[i]) rdfs(i, c);
}
void sccfind() {
    for (int i=1; i<=n*2; i++) if (!vis[i]) dfs(i);
    reverse(st.begin(), st.end());
    for (int i : st) if (!rvis[i]) rdfs(i, ++psc);
}

signed main() {
    fastio;

    cin >> n >> m;
    for (int i=1; i<=m; i++) {
        int a, b; cin >> a >> b;
        if (a<0) a=n-a;
        if (b<0) b=n-b;
        lnk[NOT(a)].push_back(b);
        lnk[NOT(b)].push_back(a);
        rlnk[a].push_back(NOT(b));
        rlnk[b].push_back(NOT(a));
    }

    sccfind();
    for (int i=1; i<=n; i++) if (scc[i]==scc[NOT(i)]) {
        cout << 0; return 0;
    }
    cout << 1;



    return 0;
}
