#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
const int mod=1e9+7, MOD=998244353, inf=2e17;

int N;
vector<int> lnk[101010];

int g[101010];
int Find(int x){return g[x]==x?x:g[x]=Find(g[x]);}
void Union(int a, int b){g[Find(a)]=Find(b);}

int P[101010], dep[101010];
void dfs(int p, int x) {for (int i : lnk[p]) if (i!=x) P[i]=p, dep[i]=dep[p]+1, dfs(i, p);}

signed main() {
    fastio;

    cin >> N;
    for (int i=1; i<N; i++) {
        g[i]=i;
        int a, b; cin >> a >> b;
        lnk[a].push_back(b); lnk[b].push_back(a);
    }
    dfs(0, -1);

    vector<array<int, 2>> ln;
    for (int i=1; i<N; i++) {
        int x, y; cin >> x >> y;
        if (P[x]==y) swap(x, y);
        if (P[y]!=x) ln.push_back({x, y});
        else Union(y, x);
    }

    cout << ln.size() << "\n";
    for (array<int, 2> i : ln) {
        int x=Find(i[0]), y=Find(i[1]);
        if (dep[x]<dep[y]) swap(x, y);
        cout << Find(x) << " " << P[Find(x)] << " " << i[0] << " " << i[1] << "\n";
        Union(x, y);
    }

    return 0;
}
