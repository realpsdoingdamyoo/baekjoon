#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e17;
#define m ((s+e)>>1)

int N, A[303030], P[303030];

struct msg {
    array<int, 2> seg[1212121];
    void update(int p, int s, int e, int x, int y) {
        if (s==e) {seg[p]={y, x}; return;}
        if (x<=m) update(p<<1, s, m, x, y); else update(p<<1|1, m+1, e, x, y);
        seg[p]=min(seg[p<<1], seg[p<<1|1]);
    }
    array<int, 2> mq(int p, int s, int e, int l, int r) {
        if (r<s || e<l) return {inf, inf};
        if (l<=s && e<=r) return seg[p];
        return min(mq(p<<1, s, m, l, r), mq(p<<1|1, m+1, e, l, r));
    }
} sg;

int E[606060], S[606060], pv=1;
struct cmp {bool operator()(array<int, 2> a, array<int, 2> b) {return a[0]*b[1]==a[1]*b[0]?a[0]<b[0]:a[0]*b[1]>a[1]*b[0];}};
bool cpr(array<int, 2> a, array<int, 2> b){return a[0]*b[1]==a[1]*b[0]?a[0]<b[0]:a[0]*b[1]>a[1]*b[0];}
priority_queue<array<int, 2>, vector<array<int, 2>>, cmp> pq[606060], st;

void in(int p, int l, int r) {
    if (l>r) return;
    int x=sg.mq(1, 0, N-1, l, r)[0];
    vector<int> ct={l-1}, ch;
    while (1) {
        array<int, 2> c=sg.mq(1, 0, N-1, ct.back()+1, r);
        if (c[0]!=x) break; ct.push_back(c[1]);
    }
    ct.push_back(r+1);

    for (int i=0; i<ct.size()-1; i++) ch.push_back(++pv), in(pv, ct[i]+1, ct[i+1]-1);

    for (int i : ch) {
        if (pq[p].size()<pq[i].size()) swap(pq[p], pq[i]);
        E[p]+=E[i]; S[p]+=S[i];
        while (pq[i].size()) {pq[p].push(pq[i].top()), pq[i].pop();}
    }
    array<int, 2> a={r-l+1-E[p], (P[r]-(l?P[l-1]:0))-S[p]};
    E[p]=r-l+1; S[p]=P[r]-(l?P[l-1]:0);

    while (pq[p].size()) {
        array<int, 2> tp=pq[p].top(); pq[p].pop();
        if (tp[0]*a[1]<a[0]*tp[1]) a[0]+=tp[0], a[1]+=tp[1];
        else {pq[p].push(tp); st.push(tp); break;}
    }
    pq[p].push(a); st.push(a);
}

int M;
vector<array<int, 2>> prs;
struct fuckseg {
    struct Node {
int L=0, R=0, cnt=0;
array<int, 2> sum={};
    };
    int sz=0;
    vector<Node> seg;
    multiset<array<int, 2>> sv;

    void update(int p, int s, int e, int x, int y) {
if (s==e) {
seg[p].cnt+=y;
seg[p].sum[0]+=prs[x][0]*y;
seg[p].sum[1]+=prs[x][1]*y;
}
else {
if (x<=m) {
if (seg[p].L==0) {
seg.push_back({});
seg[p].L=seg.size()-1;
}
update(seg[p].L, s, m, x, y);
}
else {
if (seg[p].R==0) {
seg.push_back({});
seg[p].R=seg.size()-1;
}
update(seg[p].R, m+1, e, x, y);
}
seg[p].cnt=seg[seg[p].L].cnt+seg[seg[p].R].cnt;
seg[p].sum[0]=seg[seg[p].L].sum[0]+seg[seg[p].R].sum[0];
seg[p].sum[1]=seg[seg[p].L].sum[1]+seg[seg[p].R].sum[1];
}
}

array<int, 2> stk(int p, int s, int e, int x) {
if (s==e) return {prs[s][0]*x, prs[s][1]*x};
int lc=seg[seg[p].L].cnt;
if (x<=lc) return stk(seg[p].L, s, m, x);
array<int, 2> g=stk(seg[p].R, m+1, e, x-lc);
g[0]+=seg[seg[p].L].sum[0]; g[1]+=seg[seg[p].L].sum[1];
return g;
}

    void push(array<int, 2> x) {
        int s=0, e=M-1; sz++;
        while (s<=e) {
            if (cpr(prs[m], x)) s=m+1;
            else e=m-1;
        }
        sv.insert(x);
        update(1, 0, M-1, s, 1);
    }

    int rig(int p, int s, int e) {
        if (s==e) return e;
        if (seg[seg[p].R].cnt) return rig(seg[p].R, m+1, e);
        return rig(seg[p].L, s, m);
    }

    array<int, 2> top() {
        int p=rig(1, 0, M-1); sz--;
        return prs[p];
    }

    void pop() {
        int p=rig(1, 0, M-1);
        sv.erase(sv.find(prs[p]));
        update(1, 0, M-1, p, -1);
    }
} seg[1212121];

map<array<int, 2>, array<int, 2>> ans;
void in2(int p, int l, int r) {
    if (l>r) return;
    S[p]=E[p]=0;
    int x=sg.mq(1, 0, N-1, l, r)[0];
    vector<int> ct={l-1}, ch;
    while (1) {
        array<int, 2> c=sg.mq(1, 0, N-1, ct.back()+1, r);
        if (c[0]!=x) break; ct.push_back(c[1]);
    }
    ct.push_back(r+1);

    for (int i=0; i<ct.size()-1; i++) ch.push_back(++pv), in2(pv, ct[i]+1, ct[i+1]-1);

    for (int i : ch) {
        if (seg[p].sz<seg[i].sz) swap(seg[p], seg[i]);
        E[p]+=E[i]; S[p]+=S[i];
        while (seg[i].sz) seg[p].push(seg[i].top()), seg[i].pop();
    }
    array<int, 2> a={r-l+1-E[p], (P[r]-(l?P[l-1]:0))-S[p]};
    E[p]=r-l+1; S[p]=P[r]-(l?P[l-1]:0);

    while (seg[p].sz) {
        array<int, 2> tp=seg[p].top(); seg[p].pop();
        if (tp[0]*a[1]<a[0]*tp[1]) a[0]+=tp[0], a[1]+=tp[1];
        else {seg[p].push(tp); break;}
    }
    seg[p].push(a);

    if (l==0 || r==N-1) return;

    int s=0, e=seg[p].sz-1;
    array<int, 2> g={r-l+3, P[r+1]-(l==1?0:P[l-2])};
    while (s<=e) {
        array<int, 2> mv=seg[p].stk(1, 0, M-1, m);
        array<int, 2> nv=seg[p].stk(1, 0, M-1, m+1);
        mv={g[0]-mv[0], g[1]-mv[1]}; nv={g[0]-nv[0], g[1]-nv[1]};
        if (mv[1]*nv[0]<nv[1]*mv[0]) s=m+1; else e=m-1;
    }
    array<int, 2> sv=seg[p].stk(1, 0, M-1, s);
    ans[{l-1, r+1}]={g[1]-sv[1], g[0]-sv[0]};
}

void initialize(vector<signed> a) {
    N=a.size();
    for (int i=0; i<N; i++) A[i]=a[i], sg.update(1, 0, N-1, i, A[i]);
    P[0]=A[0]; for (int i=1; i<N; i++) P[i]=P[i-1]+A[i];

    in(1, 0, N-1);
    while (st.size()) prs.push_back(st.top()), st.pop();
    reverse(prs.begin(), prs.end());
    M=prs.size();
    for (int i=1; i<=N*4; i++) seg[i].seg.resize(2, {});
    pv=1; in2(1, 0, N-1);
}

array<int, 2> maximum_average(signed i, signed j) {
    if (i==j-1) return {A[i]+A[j], 2};
    return ans[{i, j}];
}
