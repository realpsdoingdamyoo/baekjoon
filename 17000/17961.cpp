#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e17;

struct bck {
    int Lv, Rv, A;
    vector<int> v, u;

    void bu() {
        u=v;
        sort(u.begin(), u.end());
    }

    void cal() {
        int m=v.size(); A=0;
        int L1=inf, L2=inf;
        for (int j=0; j<m; j++) {
            int i=v[j];

            L1=min(L1, i);
            if (L1<i) L2=min(L2, i);
            if (L2<i) A=1;
        }
        int R1=-inf, R2=-inf;
        for (int j=m-1; j>=0; j--) {
            int i=v[j];

            R1=max(R1, i);
            if (R1>i) R2=max(R2, i);
        }
        Lv=L2; Rv=R2;
    }
};

vector<bck> V;

void split(int p, int x) {
    bck nw;
    for (int i=x; i<V[p].v.size(); i++) nw.v.push_back(V[p].v[i]);
    while (V[p].v.size()>x) V[p].v.pop_back();
    V.insert(V.begin()+p+1, nw);
    V[p].bu(); V[p+1].bu();
    V[p].cal(); V[p+1].cal();
}

void vecmrg(vector<int>& a, vector<int>& b, vector<int>& c) {
    for (int i=0, j=0; i<b.size() || j<c.size();) {
        if (i==b.size()) a.push_back(c[j++]);
        else if (j==c.size()) a.push_back(b[i++]);
        else if (b[i]<c[j]) a.push_back(b[i++]);
        else a.push_back(c[j++]);
    }
}

vector<int> t;
void merge(int p) {
    for (int i : V[p+1].v) V[p].v.push_back(i);
    t=V[p].u; V[p].u.clear();
    vecmrg(V[p].u, t, V[p+1].u);
    V.erase(V.begin()+p+1); V[p].cal();
}

int div(int m){
    int d=0;
    for (int i=0; i<V.size(); i++) {
        if (m==d) return i;
        if (V[i].v.size()+d>m) {split(i, m-d); return i+1;}
        d+=V[i].v.size();
    }
    return V.size();
}

int N;
const int X=400;

signed main() {
    fastio;

    cin >> N;
    V.resize(N/X+1);
    for (int i=1; i<=N; i++) {
        int x; cin >> x;
        V[i/X].v.push_back(x);
    }

    for (bck& i : V) i.bu(), i.cal();

    int Q; cin >> Q;
    while (Q--) {
        int l, r, k; cin >> l >> r >> k;
        int a=div(l-1), b=div(r-k), c=div(r);
        rotate(V.begin()+a, V.begin()+b, V.begin()+c);

        for (int i=(int)V.size()-1; i>0; i--) {
            if (V[i].v.size()+V[i-1].v.size()<=X) merge(i-1);
        }

        int L1=inf, L2=inf, A=0;
        for (bck& i : V) {
            if (L1<i.Rv) A=1;
            if (L2<i.u.back()) A=1;
            if (i.A) A=1;

            if (L1<i.u.back()) L2=min(L2, *lower_bound(i.u.begin(), i.u.end(), L1));
            L2=min(L2, i.Lv);
            L1=min(L1, i.u[0]);
        }
        cout << (A?"YES\n":"NO\n");
    }

    return 0;
}
