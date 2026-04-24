#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=1e18;

const int X=450;
int N, M, Q;
int BS[X];

struct HINT {
    int S, E, id;
    int G[X];

    void update(int x) {
        int d=x-S;
        for (int i=0; i<X; i++) BS[i]+=G[i]*d;
    }
} H[202020];
array<int, 3> V[202020];

array<int, 3> add(array<int, 3> ar, int x) {ar[2]+=x; return ar;}
array<int, 3> mul(array<int, 3> ar, int x) {return {ar[0], ar[1]*x, ar[2]*x};}

array<int, 3> g(int x) {
    if (x==V[x][0]) return {x, 1, 0};
    return V[x]=add(mul(g(V[x][0]), V[x][1]), V[x][2]);
}

bool mrg(int X1, int T1, int X2, int T2, int R) {
    array<int, 3> p1=mul(g(X1), T1), p2=mul(g(X2), T2);
    R=R-p1[2]-p2[2]; X1=p1[0]; T1=p1[1]; X2=p2[0]; T2=p2[1];

    if (X1>X2) swap(X1, X2), swap(T1, T2);
    if (T1<0) T1=-T1, T2=-T2, R=-R;
    if (X1==X2) {
        if (T2==-1) return R==0;
        HINT &h=H[X1];
        if (R%2==1 || R<h.S*2 || h.E*2<R) return false;

        h.update(R/2);
        h.S=h.E=R/2;
        return true;
    }

    HINT &h1=H[X1], &h2=H[X2];

    if (T2==1) {
        if (R<h1.S+h2.S || h1.E+h2.E<R) return false;
        V[X2]={X1, -1, R};
        h1.update(max(h1.S, R-h2.E));
        h1.S=max(h1.S, R-h2.E); h1.E=min(h1.E, R-h2.S);
        h2.update(R-h1.S);
        for (int i=0; i<X; i++) h1.G[i]-=h2.G[i];
    }
    else {
        if (R<h1.S-h2.E || h1.E-h2.S<R) return false;
        V[X2]={X1, 1, -R};
        h1.update(max(h1.S, h2.S+R));
        h1.S=max(h1.S, h2.S+R); h1.E=min(h1.E, h2.E+R);
        h2.update(h1.S-R);
        for (int i=0; i<X; i++) h1.G[i]+=h2.G[i];
    }
    return true;
}

int gtv(int x) {
    array<int, 3> r=g(x);
    return H[r[0]].S*r[1]+r[2];
}

int sum(int l, int r) {
    int ret=0;
    while (l<=r && l%X!=0) ret+=gtv(l), l++;
    while (l<=r && r%X!=X-1) ret+=gtv(r), r--;
    while (l<=r) ret+=BS[l/X], l+=X;
    return ret;
}

signed main(){
    fastio;

    cin >> N >> M >> Q;

    for (int i=1; i<=N; i++) {
        H[i].S=0; H[i].E=M; H[i].id=i;
        H[i].G[i/X]++;
        V[i]={i, 1, 0};
    }

    while (Q--) {
        int t, x, y, z; cin >> t;
        if (t==1 || t==2) {
            cin >> x >> y >> z;
            cout << mrg(x, 1, y, t==1?1:-1, z) << "\n";
        }
        else {
            cin >> x >> y;
            cout << sum(x, y) << "\n";
        }
    }

    return 0;
}
