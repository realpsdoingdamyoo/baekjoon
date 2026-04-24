#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;

int N, out[202020];
int X[202020], Y[202020];
char Z[202020];
map<int, set<array<int, 2>>> A, B, C, D, E, F;
priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> pq;

int dist(int a, int b){return abs(X[a]-X[b])+abs(Y[a]-Y[b]);}

void push(const map<int, set<array<int, 2>>>& mp, string s) {
    for (pair<int, set<array<int, 2>>> pr : mp) {
        set<array<int, 2>>& st=pr.second;
        set<array<int, 2>>::iterator it=st.begin();
        if (st.size()==1) continue;
        while (next(it)!=st.end()) {
            array<int, 2> p=*it, x=*next(it);
            if (Z[p[1]]==s[0] && Z[x[1]]==s[1]) pq.push({dist(p[1], x[1])/2, p[1], x[1]});
            it=next(it);
        }
    }
}

set<array<int, 2>> tmp;
void push2(int p) {
    for (int i=0; i<=2; i++) {
        set<array<int, 2>>* st;
        set<array<int, 2>>::iterator it, xp;
        string s;

        if (i==0) {
            st=&(Z[p]=='N'||Z[p]=='W'?C:A)[X[p]+Y[p]];
            s=(Z[p]=='N'||Z[p]=='W'?"NW":"ES");
            it=st->find({X[p], p});
        }
        else if (i==1) {
            st=&(Z[p]=='N'||Z[p]=='E'?D:B)[X[p]-Y[p]];
            s=(Z[p]=='N'||Z[p]=='E'?"EN":"SW");
            it=st->find({X[p], p});
        }
        else {
            st=&(Z[p]=='N'||Z[p]=='S'?E[X[p]]:F[Y[p]]);
            s=(Z[p]=='N'||Z[p]=='S'?"SN":"EW");
            it=st->find({Z[p]=='N'||Z[p]=='S'?Y[p]:X[p], p});
        }

        if (Z[p]==s[0]) {
            if (next(it)==st->end()) continue;
            xp=next(it);
        }
        else {
            if (it==st->begin()) continue;
            xp=prev(it);
        }
        int x=(*xp)[1];
        if (Z[x]==Z[p]) continue;
        pq.push({dist(x, p)/2, x, p});
    }
}

void pers(set<array<int, 2>>& st, array<int, 2> p) {
    set<array<int, 2>>::iterator it=st.find(p);
    if (it==st.begin() || next(it)==st.end()) {st.erase(it); return;}
    int l=(*prev(it))[1], r=(*next(it))[1];
    if (Z[l]!=Z[r] && (Z[l]=='E' || Z[r]=='W' || (Z[l]=='S' && Z[r]=='N')))
        pq.push({dist(l, r)/2, l, r});
    st.erase(it);
}

void ers(int p) {
    if (A[X[p]+Y[p]].find({X[p], p})!=A[X[p]+Y[p]].end()) pers(A[X[p]+Y[p]], {X[p], p});
    if (C[X[p]+Y[p]].find({X[p], p})!=C[X[p]+Y[p]].end()) pers(C[X[p]+Y[p]], {X[p], p});
    if (B[X[p]-Y[p]].find({X[p], p})!=B[X[p]-Y[p]].end()) pers(B[X[p]-Y[p]], {X[p], p});
    if (D[X[p]-Y[p]].find({X[p], p})!=D[X[p]-Y[p]].end()) pers(D[X[p]-Y[p]], {X[p], p});
    if (E[X[p]].find({Y[p], p})!=E[X[p]].end()) pers(E[X[p]], {Y[p], p});
    if (F[Y[p]].find({X[p], p})!=F[Y[p]].end()) pers(F[Y[p]], {X[p], p});
}

signed main() {
    fastio;

    cin >> N;
    for (int i=1; i<=N; i++) {
        int x, y; char c; cin >> x >> y >> c;
        if (c=='E' || c=='S') A[x+y].insert({x, i});
        else C[x+y].insert({x, i});

        if (c=='W' || c=='S') B[x-y].insert({x, i});
        else D[x-y].insert({x, i});

        if (c=='N' || c=='S') E[x].insert({y, i});
        else F[y].insert({x, i});

        X[i]=x; Y[i]=y; Z[i]=c;
    }

    push(A, "ES");
    push(B, "SW");
    push(C, "NW");
    push(D, "EN");
    push(E, "SN");
    push(F, "EW");

    while (pq.size()) {
        int t=pq.top()[0], x=pq.top()[1], y=pq.top()[2]; pq.pop();
        if (out[x] && out[y]) continue;
        if (out[x] || out[y]) {
            if (!out[y]) swap(x, y);
            if (t==out[y]) out[x]=t, ers(x);
            else push2(x);
        }
        else {
            out[x]=out[y]=t;
            ers(x); ers(y);
        }
    }

    for (int i=1; i<=N; i++) if (!out[i]) cout << i << "\n";

    return 0;
}
