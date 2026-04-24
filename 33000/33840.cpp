#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, inf=1e18;

int N, sz[101010];
vector<int> lnk[101010];
void dfs(int p, int x){sz[p]=1; for (int i : lnk[p]) if (i!=x) dfs(i, p), sz[p]+=sz[i];}
int gc(int p, int x) {for (int i : lnk[p]) if (i!=x && sz[i]>N/2) return gc(i, p); return p;}
void ch(int p, int x) {for (int i : lnk[p]) if (i!=x) {if (sz[i]*2>sz[p]) {cout << -1; exit(0);} ch(i, p);}}

signed main() {
    fastio;

    cin >> N;
    for (int i=1; i<N; i++) {
        int a, b; cin >> a >> b;
        lnk[a].push_back(b); lnk[b].push_back(a);
    }
    dfs(1, 0); int p=gc(1, 0);
    dfs(p, 0); ch(p, 0);
    for (int i=1; i<=N; i++) for (int j : lnk[i]) if (i<j) cout << i << " " << j << "\n";

    return 0;
}
