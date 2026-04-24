#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;

int n, m;
int ed[110][110], deg[110];
int XOR[110][110];

int g[110];
int Find(int x){return g[x]==x?x:Find(g[x]);}
int Union(int a, int b) {
    int chk=(Find(a)!=Find(b));
    g[Find(a)]=Find(b);
    return chk;
}

vector<int> lnk[110];
int P[110], vis[110];
void dfs(int p, int pre) {
    vis[p]=1;
    for (int i : lnk[p]) if (i!=pre) P[i]=p, dfs(i, p);
}

int CN[110], cn=0;
int V[110], E[110], RE[110];
vector<int> un[110];

signed main() {
    fastio;

    cin >> n >> m;
    for (int i=1; i<=m; i++) {
        int a, b; cin >> a >> b;
        ed[a][b]=ed[b][a]=1;
        deg[a]++; deg[b]++;
    }

    for (int i=1; i<=n; i++) g[i]=i;
    for (int i=1; i<=n; i++) for (int j=i+1; j<=n; j++) if (!ed[i][j]) {
        if (Union(i, j)) {
            lnk[i].push_back(j);
            lnk[j].push_back(i);
        }
    }
    for (int i=1; i<=n; i++) if (!vis[i]) dfs(i, 0), P[i]=i;

    for (int i=1; i<=n; i++) if (deg[i]%2) {
        CN[Find(i)]++;
        int x=i;
        while (P[x]!=x) XOR[P[x]][x]^=1, XOR[x][P[x]]^=1, x=P[x];
    }
    //for (int i=1; i<=n; i++) cout << P[i] << " "; cout << "\n";
    for (int i=1; i<=n; i++) if (CN[i]%2) {cout << "-1"; return 0;}

    for (int i=1; i<=n; i++) g[i]=i;
    for (int i=1; i<=n; i++) for (int j=i+1; j<=n; j++) if (ed[i][j] || XOR[i][j]) Union(i, j);

    for (int i=1; i<=n; i++) for (int j=i+1; j<=n; j++) if (ed[i][j] || XOR[i][j]) {
        int x=Find(i); E[x]+=ed[i][j]; RE[x]+=XOR[i][j];
    }
    for (int i=1; i<=n; i++) V[Find(i)]++, un[Find(i)].push_back(i);

    //for (int i=1; i<=n; i++) cout << Find(i) << " "; cout << "\n";

    vector<array<int, 4>> vec;
    for (int i=1; i<=n; i++) if (g[i]==i) vec.push_back({i, V[i], E[i], RE[i]});

    /*for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) cout << (ed[i][j]+XOR[i][j]) << " ";
        cout << "\n";
    }*/

    /*for (int i=1; i<=n; i++) if (g[i]==i) {
        cout << i << " " << V[i] << " " << E[i] << " " << RE[i] << "\n";
    }*/

    while (vec.size()>1) {
        sort(vec.begin(), vec.end(), [&](array<int, 4> a, array<int, 4> b){return a[1]>b[1];});
        int sz=vec.size();

        if (sz==2 && vec[sz-1][1]==1 && vec[sz-2][1]*(vec[sz-2][1]-1)/2==vec[sz-2][2]) {
            cout << "-1"; return 0;
        }

        if (vec[sz-2][1]>=2 && vec[sz-1][1]>=2) {
            int a=vec[sz-2][0], b=vec[sz-1][0];

            XOR[un[a][0]][un[b][0]]=XOR[un[b][0]][un[a][0]]=1;
            XOR[un[a][0]][un[b][1]]=XOR[un[b][1]][un[a][0]]=1;
            XOR[un[a][1]][un[b][0]]=XOR[un[b][0]][un[a][1]]=1;
            XOR[un[a][1]][un[b][1]]=XOR[un[b][1]][un[a][1]]=1;

            array<int, 4> A=vec[sz-2], B=vec[sz-1];
            for (int i : un[b]) un[a].push_back(i); un[b].clear();
            array<int, 4> r={A[0], A[1]+B[1], A[2]+B[2], A[3]+B[3]+4};
            vec.pop_back(); vec.pop_back(); vec.push_back(r);
        }
        else if (vec[sz-2][1]>=2 && vec[sz-2][3]) {
            int a=vec[sz-2][0], b=vec[sz-1][0];
            for (int i : un[a]) for (int j : un[a]) if (XOR[i][j]) {
                XOR[i][j]=XOR[j][i]=0; XOR[i][b]=XOR[b][i]=1; XOR[b][j]=XOR[j][b]=1;
                goto _out1;
            }
            _out1:
            array<int, 4> A=vec[sz-2], B=vec[sz-1];
            for (int i : un[b]) un[a].push_back(i); un[b].clear();
            array<int, 4> r={A[0], A[1]+B[1], A[2]+B[2], A[3]+B[3]+1};
            vec.pop_back(); vec.pop_back(); vec.push_back(r);
        }
        else if (vec[sz-2][1]>=2 && vec[sz-2][1]*(vec[sz-2][1]-1)/2!=vec[sz-2][2]) {
            int a=vec[sz-2][0], b=vec[sz-1][0];
            for (int i : un[a]) for (int j : un[a]) if (i!=j && !ed[i][j] && !XOR[i][j]) {
                XOR[i][j]=XOR[j][i]=1; XOR[i][b]=XOR[b][i]=1; XOR[b][j]=XOR[j][b]=1;
                goto _out2;
            }
            _out2:
            array<int, 4> A=vec[sz-2], B=vec[sz-1];
            for (int i : un[b]) un[a].push_back(i); un[b].clear();
            array<int, 4> r={A[0], A[1]+B[1], A[2]+B[2], A[3]+B[3]+3};
            vec.pop_back(); vec.pop_back(); vec.push_back(r);
        }
        else {
            int a=vec[sz-3][0], b=vec[sz-2][0], c=vec[sz-1][0];
            XOR[a][b]=XOR[b][a]=1; XOR[b][c]=XOR[c][b]=1; XOR[c][a]=XOR[a][c]=1;

            array<int, 4> A=vec[sz-3], B=vec[sz-2], C=vec[sz-1];
            for (int i : un[b]) un[a].push_back(i); un[b].clear();
            for (int i : un[c]) un[a].push_back(i); un[c].clear();
            array<int, 4> r={A[0], A[1]+B[1]+C[1], A[2]+B[2]+C[2], A[3]+B[3]+C[3]+3};
            vec.pop_back(); vec.pop_back(); vec.pop_back(); vec.push_back(r);
        }
    }

    int cnt=0;
    for (int i=1; i<=n; i++) for (int j=i+1; j<=n; j++) if (XOR[i][j]) cnt++;
    cout << cnt << "\n";
    for (int i=1; i<=n; i++) for (int j=i+1; j<=n; j++) if (XOR[i][j]) cout << i << " " << j << "\n";


    return 0;
}
