#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e8;

int n, m;
array<int, 2> v[303030];
array<int, 2> u[303030];

int ccw(array<int, 2> a, array<int, 2> b, array<int, 2> c) {
    return a[0]*b[1]+b[0]*c[1]+c[0]*a[1]-a[1]*b[0]-b[1]*c[0]-c[1]*a[0]>=0;
}

signed main() {
    fastio;

    cin >> n;
    for (int i=1; i<=n; i++) cin >> v[i][0] >> v[i][1];
    sort(v+1, v+n+1, [&](array<int, 2> a, array<int, 2> b){return a[0]*mod-a[1]<b[0]*mod-b[1];});
    vector<array<int, 2>> st1={{0, 0}}, st2={{0, 0}};

    for (int i=1; i<=n; i++) st1[0][1]=max(st1[0][1], v[i][1]);
    for (int i=1; i<=n; i++) {
        while (st1.size()>=2 && ccw(st1[st1.size()-2], st1[st1.size()-1], v[i])) {
            u[++m]=st1.back(); st1.pop_back();
        }
        st1.push_back(v[i]);
    }

    sort(u+1, u+m+1, [&](array<int, 2> a, array<int, 2> b){return a[0]*mod-a[1]<b[0]*mod-b[1];});

    for (int i=1; i<=m; i++) st2[0][1]=max(st2[0][1], u[i][1]);
    for (int i=1; i<=m; i++) {
        while (st2.size()>=2 && ccw(st2[st2.size()-2], st2[st2.size()-1], u[i])) {
            st2.pop_back();
        }
        st2.push_back(u[i]);
    }

    int ans=0;
    for (int i=1; i<st1.size(); i++) for (int j=i+1; j<st1.size(); j++) {
        ans=max(ans, st1[i][0]*st1[j][0]+st1[i][1]*st1[j][1]);
    }
    for (int i=1; i<st1.size(); i++) for (int j=1; j<st2.size(); j++) {
        ans=max(ans, st1[i][0]*st2[j][0]+st1[i][1]*st2[j][1]);
    }
    cout << ans;



    return 0;
}
