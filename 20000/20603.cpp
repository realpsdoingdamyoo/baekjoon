#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e9;

#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#pragma GCC target("avx,avx2")

const int MX=500050, M=30;

int N, Q, col[MX];
vector<int> lnk[MX];

int vl[M][MX], in[MX], rin[MX], sz[MX], tp[MX], pr[MX], dep[MX], pv;

void dfs0(int p, int x) {
    sz[p]=1; pr[p]=x;
    for (int& i : lnk[p]) if (i==x) {swap(i, lnk[p].back()); lnk[p].pop_back(); break;}
    for (int& i : lnk[p]) {dfs0(i, p), sz[p]+=sz[i]; if (sz[i]>sz[lnk[p][0]]) swap(lnk[p][0], i);}
}

void dfs1(int p) {
    in[p]=++pv; rin[in[p]]=p;
    for (int i : lnk[p]) dep[i]=dep[p]+1, tp[i]=(i==lnk[p][0]?tp[p]:i), dfs1(i);
}

int seg[M][MX*4];
int build(int t, int p, int s, int e) {
    if (s==e){seg[t][p]=vl[t][col[rin[s]]]; return seg[t][p];}
    int m=s+e>>1;
    seg[t][p]=min(build(t, p<<1, s, m), build(t, p<<1|1, m+1, e));
    return seg[t][p];
}

int update(int t, int p, int s, int e, int x, int y) {
    if (s==e){seg[t][p]=vl[t][y]; return seg[t][p];}
    int m=s+e>>1;
    if (x<=m) seg[t][p]=min(update(t, p<<1, s, m, x, y), seg[t][p<<1|1]);
    else seg[t][p]=min(seg[t][p<<1], update(t, p<<1|1, m+1, e, x, y));
    return seg[t][p];
}

int gmn(int t, int p, int s, int e, int l, int r) {
    if (r<s || e<l) return inf;
    if (l<=s && e<=r) return seg[t][p];
    int m=s+e>>1;
    return min(gmn(t, p<<1, s, m, l, r), gmn(t, p<<1|1, m+1, e, l, r));
}

long long get(int A, int B) {
    long long sum=0;
    for (int t=0; t<M; t++) {
        int ret=inf;
        int a=A, b=B;
        while (tp[a]!=tp[b]) {
            if (dep[tp[a]]<dep[tp[b]]) swap(a, b);
            ret=min(ret, gmn(t, 1, 1, N, in[tp[a]], in[a]));
            a=pr[tp[a]];
        }
        if (dep[a]>dep[b]) swap(a, b);
        ret=min(ret, gmn(t, 1, 1, N, in[a], in[b]));
        sum+=ret;
    }
    return sum;
}

void solve() {
    cin >> N >> Q;
    for (int i=0; i<M; i++) for (int j=1; j<=N; j++) vl[i][j]=1LL*rand()*rand()%mod;
    for (int i=1; i<=N; i++) lnk[i].clear(); pv=0;
    for (int i=1; i<=N; i++) cin >> col[i];
    for (int i=1; i<N; i++) {
        int a, b; cin >> a >> b;
        lnk[a].push_back(b); lnk[b].push_back(a);
    }
    dfs0(1, 0); dfs1(1);
    for (int i=0; i<M; i++) build(i, 1, 1, N);

    int cnt=0;
    while (Q--) {
        int t; cin >> t;
        if (t==2) {
            int a, b, c, d; cin >> a >> b >> c >> d;
            int ans=(get(a^cnt, b^cnt)<get(c^cnt, d^cnt));
            cnt+=ans; cout << (ans?"Yes\n":"No\n");
        }
        else {
            int x, y; cin >> x >> y;
            for (int i=0; i<M; i++) update(i, 1, 1, N, in[x^cnt], y^cnt);
        }
    }
}

signed main() {
    fastio;

    srand(6969);

    int T; cin >> T;
    while (T--) solve();

    return 0;
}
