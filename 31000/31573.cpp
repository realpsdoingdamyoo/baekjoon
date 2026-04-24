#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
const int mod=1e9+7, MOD=998244353, inf=2e17;

int N, M;
vector<int> lnk[101010];
vector<array<int, 2>> grp[2020202];
int C[101010], R[2020202], vi[2020202];

int CO[101010], sz[101010], fd[101010], cp[101010], di[101010], pv;
vector<int> in[101010], out[101010], mc[101010];
void gets(int p, int x) {
    sz[p]=1;
    for (int i : lnk[p]) if (i!=x && !CO[i]) gets(i, p), sz[p]+=sz[i];
}
int getc(int p, int x, int s) {
    for (int i : lnk[p]) if (i!=x && !CO[i] && sz[i]>s/2) return getc(i, p, s);
    return p;
}
int getf(int p, int x) {
    int r=0; for (int i : lnk[p]) if (i!=x && !CO[i]) r=max(r, getf(i, p)+1);
    return r;
}
void getm(int n, int p, int x) {
    mc[n][di[p]]=C[p];
    for (int i : lnk[p]) if (i!=x && !CO[i]) di[i]=di[p]+1, getm(n, i, p);
}
int dcp(int p) {
    gets(p, -1); p=getc(p, -1, sz[p]); fd[p]=getf(p, -1);
    mc[p]=vector<int>(fd[p]+1, inf); di[p]=0; getm(p, p, -1); CO[p]=1;
    for (int i=0; i<=fd[p]; i++) in[p].push_back(++pv), out[p].push_back(++pv);
    for (int i=1; i<=fd[p]; i++) mc[p][i]=min(mc[p][i], mc[p][i-1]);

    for (int i : lnk[p]) if (!CO[i]) cp[dcp(i)]=p;
    return p;
}

int dep[101010], sp[101010][20];
void dfs(int p, int x) {
    for (int i : lnk[p]) if (i!=x) {
        dep[i]=dep[p]+1; sp[i][0]=p;
        for (int j=1; j<20; j++) sp[i][j]=sp[sp[i][j-1]][j-1];
        dfs(i, p);
    }
}
int lca(int x, int y) {
    if (dep[x]<dep[y]) swap(x, y);
    for (int i=19; i>=0; i--) if (dep[x]-dep[y]&(1<<i)) x=sp[x][i];
    if (x==y) return x;
    for (int i=19; i>=0; i--) if (sp[x][i]!=sp[y][i]) x=sp[x][i], y=sp[y][i];
    return sp[x][0];
}
int dist(int x, int y) {
    return dep[x]+dep[y]-2*dep[lca(x, y)];
}

void adq(int n, int p, int d, int t) {
    int x=p;
    while (x>=0) {
        int dis=min(fd[x], d-dist(p, x));
        if (dis>=0) {
            if (t==0) grp[in[x][dis]].push_back({n, 0});
            else grp[n].push_back({out[x][dis], 0});
        }
        x=cp[x];
    }
}

vector<int> find_spread(signed N_, signed M_, vector<signed> A_, vector<signed> B_, vector<signed> P_, vector<signed> D_, vector<signed> C_) {
    N=N_; M=M_;
    for (int i=0; i<N-1; i++) lnk[A_[i]].push_back(B_[i]), lnk[B_[i]].push_back(A_[i]);
    for (int i=0; i<N; i++) C[i]=C_[i];
    pv=M-1; dfs(0, -1);
    cp[dcp(0)]=-1;

    for (int i=0; i<N; i++) {
        for (int j=1; j<=fd[i]; j++) grp[in[i][j-1]].push_back({in[i][j], 0}), grp[out[i][j]].push_back({out[i][j-1], 0});
        for (int j=0; j<=fd[i]; j++) grp[out[i][j]].push_back({in[i][j], mc[i][j]});
    }
    for (int i=0; i<M; i++) adq(i, P_[i], D_[i], 0), adq(i, P_[i], D_[i], 1);

    for (int p=0; p<N; p++) {
        int x=p; ++pv;
        while (x>=0) {
            int dis=dist(p, x);
            assert(dis<=fd[x]);
            grp[out[x][dis]].push_back({pv, 0});
            grp[pv].push_back({in[x][dis], C[p]});
            x=cp[x];
        }
    }

    priority_queue<array<int, 2>, vector<array<int, 2>>, greater<array<int, 2>>> pq;
    pq.push({0, 0}); fill(R+1, R+pv+1, inf);
    while (pq.size()) {
        int p=pq.top()[1], d=pq.top()[0]; pq.pop();
        if (vi[p]++) continue;
        for (array<int, 2> i : grp[p]) if (R[i[0]]>d+i[1])
            R[i[0]]=d+i[1], pq.push({R[i[0]], i[0]});
    }

    vector<int> ans;
    for (int i=0; i<M; i++) ans.push_back(R[i]==inf?-1:R[i]);
    return ans;
}
