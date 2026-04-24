#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e17;

int n, m;
vector<int> lnk[110];

int vis[110];
int dep[110], P[110];
int deg[110], ef[110];

void dfs(int p) {
    vis[p]=1;
    for (int i : lnk[p]) if (!vis[i]) {
        dep[i]=dep[p]+1; P[i]=p; dfs(i);
    }
}

void Line(int rt) {
    cout << n*2 << "\n";
    for (int i=0; i<n*2; i++) {
        for (int x=0; x<n; x++) {
            int c;
            if (dep[x]%2==i%2) c=x;
            else if (x==rt) c=rt;
            else c=P[x];
            cout << c << " ";
        }
        cout << "\n";
    }
}

signed main() {
    fastio;

    cin >> n >> m;

    for (int i=0; i<m; i++) {
        int a, b; cin >> a >> b;
        lnk[a].push_back(b);
        lnk[b].push_back(a);
    }

    P[0]=-1; dfs(0);

    int rt=max_element(dep, dep+n)-dep;
    for (int i=0; i<n; i++) vis[i]=0, P[i]=-1;
    dep[rt]=0; dfs(rt);

    if (*max_element(dep, dep+n)==n-1) {
        Line(rt); return 0;
    }

    int u=rt;
    for (int i=0; i<n; i++) if (P[i]!=-1) deg[P[i]]++;
    for (int i=0; i<n; i++) if (dep[i]>dep[u] && deg[i]>1) u=i;

    int f=P[u];
    for (int i : lnk[f]) ef[i]=1;

    int v=-1;
    for (int i=0; i<n; i++) if (P[i]==u && (v==-1 || !ef[i])) v=i;

    vector<int> pth;

    for (int i=v;;) {
        int j=-1;
        for (int x : lnk[i]) if (P[x]==i){j=x; break;}
        if (j==-1) break;
        i=j; pth.push_back(i);
    }

    for (int i=0; i<n; i++) vis[i]=0;
    dep[v]=0;
    for (int i : pth) vis[i]=1;

    swap(lnk[v][0], *find(lnk[v].begin(), lnk[v].end(), u));
    if (!ef[v]) swap(lnk[u][0], *find(lnk[u].begin(), lnk[u].end(), f));
    else partition(lnk[u].begin(), lnk[u].end(), [&](int i){return P[i]==u;});

    for (int i=0; i<n; i++) P[i]=-1; dfs(v);
    for (int i=0; i<pth.size(); i++) {
        dep[pth[i]]=i+1;
        P[pth[i]]=i?pth[i-1]:v;
    }

    cout << 6*n << "\n";
    for (int i=0; i<6*n; i++) {
        for (int x=0; x<n; x++) {
            int c=0;
            if (i%3==0) {if (dep[x]%2==1 && (pth.size()==0 || x!=pth[0])) c=P[x]; else c=x;}
            else if (i%3==1) {if (x==v) c=u; else if (dep[x]%2==0) c=P[x]; else c=x;}
            else {if (pth.size()!=0 && x==pth[0]) c=v; else c=x;}
            cout << c << " ";
        }
        cout << "\n";
    }

    return 0;
}
