#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=4e18;

array<int, 5> v[6];
array<int, 5> c[5];

bool solve() {
    for (int i=1; i<=3; i++) {
        for (int j=i; j<=4; j++) if (c[j][i]) swap(c[i], c[j]);
        assert(c[i][i]);

        for (int j=i+1; j<=4; j++) {
            for (int k=i; k<=4; k++) c[j][k]*=c[i][i];
            for (int k=4; k>=i; k--) c[j][k]-=c[i][k]*c[j][i]/c[i][i];
        }
    }
    if (c[4][4]) return false;

    int C=c[3][4]/c[3][3];
    c[2][4]-=C*c[2][3];
    int B=c[2][4]/c[2][2];
    c[1][4]-=B*c[1][2]+C*c[1][3];
    int A=c[1][4]/c[1][1];
    cout << A << " " << B << " " << C << "\n";
    return true;
}

signed main(){
    v[1]={0, 1, 0, 0};
    v[2]={0, 0, 1, 0};
    v[3]={0, 0, 0, 1};
    v[4]={0, 1, 1, 1};
    v[5]={0, 3, 2, 1};
    for (int i=1; i<=5; i++) {
        cout << v[i][1] << " " << v[i][2] << " " << v[i][3] << "\n"; cout.flush();
        cin >> v[i][4];
    }

    c[1]=v[1]; c[2]=v[2]; c[3]=v[3]; c[4]=v[4];
    if (solve()) return 0;
    c[1]=v[1]; c[2]=v[2]; c[3]=v[3]; c[4]=v[5];
    if (solve()) return 0;
    c[1]=v[1]; c[2]=v[2]; c[3]=v[4]; c[4]=v[5];
    if (solve()) return 0;
    c[1]=v[1]; c[2]=v[3]; c[3]=v[4]; c[4]=v[5];
    if (solve()) return 0;
    c[1]=v[2]; c[2]=v[3]; c[3]=v[4]; c[4]=v[5];
    if (solve()) return 0;

    return 0;
}
