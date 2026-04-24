#include "bits/stdc++.h"
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=998244353, inf=1e18;

int N;
array<int, 2> V[101010];
vector<int> lnk[101010];
map<int, int> mp;

void dfs(int p, int x, int d) {
    for (int i : lnk[p]) if (i!=x) {
        mp[d?p*mod+i:i*mod+p]=1;
        dfs(i, p, d^1);
    }
}

signed main(){
    fastio;

    cin >> N;
    for (int i=1; i<N; i++) {
        int a, b; cin >> a >> b; V[i]={a, b};
        lnk[a].push_back(b); lnk[b].push_back(a);
    }
    dfs(1, 0, 0);
    for (int i=1; i<N; i++) cout << mp[V[i][0]*mod+V[i][1]] << "\n";

    return 0;
}
