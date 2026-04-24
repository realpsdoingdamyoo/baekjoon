#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2147483647;

int n, q;
vector<array<int, 2>> u, v;
vector<array<int, 2>> con;
vector<int> vex;

double meet(array<int, 2> a, array<int, 2> b){
    return (b[1]-a[1]+0.0)/(a[0]-b[0]);
}

array<int, 2> xup(int x, int y){
    int s=0, e=vex.size()-1;
    while(s<=e){
        int m=s+e>>1;
        if(vex[m]<=x) s=m+1;
        else e=m-1;
    }
    if(con[e][0]==1){
        if(e<vex.size()-1) y=min(vex[e+1], y);
        if(con[e][1]<=0) return {x*con[e][0]+con[e][1], 1};
        int p=(y-x)/con[e][1];
        if(p==0) return {x*con[e][0]+con[e][1], 1};
        return {x+con[e][1]*p, p};
    }
    return {x*con[e][0]+con[e][1], 1};
}

signed main(){
    fastio;

    cin >> n >> q; v.resize(n);
    for(int i=0; i<n; i++) cin >> v[i][0] >> v[i][1];
    sort(v.begin(), v.end());
    for(array<int, 2> i : v){
        while(u.size() && u.back()[1]<=i[1]) u.pop_back();
        u.push_back(i);
    } n=u.size();

    for(int i=0; i<n; i++){
        while(con.size()>=2 && meet(con[con.size()-2], u[i])>meet(con[con.size()-1], u[i])) con.pop_back();
        con.push_back(u[i]);
    }

    vex.push_back(-inf);
    for(int i=1; i<con.size(); i++){
        vex.push_back(ceil(meet(con[i-1], con[i])));
    }

    while(q--){
        int x, y; cin >> x >> y;
        int cnt=0;
        while(x<y){
            array<int, 2> nx=xup(x, y);
            if(nx[0]<=x){cnt=-1; break;}
            cnt+=nx[1]; x=nx[0];
        }
        cout << cnt << "\n";
    }

    return 0;
}
