#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e10;

int n, k;
int sp[1010101][20];

signed main() {
    fastio;

    cin >> n >> k;
    for (int i=1; i<=n; i++) sp[i][0]=-1;
    for (int i=1; i<=k; i++) {
        int a, b; cin >> a >> b;
        sp[a][0]=max(sp[a][0], (b-a+n)%n);
    }

    for (int j=0; j<=1; j++) for (int i=1; i<=n; i++) sp[i%n+1][0]=max(sp[i%n+1][0], sp[i][0]-1);
    for (int i=1; i<=n; i++) if (sp[i][0]==-1){cout << "impossible"; return 0;}

    for (int j=1; j<20; j++) for (int i=1; i<=n; i++) sp[i][j]=sp[i][j-1]+1+sp[(i+sp[i][j-1])%n+1][j-1];

    int ans=inf;
    for (int p=1; p<=n; p++) {
        int s=p, d=0, ret=0;
        for (int i=19; i>=0; i--) if (d+sp[s][i]+1<n) {
            d+=sp[s][i]+1; ret+=1<<i; s=(s+sp[s][i])%n+1;
        }
        ans=min(ans, ret+1);
    }
    cout << ans;

    return 0;
}
