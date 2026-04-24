#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=4e18, bnd=1e10;

int n, m;
vector<array<int, 2>> v, u, c;

int ccw(array<int, 2>& a, array<int, 2>& b, array<int, 2>& c){
    return a[0]*b[1]+b[0]*c[1]+c[0]*a[1]-a[1]*b[0]-b[1]*c[0]-c[1]*a[0];
}
bool cmp(array<int, 2>& a, array<int, 2>& b){
    if(ccw(u[0], a, b)==0) return (a[0]-u[0][0])+abs(a[1]-u[0][1])<(b[0]-u[0][0])+abs(b[1]-u[0][1]);
    return ccw(u[0], a, b)>0;
}

int dist(array<int, 2>& a, array<int, 2>& b, array<int, 2>& c){
    int p=a[1]-b[1], q=b[0]-a[0], r=a[0]*b[1]-a[1]*b[0];
    return abs(p*c[0]+q*c[1]+r);
}

signed main(){
    //fastio;

    cin >> n; v.resize(n);
    for(int i=0; i<n; i++) cin >> v[i][0] >> v[i][1];
    cin >> m; u.resize(m);
    for(int i=0; i<m; i++) cin >> u[i][0] >> u[i][1];

    sort(u.begin(), u.end());
    sort(u.begin()+1, u.end(), cmp);
    for(array<int, 2>& i : u){
        while(c.size()>=2 && ccw(c[c.size()-2], c[c.size()-1], i)<=0) c.pop_back();
        c.push_back(i);
    }

    rotate(v.begin(), min_element(v.begin(), v.end()), v.end());
    int l=c.size();
    int s=0, ret=0;
    for(int i=0, j=1, k=0; i<n; i++){
        while(ccw(v[i], v[(j+1)%n], c[k])>0){
            if(l>1 && dist(v[i], v[(j+1)%n], c[k])>=dist(v[i], v[(j+1)%n], c[(k+1)%l])){k=(k+1)%l; continue;}
            if(l>1 && ccw(v[i], v[(j+1)%n], c[(k+1)%l])<=0){k=(k+1)%l; continue;}
            s+=abs(ccw(v[i], v[j], v[(j+1)%n]));
            j=(j+1)%n;
        }
        ret=max(ret, s);
        s-=abs(ccw(v[i], v[(i+1)%n], v[j]));
        if(i+1==j) j=(j+1)%n;
    }
    cout << ret;

    return 0;
}
