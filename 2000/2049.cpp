#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e17;

int n, t;
array<int, 2> v[101010];
vector<array<int, 2>> U, D;

int ccw(array<int, 2> a, array<int, 2> b, array<int, 2> c) {
    return a[0]*b[1]+b[0]*c[1]+c[0]*a[1]-a[1]*b[0]-b[1]*c[0]-c[1]*a[0];
}

signed main() {
    fastio;

    cin >> n;
    for (int i=1; i<=n; i++) cin >> v[i][0] >> v[i][1];
    sort(v+1, v+n+1);
    for (int i=1; i<=n; i++) {
        while (U.size()>=2 && ccw(U[U.size()-2], U[U.size()-1], v[i])<=0) U.pop_back(); U.push_back(v[i]);
        while (D.size()>=2 && ccw(D[D.size()-2], D[D.size()-1], v[i])>=0) D.pop_back(); D.push_back(v[i]);
    }

    vector<array<int, 2>> C=U; C.pop_back();
    reverse(D.begin(), D.end()); D.pop_back();
    for (array<int, 2> i : D) C.push_back(i);

    int M=C.size(), j=0, ans=0, cnt=0;
    for (int i=0; i<M; i++) {
        if (i==j) j=(j+1)%M;
        while (1) {
            array<int, 2> I={C[(i+1)%M][0]-C[i][0], C[(i+1)%M][1]-C[i][1]};
            array<int, 2> J={C[(j+1)%M][0]-C[j][0], C[(j+1)%M][1]-C[j][1]};
            ans=max(ans, (C[i][0]-C[j][0])*(C[i][0]-C[j][0])+(C[i][1]-C[j][1])*(C[i][1]-C[j][1]));
            cnt++;
            if (ccw(I, {0, 0}, J)<0) j=(j+1)%M; else break;
        }
    }
    assert(cnt<10*M);
    cout << ans;

    return 0;
}
