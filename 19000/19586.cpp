#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=4e18;

int ccw(array<int, 2> a, array<int, 2> b, array<int, 2> c){
    return (b[1]-a[1])*(c[0]-a[0])-(c[1]-a[1])*(b[0]-a[0]);
}

vector<array<int, 2>> hull(vector<array<int, 2>> v){
    int n=v.size();
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    sort(v.begin()+1, v.end(), [&](array<int, 2> a, array<int, 2> b){
         int c=(b[0]-v[0][0])*(a[1]-v[0][1])-(b[1]-v[0][1])*(a[0]-v[0][0]);
         if(c==0) return a[0]-v[0][0]<b[0]-v[0][0]; else return c<0;
    });
    vector<array<int, 2>> st;
    for(array<int, 2> i : v){
        while(st.size()>1 && ccw(st[st.size()-2], st.back(), i)>=0) st.pop_back();
        st.push_back(i);
    }
    return st;
}

array<int, 2> su(array<int, 2> a, array<int, 2> b){
    return {a[0]-b[0], a[1]-b[1]};
}

int dot(array<int, 2> a, array<int, 2> b){
    return a[0]*b[0]+a[1]*b[1];
}

int cr(array<int, 2> a, array<int, 2> b){
    return a[0]*b[1]-b[0]*a[1];
}

double dist(array<int, 2> a, array<int, 2> b){
    return sqrt((a[0]-b[0])*(a[0]-b[0])+(a[1]-b[1])*(a[1]-b[1]));
}

double Dist(array<int, 2> a, array<int, 2> b, array<int, 2> d){
    array<int, 2> r={a[0]+d[0], a[1]+d[1]};
    return abs(cr(su(b, a), su(r, a)))/dist(a, r);
}

signed main(){
    fastio;

    cout.precision(13);
    int n; cin >> n;
    vector<array<int, 2>> v(n);
    for(array<int, 2>& i : v) cin >> i[0] >> i[1];
    v=hull(v);

    if(v.size()==1){cout << "0"; return 0;}
    if(v.size()==2){
        array<int, 2> mn=*min_element(v.begin(), v.end());
        array<int, 2> mx=*max_element(v.begin(), v.end());
        cout << dist(mn, mx)*2; return 0;
    }


    n=v.size();
    for(int i=0; i<3*n; i++) v.push_back(v[i]);

    auto _u=[&v](int i, int j){
        return cr(su(v[i+1], v[i]), su(v[j+1], v[j]))>0;
    };
    auto _l=[&v](int i, int j){
        return cr(su(v[i+1], v[i]), su(v[j+1], v[j]))>0 || dot(su(v[i+1], v[i]), su(v[j+1], v[j]))<0;
    };
    auto _r=[&v](int i, int j){
        return cr(su(v[i+1], v[i]), su(v[j+1], v[j]))>0 && dot(su(v[i+1], v[i]), su(v[j+1], v[j]))>0;
    };

    int u=1, l=1, r=1;
    double ans=inf;

    for(int i=0; i<n; i++){
        if(u%n==i) u++; while(_u(i, u)) u++;
        if(l%n==i) l++; while(_l(i, l)) l++;
        if(r%n==i) r++; while(_r(i, r)) r++;

        array<int, 2> v1=su(v[i+1], v[i]);
        array<int, 2> v2={v1[1], -v1[0]};
        double nw=Dist(v[i], v[u], v1)+Dist(v[l], v[r], v2);
        ans=min(ans, nw);
    }
    cout << ans*2;

    return 0;
}
