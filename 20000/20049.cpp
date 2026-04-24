#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
const int mod=1e9+7, inf=2e18;

const int MX=505050;

int N, K, D[MX], M[MX];
vector<int> lnk[MX], ans;

int dfs(int p, int x) {
    M[p]=-1;
    int fl=!D[p];
    for (int i : lnk[p]) if (i!=x) fl|=dfs(i, p), M[p]=max(M[p], M[i]-1);
    if (M[p]==D[p]) fl=0;
    if (fl && D[x]<=D[p]) ans.push_back(p), M[p]=D[p], fl=0;
    return fl;
}

signed main() {
    fastio;

    cin >> N >> K;
    for (int i=1; i<N; i++) {
        int a, b; cin >> a >> b;
        lnk[a].push_back(b); lnk[b].push_back(a);
    }

    fill(D+1, D+N+1, inf);
    queue<int> q;
    for (int i=1, x; i<=K; i++) cin >> x, q.push(x), D[x]=0;
    while (q.size()) {
        int p=q.front(); q.pop();
        for (int i : lnk[p]) if (D[i]==inf) D[i]=D[p]+1, q.push(i);
    }
    dfs(1, 0);
    cout << ans.size() << "\n";
    for (int i : ans) cout << i << " ";

    return 0;
}
