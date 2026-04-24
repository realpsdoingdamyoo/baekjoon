#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+8, MOD=998244353, inf=4e18;

int N;
array<int, 2> V[101];
array<double, 3> L[101], U[101];

array<double, 2> crs(array<double, 3> a, array<double, 3> b) {
    return {(a[2]*b[1]-a[1]*b[2]+0.0)/(a[0]*b[1]-a[1]*b[0]), (a[2]*b[0]-a[0]*b[2]+0.0)/(a[1]*b[0]-a[0]*b[1])};
}

bool HPI() {
    deque<array<double, 3>> dq;
    for (int i=1; i<=N; i++) {
        if (dq.empty()) {dq.push_back(U[i]); continue;}
        while (dq.size()>1) {
            int z=dq.size()-1;
            array<double, 2> p=crs(dq[z], dq[z-1]);
            if (U[i][0]*p[0]+U[i][1]*p[1]<U[i][2]) break;
            dq.pop_back();
        }
        if (dq.size()<=1) {dq.push_back(U[i]); continue;}
        array<double, 2> p=crs(dq.back(), U[i]);
        if (dq[0][0]*p[0]+dq[0][1]*p[1]<dq[0][2]) dq.push_back(U[i]);
    }

    return dq.size()>=3;
}

bool solve() {
    cin >> N;
    if (N==0) return false;

    for (int i=1; i<=N; i++) cin >> V[i][0] >> V[i][1];
    for (int i=1; i<=N; i++) {
        L[i][0]=V[i%N+1][1]-V[i][1]; L[i][1]=V[i][0]-V[i%N+1][0];
        L[i][2]=L[i][0]*V[i][0]+L[i][1]*V[i][1];
    }

    double s=0, e=10000;
    while (e-s>1e-6) {
        double m=(s+e)/2;
        for (int i=1; i<=N; i++) {
            U[i]=L[i];
            double d=sqrt(U[i][0]*U[i][0]+U[i][1]*U[i][1]);
            double dx=-U[i][0]/d*m, dy=-U[i][1]/d*m;
            U[i][2]=U[i][0]*(V[i][0]+dx)+U[i][1]*(V[i][1]+dy);
        }
        if (HPI()) s=m; else e=m;
    }
    cout << s << "\n";

    return true;
}

signed main() {
    fastio;

    cout.precision(10);
    while (solve()){}

    return 0;
}
