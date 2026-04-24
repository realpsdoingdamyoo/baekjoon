#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=4e18, bnd=1e10;

int n, m, ans;
int a[505050], b[505050];
array<int, 2> r[505050], c[505050];

int ccw(array<int, 2> a, array<int, 2> b, array<int, 2> c){
    return (b[0]-a[0])*(c[1]-a[1])-(b[1]-a[1])*(c[0]-a[0]);
}

vector<int> hull(int s, int* x){
    vector<array<int, 2>> ret;
    for(int i=0; i<=s; i++){
        while(ret.size()>=2 && ccw(ret[ret.size()-2], ret[ret.size()-1], {i, x[i]})<=0) ret.pop_back();
        ret.push_back({i, x[i]});
    }
    vector<int> rret;
    for(array<int, 2>& i : ret) rret.push_back(i[0]);
    return rret;
}

signed main(){
    fastio;

    cin >> n >> m; n--; m--;
    for(int i=n; i>=0; i--) cin >> a[i];
    for(int i=0; i<=m; i++) cin >> b[i];
    ans=m*a[0]+n*b[0];

    vector<int> rh=hull(n, a), ch=hull(m, b);
    int R=rh.size()-1, C=ch.size()-1;

    for(int i=1; i<=R; i++) r[i]={a[rh[i]]-a[rh[i-1]], rh[i]-rh[i-1]};
    for(int i=1; i<=C; i++) c[i]={b[ch[i]]-b[ch[i-1]], ch[i]-ch[i-1]};

    int p=C, hei=m, sum=b[m]-b[0];

    for(int i=1; i<=R; i++){
        while(p>0 && c[p][0]*r[i][1]+c[p][1]*r[i][0]>0){
            hei-=c[p][1]; sum-=c[p][0]; p--;
        }
        ans+=sum*r[i][1]+r[i][0]*hei;
    }
    cout << ans << "\n";

    return 0;
}
