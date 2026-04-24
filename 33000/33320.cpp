#include <bits/stdc++.h>
using namespace std;
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;

void compress(vector<int>& v1, vector<int>& v2) {
    vector<int> cmp;
    for (int i : v1) cmp.push_back(i);
    for (int i : v2) cmp.push_back(i);
    sort(cmp.begin(), cmp.end());
    cmp.erase(unique(cmp.begin(), cmp.end()), cmp.end());
    for (int& i : v1) i=lower_bound(cmp.begin(), cmp.end(), i)-cmp.begin();
    for (int& i : v2) i=lower_bound(cmp.begin(), cmp.end(), i)-cmp.begin();
}

const int X=20;
int seg[1<<X+1], lzy[1<<X+1];

void prop(int p) {lzy[p<<1]+=lzy[p]; lzy[p<<1|1]+=lzy[p]; seg[p]+=lzy[p]; lzy[p]=0;}
void segup(int p) {seg[p]=max(seg[p<<1]+lzy[p<<1], seg[p<<1|1]+lzy[p<<1|1]);}

void update(int s, int e, int x) {
    int S=s+=1<<X, E=e+=1<<X;
    for (int i=X; i>=1; i--) prop(S>>i), prop(E>>i);
    while (s<=e) {
        if (s&1) lzy[s]+=x; ++s>>=1;
        if (~e&1) lzy[e]+=x; --e>>=1;
    }
    for (int i=1; i<=X; i++) segup(S>>i), segup(E>>i);
}
int Max(int s, int e) {
    s+=1<<X; e+=1<<X; int r=0;
    for (int i=X; i>=1; i--) prop(s>>i), prop(e>>i);
    while (s<=e) {
        if (s&1) r=max(r, seg[s]+lzy[s]); ++s>>=1;
        if (~e&1) r=max(r, seg[e]+lzy[e]); --e>>=1;
    }
    return r;
}

int g[505050];
int Find(int x){return g[x]==x?x:g[x]=Find(g[x]);}
void Union(int a, int b) {a=Find(a); b=Find(b); g[b]=a;}

set<array<int, 3>> st;

vector<array<int, 3>> in[1010101], out[1010101];

array<int, 2> Merge(int s, int e, int x, set<array<int, 3>>::iterator it) {
    int l=(*it)[0], r=(*it)[1], y=(*it)[2]; st.erase(it);
    if (Max(max(s, l), min(r, e))==0) {
        if (l<s) st.insert({l, s-1, y});
        if (e<r) st.insert({e+1, r, y});
        return {s, e};
    }
    Union(x, y);
    return {min(s, l), max(r, e)};
}

void IN(int s, int e, int x) {
    array<int, 2> ret={s, e};
    while (st.size()) {
        set<array<int, 3>>::iterator it=st.lower_bound({e+1, 0, 0});
        if (it==st.begin()) break; it=prev(it);
        if ((*it)[1]<s || e<(*it)[0]) break;
        array<int, 2> r=Merge(s, e, x, it);
        ret={min(r[0], ret[0]), max(r[1], ret[1])};
    }
    st.insert({ret[0], ret[1], x});
    update(s, e, 1);
}

void OUT(int s, int e, int x) {
    update(s, e, -1);
}

vector<int> find_union(int N, vector<int> A, vector<int> B, vector<int> C, vector<int> D) {
    compress(A, C); compress(B, D);

    for (int i=0; i<N; i++) g[i]=i;
    for (int i=0; i<N; i++) {
        in[A[i]].push_back({B[i], D[i], i});
        out[C[i]].push_back({B[i], D[i], i});
    }

    for (int i=0; i<2*N; i++) {
        for (array<int, 3> j : in[i]) IN(j[0], j[1], j[2]);
        for (array<int, 3> j : out[i]) OUT(j[0], j[1], j[2]);
    }

    vector<int> cmp, ret;
    for (int i=0; i<N; i++) cmp.push_back(Find(i));
    sort(cmp.begin(), cmp.end());
    cmp.erase(unique(cmp.begin(), cmp.end()), cmp.end());
    for (int i=0; i<N; i++) ret.push_back(lower_bound(cmp.begin(), cmp.end(), Find(i))-cmp.begin());

    return ret;
}
