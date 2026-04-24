#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
//const int mod=1e9+7, MOD=998244353, inf=2e17;

vector<int> lnk[202020], lnk1[202020], lnk2[202020];
int g[202020];
int Find(int x){return g[x]==x?x:g[x]=Find(g[x]);}
void Union(int a, int b){g[Find(a)]=Find(b);}

int sp1[202020][20], sp2[202020][20];

int up1(int p, int x) {
    for (int i=19; i>=0; i--) if (sp1[p][i]!=0 && sp1[p][i]<=x) p=sp1[p][i];
    return p;
}
int up2(int p, int x) {
    for (int i=19; i>=0; i--) if (sp2[p][i]!=0 && sp2[p][i]>=x) p=sp2[p][i];
    return p;
}

int in1[202020], out1[202020], pv1;
int in2[202020], out2[202020], pv2;

void dfs1(int p) {
    in1[p]=++pv1;
    for (int i : lnk1[p]) dfs1(i);
    out1[p]=pv1;
}

void dfs2(int p) {
    in2[p]=++pv2;
    for (int i : lnk2[p]) dfs2(i);
    out2[p]=pv2;
}

const int X=18;
set<int> st[2<<X];

int OCF(int p, int l, int r){return st[p].lower_bound(l)!=st[p].upper_bound(r);}
int CF(int s, int e, int l, int r) {
    s+=1<<X; e+=1<<X;
    while (s<=e) {
        if (s&1) if (OCF(s, l, r)) return 1;
        if (~e&1) if (OCF(e, l, r)) return 1;
        ++s>>=1; --e>>=1;
    }
    return 0;
}

vector<int> check_validity(int N, vector<int> x, vector<int> y, vector<int> S, vector<int> E, vector<int> L, vector<int> R) {
    for (int i=0; i<x.size(); i++) lnk[x[i]+1].push_back(y[i]+1), lnk[y[i]+1].push_back(x[i]+1);

    iota(g+1, g+N+1, 1);
    for (int i=1; i<=N; i++) for (int j : lnk[i]) if (j<i && Find(j)!=i) {
        j=Find(j); sp1[j][0]=i; lnk1[i].push_back(j); Union(j, i);
    }
    iota(g+1, g+N+1, 1);
    for (int i=N; i>=1; i--) for (int j : lnk[i]) if (j>i && Find(j)!=i) {
        j=Find(j); sp2[j][0]=i; lnk2[i].push_back(j); Union(j, i);
    }

    for (int j=1; j<20; j++) for (int i=1; i<=N; i++) {
        sp1[i][j]=sp1[sp1[i][j-1]][j-1]; sp2[i][j]=sp2[sp2[i][j-1]][j-1];
    }

    dfs1(N); dfs2(1);

    for (int i=1; i<=N; i++) {
        int p=in1[i]+(1<<X), q=in2[i];
        while (p) st[p].insert(q), p>>=1;
    }

    vector<int> ans;
    for (int i=0; i<S.size(); i++) {
        int s=S[i]+1, e=E[i]+1, l=L[i]+1, r=R[i]+1;
        s=up2(s, l); e=up1(e, r);
        ans.push_back(CF(in1[e], out1[e], in2[s], out2[s]));
    }
    return ans;
}
