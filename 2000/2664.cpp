#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e14;

int d, n;
vector<array<int, 3>> v;

int cvx(array<int, 3> a, array<int, 3> b, array<int, 3> c) {
    if (a[0]==b[0]) return (a[1]<b[1])^(b[0]<c[0]); return (a[0]<b[0])^(b[1]>c[1]);
}

signed main() {
    fastio;

    cin >> d >> n;
    v.resize(n);
    for (array<int, 3>& i : v) cin >> i[0] >> i[1];
    for (int i=0; i<n; i++) v[(i+1)%n][2]=cvx(v[i], v[(i+1)%n], v[(i+2)%n]);

    for (int t=1; t<=1000; t++) {

        for (int i=1; i<n-2; i++) {
            if (v[i][2]!=0 || v[i+1][2]!=0) continue;
            if (abs(v[i][0]-v[i+1][0])+abs(v[i][1]-v[i+1][1])>2*d) continue;

            int x, y, z;
            if (abs(v[i][0]-v[i-1][0])+abs(v[i][1]-v[i-1][1])==abs(v[i+2][0]-v[i+1][0])+abs(v[i+2][1]-v[i+1][1])) {
                v.erase(v.begin()+i-1, v.begin()+i+3);
                n-=4;
            }
            else {
                if (abs(v[i][0]-v[i-1][0])+abs(v[i][1]-v[i-1][1])>abs(v[i+2][0]-v[i+1][0])+abs(v[i+2][1]-v[i+1][1])) x=i, y=i+1, z=i+2;
                else x=i-1, y=i, z=i+1;

                array<int, 3> p={v[x][0]^v[y][0]^v[z][0], v[x][1]^v[y][1]^v[z][1], 0};
                v.erase(v.begin()+x, v.begin()+z);
                v[x]=p; n-=2;
            }

            for (int j=0; j<n; j++) v[(j+1)%n][2]=cvx(v[j], v[(j+1)%n], v[(j+2)%n]);
            break;
        }
        rotate(v.begin(), v.begin()+1, v.end());
    }

    vector<array<int, 3>> u=v;

    for (int i=0; i<n; i++) {
        int j=(i+n-1)%n, k=(i+1)%n;
        if (v[i][0]==v[j][0]) {if (v[i][1]>v[j][1] ^ v[i][2]) u[i][1]-=d; else u[i][1]+=d;}
        else {if (v[i][0]>v[j][0] ^ v[i][2]) u[i][0]-=d; else u[i][0]+=d;}
        if (v[i][0]==v[k][0]) {if (v[i][1]>v[k][1] ^ v[i][2]) u[i][1]-=d; else u[i][1]+=d;}
        else {if (v[i][0]>v[k][0] ^ v[i][2]) u[i][0]-=d; else u[i][0]+=d;}
    }

    rotate(u.begin(), min_element(u.begin(), u.end()), u.end());

    cout << n << "\n";
    for (array<int, 3> i : u) cout << i[0] << " " << i[1] << "\n";


    return 0;
}
