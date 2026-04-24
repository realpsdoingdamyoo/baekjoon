#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e17;

int N, A[202020];
vector<int> lnk[202020];

int sz[202020], ps[202020];
void dfs(int p, int x) {
    sz[p]=1;
    for (int i : lnk[p]) if (i!=x) dfs(i, p), sz[p]+=sz[i];
}

void dfs2(int p, int x, int a, int b) {
    b|=(p==a); ps[p]=b;
    for (int i : lnk[p]) if (i!=x) dfs2(i, p, a, b);
}

void div(vector<int> v, int p, int x, int bt) {
    if (v.size()==1){A[p]=x; return;}
    dfs(p, -1);
    int a=p;
    for (int i : v) if (min(sz[p]-sz[a], sz[a])<min(sz[p]-sz[i], sz[i])) a=i;
    dfs2(p, -1, a, 0);
    int p1, p2;
    for (int i : v) for (int j : lnk[i]) if (ps[i]==0 && ps[j]==1) p1=i, p2=j;
    for (int& i : lnk[p1]) if (i==p2) {swap(i, lnk[p1].back()); lnk[p1].pop_back(); break;}
    for (int& i : lnk[p2]) if (i==p1) {swap(i, lnk[p2].back()); lnk[p2].pop_back(); break;}

    vector<int> lef, rig;
    for (int i : v) (ps[i]?rig:lef).push_back(i);
    div(lef, p, x, bt-1);
    div(rig, p2, A[p1]^(1<<bt), bt-1);
}

signed main() {
    fastio;

    cin >> N;
    for (int i=1; i<N; i++) {
        int a, b; cin >> a >> b;
        lnk[a].push_back(b); lnk[b].push_back(a);
    }

    vector<int> v;
    for (int i=1; i<=N; i++) v.push_back(i);

    div(v, 1, 0, 28);

    for (int i=1; i<=N; i++) cout << A[i] << " ";

    return 0;
}
