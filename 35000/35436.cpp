#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, inf=1e18;
 
int N, Q;
array<int, 2> V[505050];
vector<array<int, 2>> U, D;
int ccw(array<int, 2> a, array<int, 2> b, array<int, 2> c) {
    return a[0]*b[1]+b[0]*c[1]+c[0]*a[1]-a[1]*b[0]-b[1]*c[0]-c[1]*a[0];
}
int crs(array<int, 2> a, array<int, 2> b) {
    return ceil((a[1]-b[1]+0.0)/(b[0]-a[0]));
}
 
int MX[404040], T=200020;
set<array<int, 2>> h;
 
signed main() {
    fastio;
 
    cin >> N;
    for (int j : {0, 1}) for (int i=1; i<=N; i++) cin >> V[i][j];
    sort(V+1, V+N+1);
    for (int i=1; i<=N; i++) {
        while (U.size()>=2 && ccw(U[U.size()-2], U[U.size()-1], V[i])<=0) U.pop_back();
        while (D.size()>=2 && ccw(D[D.size()-2], D[D.size()-1], V[i])>=0) D.pop_back();
        U.push_back(V[i]); D.push_back(V[i]);
    }
    U.pop_back();
    while (D.size()) U.push_back(D.back()), D.pop_back();
    U.pop_back();
 
    for (int i=0; i<=2*T; i++) MX[i]=-inf;
 
    for (array<int, 2> i : U) for (array<int, 2> j : U) {
        int v=i[0]+j[1]-i[1]-j[0];
        MX[v+T]=max(MX[v+T], i[0]*j[1]-j[0]*i[1]);
    }
 
    vector<array<int, 2>> st;
    for (int i=-T; i<=T; i++) if (MX[i+T]!=-inf){
        array<int, 2> g={i, MX[i+T]};
        while (st.size()>=2 && crs(st[st.size()-2], st.back())>=crs(st.back(), g)) st.pop_back();
        st.push_back(g);
    }
 
    h.insert({-inf, 0});
    for (int i=1; i<st.size(); i++) {
        int c=crs(st[i-1], st[i]);
        h.insert({c, i});
    }
 
    cin >> Q;
    while (Q--) {
        int X; cin >> X;
        array<int, 2> p=*prev(h.upper_bound({X, inf}));
        cout << st[p[1]][0]*X+st[p[1]][1] << "\n";
    }
 
    return 0;
}
