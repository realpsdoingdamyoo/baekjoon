#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+8, MOD=998244353, inf=4e18;

int N;
array<int, 2> V[50505];
array<double, 3> L[50505], U[50505];

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

signed main() {
    fastio;

    cin >> N;

    for (int i=N; i>=1; i--) cin >> V[i][0] >> V[i][1];

    int s=1, e=N-1;
    while (s<=e) {
        int m=s+e>>1;
        for (int i=1; i<=N; i++) {
            U[i][0]=V[(i+m-1)%N+1][1]-V[i][1];
            U[i][1]=V[i][0]-V[(i+m-1)%N+1][0];
            U[i][2]=U[i][0]*V[i][0]+U[i][1]*V[i][1];
        }
        if (HPI()) s=m+1; else e=m-1;
    }
    cout << e << "\n";

    return 0;
}
