#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e17;

set<int> ll[1010101];

int N, sz[1010101], a[1010101], b[1010101], X[1010101];

int crs(array<int, 3> a, array<int, 3> b) {
    double ret=(a[2]-b[2]+0.0)/(b[1]-a[1]);
    return ceil(ret);
}

void dfs(int p, int x) {
    if (ll[p].find(x)!=ll[p].end()) ll[p].erase(ll[p].find(x));

    if (ll[p].size()==0) {a[p]=(N-1)*(N-2)/2, sz[p]=X[p]; return;}
    sz[p]=X[p]; a[p]=b[p]=inf;
    vector<array<int, 2>> ct;
    for (int c : ll[p]) dfs(c, p), sz[p]+=sz[c], a[p]=min(a[p], a[c]);
    for (int c : ll[p]) {
        b[p]=min(b[p], b[c]+(sz[p]-sz[c])*(sz[p]-sz[c]-1)/2);
        ct.push_back({sz[c], sz[c]*(sz[c]+1)/2-N*sz[c]+b[c]});
    }

    sort(ct.begin(), ct.end());
    reverse(ct.begin(), ct.end());

    vector<array<int, 3>> st={{-inf, N, N*N}};

    for(array<int, 2> i : ct) {
        array<int, 3> up=*prev(lower_bound(st.begin(), st.end(), array{i[0], -inf, inf}));
        a[p]=min(a[p], up[1]*i[0]+i[1]+up[2]+N*(N-1)/2);
        array<int, 3> tp={0, i[0], i[1]};
        while (st.size()>=2 && (st.back()[1]==tp[1] || crs(st[st.size()-2], st.back())>=crs(st.back(), tp))) st.pop_back();
        tp[0]=crs(st.back(), tp); st.push_back(tp);
    }
}

vector<int> lnk[1010101];
int g[1010101];
int Find(int x){return g[x]==x?x:g[x]=Find(g[x]);}
void Union(int a, int b){g[Find(a)]=Find(b);}

int P[1010101];
void dfs(int p) {
    for (int i : lnk[p]) {
        if (P[i]==-1) P[i]=p, dfs(i);
        else if (P[i]==p) Union(i, p);
        else if (i!=P[p]) while (Find(p)!=Find(i)) Union(p, P[Find(p)]);
    }
}

long long max_diversity(signed n, signed M, vector<signed> U, vector<signed> V) {
    for (int i=0; i<M; i++) {
        lnk[U[i]].push_back(V[i]);
        lnk[V[i]].push_back(U[i]);
    } N=n;

    for (int i=0; i<N; i++) g[i]=i;
    fill(P+1, P+N, -1); dfs(0);

    for (int i=0; i<N; i++) for (int j : lnk[i]) if (Find(i)!=Find(j))
        ll[Find(i)].insert(Find(j));

    for (int i=0; i<N; i++) X[Find(i)]++;
    for (int i=0; i<N; i++) if (X[i]==N) return 0;
    int p=0;
    for (int i=0; i<N; i++) if (Find(i)==i && lnk[i].size()>=2) p=i;
    dfs(p, -1);
    return N*(N-1)/2-a[p];
}
