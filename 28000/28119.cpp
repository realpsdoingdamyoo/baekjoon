#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e15;

int n, m, s;
vector<array<int, 3>> vec;

int g[2020];
int Find(int x){return x==g[x]?x:g[x]=Find(g[x]);}
int Union(int a, int b){a=Find(a); b=Find(b); g[a]=b; return a!=b;}

signed main() {
    fastio;

    cin >> n >> m >> s;
    for (int i=1; i<=m; i++) {
        int a, b, c; cin >> a >> b >> c;
        vec.push_back({c, a, b});
    }
    sort(vec.begin(), vec.end());
    for (int i=1; i<=n; i++) g[i]=i;

    int ans=0;
    for (array<int, 3> i : vec) {
        ans+=i[0]*Union(i[1], i[2]);
    }
    cout << ans;

    return 0;
}
