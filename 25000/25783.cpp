#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e17;

int N;
array<double, 2> V[101010];
array<double, 3> L[101010], U[101010];

double ccw(array<double, 2> a, array<double, 2> b, array<double, 2> c) {
    return a[0]*b[1]+b[0]*c[1]+c[0]*a[1]-a[1]*b[0]-b[1]*c[0]-c[1]*a[0];
}

double frp(vector<array<double, 2>> C) {
    int M=C.size(), j=0; double ret=0;
    for (int i=0; i<M; i++) {
        if (i==j) j=(j+1)%M;
        while (1) {
            array<double, 2> I={C[(i+1)%M][0]-C[i][0], C[(i+1)%M][1]-C[i][1]};
            array<double, 2> J={C[(j+1)%M][0]-C[j][0], C[(j+1)%M][1]-C[j][1]};
            ret=max(ret, (C[i][0]-C[j][0])*(C[i][0]-C[j][0])+(C[i][1]-C[j][1])*(C[i][1]-C[j][1]));
            if (ccw(I, {0, 0}, J)<0) j=(j+1)%M; else break;
        }
    }
    return sqrt(ret);
}

array<double, 2> crs(array<double, 3> a, array<double, 3> b) {
    return {(a[2]*b[1]-a[1]*b[2]+0.0)/(a[0]*b[1]-a[1]*b[0]), (a[2]*b[0]-a[0]*b[2]+0.0)/(a[1]*b[0]-a[0]*b[1])};
}

bool cont(array<double, 3> a, array<double, 3> b, array<double, 3> c) {
    if (abs(a[0]*b[1]-b[0]*a[1])<1e-9) return false;
    array<double, 2> p=crs(a, b);
    return c[0]*p[0]+c[1]*p[1]>=c[2]-(1e-9);
}

bool HPI(double r) {
    deque<array<double, 3>> dq;
    for (int i=1; i<=N; i++) {
        while (dq.size()>=2 && cont(dq[dq.size()-2], dq[dq.size()-1], U[i])) dq.pop_back();
        while (dq.size()>=2 && cont(dq[0], dq[1], U[i])) dq.pop_front();
        if (dq.size()<2 || !cont(dq[dq.size()-1], U[i], dq[0])) dq.push_back(U[i]);
    }

    //for (array<double, 3> i : dq) cout << i[0] << " " << i[1] << " " << i[2] << "\n";

    if (dq.size()<3) return false;

    int M=dq.size();
    vector<array<double, 2>> vec;
    for (int i=0; i<M; i++) vec.push_back(crs(dq[i], dq[(i+1)%M]));

    return frp(vec)>=r;
}


signed main() {
    fastio;

    cin >> N;
    double D; cin >> D;
    for (int i=N; i>=1; i--) cin >> V[i][0] >> V[i][1];
    for (int i=1; i<=N; i++) {
        L[i][0]=V[i%N+1][1]-V[i][1]; L[i][1]=V[i][0]-V[i%N+1][0];
        L[i][2]=L[i][0]*V[i][0]+L[i][1]*V[i][1];
        U[i]=L[i];
    }

    double s=0, e=1e7;
    while (e-s>1e-9) {
        double m=(s+e)/2;
        for (int i=1; i<=N; i++) {
            U[i]=L[i];
            double d=sqrt(U[i][0]*U[i][0]+U[i][1]*U[i][1]);
            double dx=-U[i][0]/d*m, dy=-U[i][1]/d*m;
            U[i][2]=U[i][0]*(V[i][0]+dx)+U[i][1]*(V[i][1]+dy);
        }
        if (HPI(D)) s=m; else e=m;
    }

    cout.precision(10);
    cout << s;

    return 0;
}
