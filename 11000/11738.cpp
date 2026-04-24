#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=998244353, inf=1e12;

int N, M, Q, ans[101010];
set<array<int, 2>> lnk[101010], rlnk[101010];
int deg[101010], us[101010];
array<int, 3> T[101010];
map<array<int, 2>, vector<int>> mp;

vector<int> gr[101010];

int sz[101010];
void gets(int p, int x) {sz[p]=1; for (int i : gr[p]) if (i!=x) gets(i, p), sz[p]+=sz[i];}
int getc(int p, int x, int s){for (int i : gr[p]) if (i!=x && sz[i]>s/2) return getc(i, p, s); return p;}

int X[101010];
void dfs(int p, int x, int c) {
    for (int i : T[p]) X[i]=c;
    for (int i : gr[p]) if (i!=x) dfs(i, p, c);
}

int D1[101010], vis1[101010], D2[101010], vis2[101010];
vector<int> tc;

void dijk1(int s) {
    for (int i : tc) D1[i]=vis1[i]=0; tc.clear();
    priority_queue<array<int, 2>, vector<array<int, 2>>, greater<array<int, 2>>> pq;
    pq.push({-inf, s}); D1[s]=-inf;

    while (pq.size()) {
        int p=pq.top()[1], d=pq.top()[0]; pq.pop();
        if (vis1[p]++) continue; tc.push_back(p);
        for (array<int, 2> i : lnk[p]) if (D1[i[0]]>d+i[1])
            D1[i[0]]=d+i[1], pq.push({D1[i[0]], i[0]});
    }
}
void dijk2(int s) {
    for (int i : tc) D2[i]=vis2[i]=0; tc.clear();
    priority_queue<array<int, 2>, vector<array<int, 2>>, greater<array<int, 2>>> pq;
    pq.push({-inf, s}); D2[s]=-inf;

    while (pq.size()) {
        int p=pq.top()[1], d=pq.top()[0]; pq.pop();
        if (vis2[p]++) continue; tc.push_back(p);
        for (array<int, 2> i : rlnk[p]) if (D2[i[0]]>d+i[1])
            D2[i[0]]=d+i[1], pq.push({D2[i[0]], i[0]});
    }
}

void erz(set<array<int, 2>>& s, int p) {
    s.erase(s.lower_bound({p, -1}));
}

void dcp(int p, vector<array<int, 3>> qry) {
    gets(p, -1); p=getc(p, -1, sz[p]);
    int _c=1; for (int i : gr[p]) dfs(i, p, _c++);
    for (int i : T[p]) X[i]=_c++;

    for (int i : T[p]) {
        dijk1(i); dijk2(i);
        for (array<int, 3> q : qry) ans[q[2]]=min(ans[q[2]], D2[q[0]]+D1[q[1]]+2*inf);
    }

    for (int i : gr[p]) for (int& j : gr[i]) if (j==p) {swap(j, gr[i].back()); gr[i].pop_back(); break;}
    for (int i : gr[p]) dfs(i, p, 0);

    for (int i : gr[p]) {
        dfs(i, p, 1);
        set<array<int, 2>> kep[3];
        set<array<int, 2>> rkep[3];
        for (int x : {0, 1, 2}) {
            swap(kep[x], lnk[T[p][x]]);
            swap(rkep[x], rlnk[T[p][x]]);
            for (array<int, 2> it : kep[x]) if (X[it[0]]) lnk[T[p][x]].insert(it);
            for (array<int, 2> it : rkep[x]) if (X[it[0]]) rlnk[T[p][x]].insert(it);
        }

        vector<array<int, 3>> sqr;
        for (array<int, 3> q : qry) if (X[q[0]] && X[q[1]]) sqr.push_back(q);
        dcp(i, sqr);

        for (int x : {0, 1, 2}) swap(kep[x], lnk[T[p][x]]);
        for (int x : {0, 1, 2}) swap(rkep[x], rlnk[T[p][x]]);
        dfs(i, p, 0);
    }
}

int L[101010], R[101010], P[101010];
map<int, int> grp[101010];

void clear() {
    for (int i=1; i<=N; i++) {
        lnk[i].clear(); rlnk[i].clear();
        deg[i]=us[i]=0; T[i]={0, 0, 0};
        gr[i].clear(); sz[i]=X[i]=0;
        D1[i]=vis1[i]=D2[i]=vis2[i]=0;
        L[i]=R[i]=P[i]=0; grp[i].clear();
    }
    M=0; mp.clear(); tc.clear();
}

void solve(int t) {
    cin >> N;
    for (int i=1; i<=N; i++) {
        int j=i%N+1;
        lnk[i].insert({j, 1}); lnk[j].insert({i, 1});
    }
    for (int i=1; i<=N-3; i++) {
        int a, b; cin >> a >> b;
        lnk[a].insert({b, 1}); lnk[b].insert({a, 1});
    }

    for (int i=1; i<=N; i++) for (array<int, 2> j : lnk[i]) rlnk[j[0]].insert({i, j[1]});

    vector<int> st;
    for (int i=1; i<=N; i++) {deg[i]=lnk[i].size(); if (deg[i]==2) st.push_back(i);}
    while (st.size()) {
        int p=st.back(); us[p]=1; st.pop_back();
        vector<int> g;
        for (array<int, 2> i : lnk[p]) if (!us[i[0]]) g.push_back(i[0]);
        if (g.size()==2) T[++M]={p, g[0], g[1]};
        for (int i : g) if (--deg[i]==2) st.push_back(i);
    }

    for (int i=1; i<=M; i++) {
        for (int j=0; j<3; j++) {
            int x=T[i][j], y=T[i][(j+1)%3]; if (x>y) swap(x, y);
            mp[{x, y}].push_back(i);
        }
    }

    for (pair<array<int, 2>, vector<int>> i : mp) if (i.second.size()==2)
        gr[i.second[0]].push_back(i.second[1]), gr[i.second[1]].push_back(i.second[0]);

    cin >> Q;
    vector<array<int, 3>> qry(Q);
    for (int i=0; i<Q; i++) cin >> qry[i][0] >> qry[i][1];
    for (int i=0; i<Q; i++) qry[i][2]=i, ans[i]=inf;

    dcp(1, qry);

    for (int i=0; i<Q; i++) cout << ans[i] << "\n";
}

signed main() {
    fastio;

    int T=1; //cin >> T;
    for (int i=1; i<=T; i++) solve(i);

    return 0;
}
