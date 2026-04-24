#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
const int mod=1e9+7, MOD=998244353, inf=2e17;

int N, Q;
int A[101010];

struct ST{
    vector<array<int, 3>> nd;
    vector<int> l, r;
    array<int, 3> mrg(array<int, 3> a, array<int, 3> b) {
        for (int i=0; i<3; i++) for (int j=0; j<=3; j++) if (a[j]>b[i]) swap(a[j], b[i]);
        return a;
    }
    array<int, 3> fil(int x) {
        array<int, 3> r={inf, inf, inf};
        for (int i=0; i<x; i++) r[i]=0;
        return r;
    }

    void update(int n, int s, int e, int p, int x) {
        if (s==e) {nd[n]={x, inf, inf}; return;}
        int m=s+e>>1;
        if (p<=m) {
            if (l[n]==-1) l[n]=l.size(), l.push_back(-1), r.push_back(-1), nd.push_back({inf, inf, inf});
            update(l[n], s, m, p, x);
        }
        else {
            if (r[n]==-1) r[n]=r.size(), l.push_back(-1), r.push_back(-1), nd.push_back({inf, inf, inf});
            update(r[n], m+1, e, p, x);
        }
        array<int, 3> _L=(l[n]==-1?fil(min(m-s+1, 3LL)):nd[l[n]]);
        array<int, 3> _R=(r[n]==-1?fil(min(e-m, 3LL)):nd[r[n]]);
        nd[n]=mrg(_L, _R);
    }

    array<int, 3> query(int n, int s, int e, int ql, int qr) {
        if (n==-1) return fil(min(3LL, max(min(e, qr)-max(s, ql)+1, 0LL)));
        if (qr<s || e<ql) return {inf, inf, inf};
        if (ql<=s && e<=qr) return nd[n];
        int m=s+e>>1;
        return mrg(query(l[n], s, m, ql, qr), query(r[n], m+1, e, ql, qr));
    }
    void upd(int p, int x){update(0, 1, N, p, x);}
    array<int, 3> que(int s, int e){return query(0, 1, N, s, e);}

} T[1010101];

int P[1010101];

vector<array<int, 2>> ft(int n) {
    vector<array<int, 2>> ret;
    while (n>1) {
        int x=P[n]; n/=x;
        if (ret.size() && ret.back()[0]==x) ret.back()[1]++;
        else ret.push_back({x, 1});
    }
    return ret;
}

int pw(int x, int p) {
    int r=1;
    while (p--) r=r*x;
    return r;
}

signed main() {
    fastio;

    cin >> N >> Q;
    for (int i=1; i<=1010000; i++) P[i]=i;
    for (int i=2; i<=1010000; i++) if (P[i]==i) {
        for (int j=i; j<=1010000; j+=i) P[j]=min(P[j], i);
        T[i].nd={{}}; T[i].l={-1}; T[i].r={-1};
    }

    for (int i=1; i<=N; i++) {
        cin >> A[i];
        vector<array<int, 2>> f=ft(A[i]);
        for (array<int, 2> j : f) T[j[0]].upd(i, j[1]);
    }

    while (Q--) {
        char q; cin >> q;
        if (q=='Q') {
            int a, b, c, ans=1; cin >> a >> b >> c;
            vector<int> v;
            for (int i=a; i<=min(a+c, b); i++) {
                vector<array<int, 2>> f=ft(A[i]);
                for (array<int, 2> j : f) v.push_back(j[0]);
            }
            sort(v.begin(), v.end());
            v.erase(unique(v.begin(), v.end()), v.end());

            for (int i : v) {
                ans*=pw(i, T[i].que(a, b)[c]);
            }
            cout << ans << "\n";
        }
        else {
            int a, b; cin >> a >> b;
            vector<array<int, 2>> f=ft(A[a]);
            for (array<int, 2> j : f) T[j[0]].upd(a, 0);
            A[a]=b; f=ft(A[a]);
            for (array<int, 2> j : f) T[j[0]].upd(a, j[1]);
        }
    }

    return 0;
}
