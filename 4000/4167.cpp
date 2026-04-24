#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, inf=4e18;

void solve() {
    double A, B, C, D, R=6371009, pi=acos(-1);
    cin >> A >> B >> C >> D;
    A*=pi/180; B*=pi/180; C*=pi/180; D*=pi/180;

    array<double, 3> P, Q;
    P={R*cos(B)*cos(A), R*sin(B)*cos(A), R*sin(A)};
    Q={R*cos(D)*cos(C), R*sin(D)*cos(C), R*sin(C)};

    double dis, rds;
    dis=sqrt((P[0]-Q[0])*(P[0]-Q[0])+(P[1]-Q[1])*(P[1]-Q[1])+(P[2]-Q[2])*(P[2]-Q[2]));
    rds=2*asin(dis/2/R)*R;
    cout << (int)(rds-dis+0.5) << "\n";
}

signed main(){
    fastio;

    int T; cin >> T;
    while (T--) solve();

    return 0;
}
