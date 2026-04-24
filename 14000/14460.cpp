#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e7;

int n, k;
array<int, 2> v[101010];

const int X=500;
vector<int> u[500];
int r[101010];

void update(int p, int x) {
    r[p]=x;
    u[p/X].insert(upper_bound(u[p/X].begin(), u[p/X].end(), x), x);
}

int qry1(int s, int e, int x) {
    int ret=0;
    while (s<=e && s%X) ret+=(r[s++]>x);
    while (s<=e && (e+1)%X) ret+=(r[e--]>x);
    while (s<=e) ret+=u[s/X].end()-upper_bound(u[s/X].begin(), u[s/X].end(), x), s+=X;
    return ret;
}
int qry2(int s, int e, int x) {
    int ret=0;
    while (s<=e && s%X) {if (r[s]) ret+=(r[s]<x); s++;}
    while (s<=e && (e+1)%X) {if (r[e]) ret+=(r[e]<x); e--;}
    while (s<=e) ret+=lower_bound(u[s/X].begin(), u[s/X].end(), x)-u[s/X].begin(), s+=X;
    return ret;
}

signed main() {
    fastio;

    cin >> n >> k;
    for (int i=1; i<=n; i++) {int a; cin >> a; v[a][0]=i;}
    for (int i=1; i<=n; i++) {int a; cin >> a; v[a][1]=i;}

    int ans=0;
    for (int i=k+2; i<=n; i++) {
        update(v[i-k-1][0], v[i-k-1][1]);
        ans+=qry1(1, v[i][0]-1, v[i][1]);
        ans+=qry2(v[i][0]+1, n, v[i][1]);
    }
    cout << ans << "\n";

    return 0;
}
