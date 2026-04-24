#include <bits/stdc++.h>
using namespace std;
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e4+7, MOD=998244353, inf=2e18;

#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

int n, pv;
array<int, 2> v[4040];
int lc[4040];
array<int, 3> line[8080808];

bool cmp(const array<int, 3>& a, const array<int, 3>& b){
    if(1LL*a[1]*b[0]==1LL*b[1]*a[0]) return a[2]<b[2];
    return 1LL*a[1]*b[0]<1LL*b[1]*a[0];
}

double dis(const array<int, 2> &a, const array<int, 2> &b, const array<int, 2> &c){
    double crs=abs(1LL*(b[0]-a[0])*(a[1]-c[1])-1LL*(a[0]-c[0])*(b[1]-a[1]));
    double ab=sqrt(1LL*(b[0]-a[0])*(b[0]-a[0])+1LL*(b[1]-a[1])*(b[1]-a[1]));
    return crs/ab;
}

signed main(){
    fastio;

    int n; cin >> n;
    for(int i=1; i<=n; i++) cin >> v[i][0] >> v[i][1];
    sort(v+1, v+n+1);

    for(int i=1; i<=n; i++) for(int j=i+1; j<=n; j++)
        line[pv++]={v[j][0]-v[i][0], v[j][1]-v[i][1], i*mod+j};

    sort(line, line+pv, cmp);

    for(int i=1; i<=n; i++) lc[i]=i;

    double ans=0;
    for(int i=0, j=0; i<pv; i=j){
        while(j<pv && 1LL*line[i][1]*line[j][0]==1LL*line[j][1]*line[i][0]) j++;

        for(int k=i; k<j; k++){
            int x=lc[line[k][2]/mod], y=lc[line[k][2]%mod];
            if(x>y) swap(x, y);

            double ret=inf;
            if(x!=1) ret=min(ret, dis(v[x], v[y], v[x-1]));
            if(y!=n) ret=min(ret, dis(v[x], v[y], v[y+1]));
            ans=max(ans, ret);
        }
        for(int k=i; k<j; k++){
            int x=lc[line[k][2]/mod], y=lc[line[k][2]%mod];
            swap(lc[line[k][2]/mod], lc[line[k][2]%mod]); swap(v[x], v[y]);
        }
    }
    cout.precision(14);
    cout << ans;

    return 0;
}
