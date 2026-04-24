#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;

int n, D, G;
int deg[303030];
vector<array<int, 2>> l;

signed main(){
    fastio;

    cin >> n;
    for (int i=1; i<n; i++) {
        int a, b; cin >> a >> b;
        l.push_back({a, b});
        deg[a]++; deg[b]++;
    }

    for (int i=1; i<=n; i++) G+=deg[i]*(deg[i]-1)*(deg[i]-2)/6;
    for (array<int, 2> i : l) D+=(deg[i[0]]-1)*(deg[i[1]]-1);
    if (D>G*3) cout << "D";
    else if (D<G*3) cout << "G";
    else cout << "DUDUDUNGA";

    return 0;
}
