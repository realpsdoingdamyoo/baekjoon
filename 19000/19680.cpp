#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;

int N;
array<int, 2> V[101010], U[101010];
array<int, 3> P[202020];

struct cmp {
    bool operator()(const array<int, 4>& a, const array<int, 4>& b) const {
        int x=max(a[0], b[0]); double ay, by;
        if (a[0]==a[2]) ay=a[1];
        else ay=a[1]+(a[3]-a[1]+0.0)/(a[2]-a[0])*(x-a[0]);
        if (b[0]==b[2]) by=b[1];
        else by=b[1]+(b[3]-b[1]+0.0)/(b[2]-b[0])*(x-b[0]);
        return ay<by;
    }
};

map<array<int, 4>, array<int, 2>, cmp> mp;

signed main(){
    fastio;

    cin >> N;
    for (int i=1; i<=N; i++) {
        cin >> V[i][0] >> V[i][1];
        cin >> U[i][0] >> U[i][1];
        if (V[i]>U[i]) swap(V[i], U[i]);
        P[i*2-1]={V[i][0], V[i][1], i};
        P[i*2]={U[i][0], U[i][1], i};
    }
    sort(P+1, P+2*N+1);
    mp[{-inf, -inf, -inf, inf}]={0, 0};

    for (int i=1; i<=N*2; i++) {
        array<int, 2> p={P[i][0], P[i][1]};
        int x=P[i][2];

        array<int, 4> line={V[x][0], V[x][1], U[x][0], U[x][1]};
        if (p==V[x]) {
            mp[line]=p;
            map<array<int, 4>, array<int, 2>>::iterator it=prev(mp.find(line));
            array<int, 2> itp=(*it).second;

            if (i>1) cout << itp[0] << " " << itp[1] << " " << p[0] << " " << p[1] << "\n";
            mp[(*it).first]=p;
        }
        else {
            map<array<int, 4>, array<int, 2>>::iterator it=prev(mp.find(line));
            mp[(*it).first]=p; mp.erase(next(it));
        }
    }

    return 0;
}
