#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+8, MOD=998244353, inf=4e18;

vector<array<int, 2>> Uh, Dh;
int X, Y;

int ccw(array<int, 2> a, array<int, 2> b, array<int, 2> c) {
    return a[0]*b[1]+b[0]*c[1]+c[0]*a[1]-a[1]*b[0]-b[1]*c[0]-c[1]*a[0];
}

void build() {
    int G; cin >> G;
    vector<array<int, 2>> vec(G);
    for (array<int, 2>& i : vec) cin >> i[0] >> i[1];
    sort(vec.begin(), vec.end());
    vector<array<int, 2>> U={vec[0]}, D={vec[0]};
    for (array<int, 2> i : vec) {
        while (U.size()>=2 && ccw(U[U.size()-2], U[U.size()-1], i)>=0) U.pop_back(); U.push_back(i);
        while (D.size()>=2 && ccw(D[D.size()-2], D[D.size()-1], i)<=0) D.pop_back(); D.push_back(i);
    }

    int x=vec[0][0], y=vec[0][1];
    for (int i=U.size()-1; i>=1; i--) U[i][0]-=U[i-1][0], U[i][1]-=U[i-1][1];
    for (int i=D.size()-1; i>=1; i--) D[i][0]-=D[i-1][0], D[i][1]-=D[i-1][1];
    X+=x; Y+=y;
    for (int i=1; i<U.size(); i++) Uh.push_back(U[i]);
    for (int i=1; i<D.size(); i++) Dh.push_back(D[i]);
}

signed main() {
    fastio;

    int N, x, y; cin >> N;
    for (int i=1; i<=N; i++) build();
    sort(Uh.begin(), Uh.end(), [&](array<int, 2> a, array<int, 2> b){return a[1]*b[0]>a[0]*b[1];});
    sort(Dh.begin(), Dh.end(), [&](array<int, 2> a, array<int, 2> b){return a[1]*b[0]<a[0]*b[1];});
    int ans=X*X+Y*Y;
    x=X; y=Y; for (array<int, 2> i : Uh) x+=i[0], y+=i[1], ans=max(ans, x*x+y*y);
    x=X; y=Y; for (array<int, 2> i : Dh) x+=i[0], y+=i[1], ans=max(ans, x*x+y*y);
    cout << ans;

    return 0;
}
