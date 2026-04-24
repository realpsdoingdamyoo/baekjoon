#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
const int mod=1e9+7, MOD=998244353, inf=2e18;

int n, m;
array<int, 2> v[303030];
vector<int> x;
int sp[606060][20];

int mxs(int s, int e) {
    if (s>=e) return 0;
    int r=0;
    for (int i=19; i>=0; i--) if (sp[s][i]<e) s=sp[s][i]+1, r+=1<<i;
    return r;
}

signed main() {
    fastio;

    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        cin >> v[i][0] >> v[i][1];
        x.push_back(v[i][0]); x.push_back(v[i][1]);
    }
    sort(x.begin(), x.end());
    x.erase(unique(x.begin(), x.end()), x.end());
    for (int i=1; i<=n; i++) {
        v[i][0]=lower_bound(x.begin(), x.end(), v[i][0])-x.begin()+1;
        v[i][1]=lower_bound(x.begin(), x.end(), v[i][1])-x.begin()+1;
    }

    for (int i=1; i<=n*2+1; i++) sp[i][0]=inf;
    for (int j=1; j<20; j++) sp[n*2+1][j]=inf;
    
    for (int i=1; i<=n; i++) sp[v[i][0]][0]=min(sp[v[i][0]][0], v[i][1]);
    for (int i=n*2; i>=1; i--) sp[i][0]=min(sp[i][0], sp[i+1][0]);

    for (int j=1; j<20; j++) {
        for (int i=1; i<=n*2; i++) {
            if (sp[i][j-1]==inf) sp[i][j]=inf;
            else sp[i][j]=sp[sp[i][j-1]+1][j-1];
        }
    }

    while (m--) {
        int x; cin >> x;
        vector<int> u(x);
        vector<array<int, 2>> r;
        for (int& i : u) cin >> i;
        r.push_back({1, v[u[0]][0]});
        for (int i=0; i<x-1; i++) r.push_back({v[u[i]][1]+1, v[u[i+1]][0]});
        r.push_back({v[u[x-1]][1]+1, n*2+1});

        int ans=x;
        for (array<int, 2> i : r) ans+=mxs(i[0], i[1]);
        cout << ans << "\n";
    }

    return 0;
}
