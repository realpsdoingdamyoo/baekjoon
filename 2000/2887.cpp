#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e8;

int n, ans;
array<int, 4> v[101010];
vector<array<int, 3>> ed;

int g[101010];
int Find(int x){return g[x]==x?x:g[x]=Find(g[x]);}
int Union(int a, int b) {
    a=Find(a); b=Find(b);
    if (a==b) return 0;
    g[a]=b; return 1;
}

signed main() {
    fastio;

    cin >> n;
    for (int i=1; i<=n; i++){cin >> v[i][0] >> v[i][1] >> v[i][2]; v[i][3]=i;}

    sort(v+1, v+n+1, [&](array<int, 4> a, array<int, 4> b){return a[0]<b[0];});
    for (int i=1; i<n; i++) ed.push_back({v[i+1][0]-v[i][0], v[i][3], v[i+1][3]});
    sort(v+1, v+n+1, [&](array<int, 4> a, array<int, 4> b){return a[1]<b[1];});
    for (int i=1; i<n; i++) ed.push_back({v[i+1][1]-v[i][1], v[i][3], v[i+1][3]});
    sort(v+1, v+n+1, [&](array<int, 4> a, array<int, 4> b){return a[2]<b[2];});
    for (int i=1; i<n; i++) ed.push_back({v[i+1][2]-v[i][2], v[i][3], v[i+1][3]});

    sort(ed.begin(), ed.end(), [&](array<int, 3> a, array<int, 3> b){return a[0]<b[0];});

    for (int i=1; i<=n; i++) g[i]=i;
    for (array<int, 3> i : ed) {
        ans+=Union(i[2], i[1])*i[0];
    }
    cout << ans;


    return 0;
}
