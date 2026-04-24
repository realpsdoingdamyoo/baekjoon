#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=998244353, inf=1e17;

int N, M, Q, ans[303030];
set<array<int, 2>> Lnk[303030];
vector<array<int, 2>> lnk[303030], rlnk[303030];
int deg[303030], us[303030];
array<int, 3> T[303030];
map<array<int, 2>, vector<int>> mp;

vector<int> gr[303030];

int sz[303030];
void gets(int p, int x) {sz[p]=1; for (int i : gr[p]) if (i!=x) gets(i, p), sz[p]+=sz[i];}
int getc(int p, int x, int s){for (int i : gr[p]) if (i!=x && sz[i]>s/2) return getc(i, p, s); return p;}

int X[303030];
void dfs(int p, int x, int c) {
    for (int i : T[p]) X[i]=c;
    for (int i : gr[p]) if (i!=x) dfs(i, p, c);
}

int D1[303030], vis1[303030], D2[303030], vis2[303030];
vector<int> tc1, tc2;

void dijk1(int s) {
    for (int i : tc1) D1[i]=vis1[i]=0; tc1.clear();
    priority_queue<array<int, 2>, vector<array<int, 2>>, greater<array<int, 2>>> pq;
    pq.push({-inf, s}); D1[s]=-inf;

    while (pq.size()) {
        int p=pq.top()[1], d=pq.top()[0]; pq.pop();
        if (vis1[p]++) continue; tc1.push_back(p);
        for (array<int, 2> i : lnk[p]) if (D1[i[0]]>d+i[1])
            D1[i[0]]=d+i[1], pq.push({D1[i[0]], i[0]});
    }
}
void dijk2(int s) {
    for (int i : tc2) D2[i]=vis2[i]=0; tc2.clear();
    priority_queue<array<int, 2>, vector<array<int, 2>>, greater<array<int, 2>>> pq;
    pq.push({-inf, s}); D2[s]=-inf;

    while (pq.size()) {
        int p=pq.top()[1], d=pq.top()[0]; pq.pop();
        if (vis2[p]++) continue; tc2.push_back(p);
        for (array<int, 2> i : rlnk[p]) if (D2[i[0]]>d+i[1])
            D2[i[0]]=d+i[1], pq.push({D2[i[0]], i[0]});
    }
}

void dcp(int p, vector<array<int, 3>>& qry) {
    if (!qry.size()) return;
    gets(p, -1); p=getc(p, -1, sz[p]);
    int _c=1; for (int i : gr[p]) dfs(i, p, _c++);
    for (int i : T[p]) X[i]=_c++;

    for (int i : T[p]) {
        dijk1(i); dijk2(i);
        for (array<int, 3> q : qry) ans[q[2]]=min(ans[q[2]], D2[q[0]]+D1[q[1]]+2*inf);
    }

    for (int i : gr[p]) for (int& j : gr[i]) if (j==p) {swap(j, gr[i].back()); gr[i].pop_back(); break;}
    for (int i : gr[p]) dfs(i, p, 0);

    vector<array<int, 2>> kep[3], rkep[3];
    for (int i : gr[p]) {
        dfs(i, p, 1);
        for (int x : {0, 1, 2}) kep[x].clear(), rkep[x].clear();
        for (int x : {0, 1, 2}) {
            swap(kep[x], lnk[T[p][x]]);
            swap(rkep[x], rlnk[T[p][x]]);
            for (array<int, 2> it : kep[x]) if (X[it[0]]) lnk[T[p][x]].push_back(it);
            for (array<int, 2> it : rkep[x]) if (X[it[0]]) rlnk[T[p][x]].push_back(it);
        }

        vector<array<int, 3>> sqr;
        for (array<int, 3> q : qry) if (X[q[0]] && X[q[1]]) sqr.push_back(q);
        dcp(i, sqr);

        for (int x : {0, 1, 2}) swap(kep[x], lnk[T[p][x]]);
        for (int x : {0, 1, 2}) swap(rkep[x], rlnk[T[p][x]]);
        dfs(i, p, 0);
    }
}

void dnc(int l, int r) {
    if (l+1>=r) return;
    int lp=(*prev(Lnk[l].lower_bound({r, -1})))[0];
    int rp=(*Lnk[r].upper_bound({l, inf}))[0];
    if (lp==rp) dnc(l, lp), dnc(rp, r);
    else {
        Lnk[l].insert({rp, inf}); Lnk[rp].insert({l, inf});
        dnc(l, rp); dnc(rp, r);
    }
}

int P[303030], L[303030], R[303030];

void clear() {
    for (int i=1; i<=N; i++) {
        lnk[i].clear(); rlnk[i].clear(); Lnk[i].clear();
        deg[i]=us[i]=0; T[i]={0, 0, 0};
        gr[i].clear(); sz[i]=X[i]=0;
        D1[i]=vis1[i]=D2[i]=vis2[i]=0;
        L[i]=R[i]=P[i]=0;
    }
    M=0; mp.clear(); tc1.clear(); tc2.clear();
}

void solve() {
    cin >> N >> Q;
    clear();

    for (int i=1; i<=N; i++) cin >> P[i];
    for (int i=1; i<=N; i++) cin >> L[i] >> R[i];

    vector<int> pst;
    for (int i=1; i<=N; i++) {
        while (pst.size() && P[pst.back()]<=P[i]) {
            int j=pst.back();
            Lnk[j].insert({i, R[j]}); Lnk[i].insert({j, L[i]});
            pst.pop_back();

        }
        pst.push_back(i);
    }
    pst.clear();
    for (int i=N; i>=1; i--) {
        while (pst.size() && P[pst.back()]<=P[i]) {
            int j=pst.back();
            Lnk[j].insert({i, L[j]}); Lnk[i].insert({j, R[i]});
            pst.pop_back();

        }
        pst.push_back(i);
    }
    Lnk[1].insert({N, inf}); Lnk[N].insert({1, inf});
    dnc(1, N);

    for (int i=1; i<=N; i++) for (array<int, 2> j : Lnk[i])
        lnk[i].push_back(j), rlnk[j[0]].push_back({i, j[1]});

    vector<int> st;
    for (int i=1; i<=N; i++) {deg[i]=Lnk[i].size(); if (deg[i]==2) st.push_back(i);}
    while (st.size()) {
        int p=st.back(); us[p]=1; st.pop_back();
        vector<int> g;
        for (array<int, 2> i : Lnk[p]) if (!us[i[0]]) g.push_back(i[0]);
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

    vector<array<int, 3>> qry(Q);
    for (int i=0; i<Q; i++) cin >> qry[i][0] >> qry[i][1];
    for (int i=0; i<Q; i++) qry[i][2]=i, ans[i]=inf;

    dcp(1, qry);

    for (int i=0; i<Q; i++) cout << ans[i] << "\n";
}

signed main() {
    fastio;

    int T; cin >> T;
    while (T--) solve();

    return 0;
}
