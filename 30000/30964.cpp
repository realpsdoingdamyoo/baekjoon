#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e17;

int N;
int g[1010101], c[1010101], v[1010101], ans;
int Find(int x){return g[x]==x?x:Find(g[x]);}

signed main() {
    fastio;

    cin >> N;
    for (int i=1; i<=1000000; i++) g[i]=i;
    for (int i=1, pt=0; i<=N; i++) {
        int a, b; cin >> a >> b;
        if (a==b) ans-=(a<pt)*c[a]*!v[a], v[a]=1;
        a=Find(a); b=Find(b); if (a<b) swap(a, b);
        if (a==b) c[a]=1;
        else g[b]=a, c[a]|=c[b], c[b]=1;
        while (c[pt]) ans+=c[pt]*!v[pt], pt++;
        cout << ans+!v[pt] << "\n";
    }

    return 0;
}
