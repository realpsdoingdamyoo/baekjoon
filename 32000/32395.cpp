#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=9e18;

int N, M, C[101010], R;
vector<int> g[101010];
int v(int a){return g[a].size()*mod+a;}

signed main(){
    fastio;

    cin >> N >> M;
    for (int i=1; i<=M; i++) {
        int a, b; cin >> a >> b;
        g[a].push_back(b); g[b].push_back(a);
    }

    for (int i=1; i<=N; i++) {
        for (int j : g[i]) if (v(i)>v(j)) for (int k : g[j]) if (v(i)>v(k)) R+=C[k]++;
        for (int j : g[i]) if (v(i)>v(j)) for (int k : g[j]) if (v(i)>v(k)) C[k]--;
        R%=mod;
    }
    cout << R;

    return 0;
}
