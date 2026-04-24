#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;

int N, M;
vector<int> lnk[101010];

int dep[101010], sp[101010][20];
void dfs(int p, int x) {
    for (int& i : lnk[p]) if (i==x) {swap(i, lnk[p].back()); lnk[p].pop_back(); break;}
    for (int i : lnk[p]) {
        sp[i][0]=p; dep[i]=dep[p]+1;
        for (int j=1; j<20; j++) sp[i][j]=sp[sp[i][j-1]][j-1];
        dfs(i, p);
    }
}

int lca(int a, int b) {
    if (dep[a]<dep[b]) swap(a, b);
    for (int i=19; i>=0; i--) if (dep[a]-dep[b]&1<<i) a=sp[a][i];
    for (int i=19; i>=0; i--) if (sp[a][i]!=sp[b][i]) a=sp[a][i], b=sp[b][i];
    return a==b?a:sp[a][0];
}

vector<array<int, 3>> dp[101010];

int D1[101010], D2[101010], sz[101010], S[101010];

void go(int p, int x) {
    for (int i : lnk[p]) go(i, x);
    S[p]+=x;
}

void sol(int p) {
    sz[p]=1;
    for (int& i : lnk[p]) {
        sol(i), D2[p]+=D1[i]; sz[p]+=sz[i];
        if (sz[i]>sz[lnk[p][0]]) swap(lnk[p][0], i);
    }

    int x=lnk[p][0];
    S[p]=S[x]+(D2[x]-D1[x]);
    for (int i : lnk[p]) if (i!=x) go(i, S[p]-(D2[i]-D1[i])-S[i]);

    D1[p]=D2[p];
    for (array<int, 3> i : dp[p]) {
        D1[p]=max(D1[p], i[2]+D2[p]+S[p]*2-S[i[0]]-S[i[1]]);
    }
}

signed main() {
    fastio;

    cin >> N;
    for (int i=1; i<N; i++) {
        int a, b; cin >> a >> b;
        lnk[a].push_back(b); lnk[b].push_back(a);
    }

    dfs(1, -1);

    cin >> M;
    for (int i=1; i<=M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        dp[lca(a, b)].push_back({a, b, c});
    }

    sol(1);
    cout << D1[1];

    return 0;
}
