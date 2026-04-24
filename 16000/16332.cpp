#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=4e18;

int n, q;

int v[2][1<<20];
int seg[2][1<<21];
int clr[2][21];

void update(int t, int p, int x) {
    p+=1<<n; int lv=n;
    while (p) {
        clr[t][lv]-=(seg[t][p]==0 || seg[t][p]==1<<(n-lv));
        seg[t][p]+=x;
        clr[t][lv]+=(seg[t][p]==0 || seg[t][p]==1<<(n-lv));
        lv--; p>>=1;
    }
}

signed main() {
    fastio;

    cin >> n >> q;
    for (int i=0; i<=n; i++) clr[0][i]=clr[1][i]=1<<i;

    for (int i=1; i<=q; i++) {
        int a, b; cin >> a >> b;
        v[a][b-1]^=1;
        update(a, b-1, v[a][b-1]*2-1);
        int ret=4LL<<n*2;
        for (int j=0; j<=n; j++) {
            ret+=(1LL<<j*2)-clr[0][j]*clr[1][j]*4;
        }
        cout << ret << "\n";
    }


    return 0;
}
