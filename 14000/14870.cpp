#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e14;

int n, ans;
int v[1515][1515];
const int X=11;
int u[1515][1<<X+1];

void update(int t, int s, int e, int x) {
    s+=1<<X; e+=1<<X;
    while (s<=e) {
        if (s&1) u[t][s]+=x; ++s>>=1;
        if (~e&1) u[t][e]+=x; --e>>=1;
    }
}

int val(int t, int p) {
    p+=1<<X; int r=0;
    while (p) r+=u[t][p], p>>=1;
    return r;
}

void query(int x, int y, int k) {
    int s=y, e=y;
    v[x][y]+=k;
    for (int i=x; i<=n; i++) {
        while (s<=n && val(i, s)==max(val(i-1, s), val(i, s-1))+v[i][s]) s++;
        e=max(e, min(s, n));
        while (e<n && val(i, e+1)!=max(val(i-1, e+1), val(i, e)+k)+v[i][e+1]) e++;
        if (s>e) break;
        update(i, s, e, k);
        ans+=(e-s+1)*k;
    }
}

signed main() {
    fastio;

    cin >> n;
    for (int i=1; i<=n; i++) for (int j=1; j<=n; j++) cin >> v[i][j];
    for (int i=1; i<=n; i++) for (int j=1; j<=n; j++) {
        update(i, j, j, max(val(i-1, j), val(i, j-1))+v[i][j]);
        ans+=val(i, j);
    }
    cout << ans << "\n";

    for (int i=1; i<=n; i++) {
        string s; int a, b; cin >>s >> a >> b;
        query(a, b, (s=="U")-(s=="D"));
        cout << ans << "\n";
    }

    return 0;
}
