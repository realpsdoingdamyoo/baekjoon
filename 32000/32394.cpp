#include <iostream>
#include <vector>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=9e18;

signed N, M, C[1010];
long long R;
vector<signed> g[1010];
signed v(signed a){return g[a].size()*N+a;}

signed main(){
    fastio;

    cin >> N >> M;
    for (int i=1; i<=M; i++) {
        signed a, b; cin >> a >> b;
        g[a].push_back(b); g[b].push_back(a);
    }

    for (signed i=1; i<=N; i++) {
        for (signed j : g[i]) if (v(i)>v(j)) for (signed k : g[j]) if (v(i)>v(k)) R+=C[k]++;
        for (signed j : g[i]) if (v(i)>v(j)) for (signed k : g[j]) if (v(i)>v(k)) C[k]--;
        R%=mod;
    }
    cout << R;

    return 0;
}
