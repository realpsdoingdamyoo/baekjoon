#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e17;

int N, M;
int A[505050], CN[505050], X[505050], C[505050], U[505050];
vector<int> lnk[505050];
vector<array<int, 3>> vec;

int sz[505050];

void gets(int p, int x) {
    sz[p]=1;
    for (int i : lnk[p]) if (i!=x) gets(i, p), sz[p]+=sz[i];
}

int getc(int p, int x, int s) {
    for (int i : lnk[p]) if (i!=x && sz[i]>s/2) return getc(i, p, s);
    return p;
}

int ans=0;
array<int, 2> dfs(int p, int x) {
    array<int, 2> r={1, 0};
    for (int i : lnk[p]) if (i!=x) {
        array<int, 2> s=dfs(i, p);
        ans+=r[0]*s[0]+r[0]*s[1]+r[1]*s[0];
        r[0]+=s[0]; r[1]+=s[0]+s[1];
    }
    return r;
}

signed main() {
    fastio;

    cin >> N >> M;
    for (int i=1; i<=M; i++) cin >> A[i];
    for (int i=1; i<=M; i++) cin >> CN[i];
    for (int i=1; i<=N-M; i++) {
        int x, u, v; cin >> x >> u >> v;
        X[u]=X[v]=x; U[x]=1; lnk[u].push_back(v); lnk[v].push_back(u);
    }

    for (int i=1, p=1; i<=N; i++) if (!sz[i]) {
        if (X[i]==0) while (U[p]) p++; X[i]=p++;
        gets(i, 0); C[X[i]]=getc(i, 0, sz[i]);
        vec.push_back({A[X[i]], CN[X[i]], C[X[i]]});
    }
    sort(vec.begin(), vec.end());
    reverse(vec.begin(), vec.end());

    for (int i=0, p=1; i<M; i++) {
        while (vec[i][0]--) {
            lnk[vec[i][2]].push_back(vec[p][2]);
            lnk[vec[p][2]].push_back(vec[i][2]);
            vec[p][0]--; p++;
        }
    }

    dfs(1, 0);

    cout << ans;

    return 0;
}
