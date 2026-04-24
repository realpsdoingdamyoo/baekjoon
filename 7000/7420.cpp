#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=4e18;

int l;

int ccw(array<int, 2> a, array<int, 2> b, array<int, 2> c){
    return (b[1]-a[1])*(c[0]-a[0])-(c[1]-a[1])*(b[0]-a[0]);
}

double dist(array<int, 2> a, array<int, 2> b){
    return sqrt((a[0]-b[0])*(a[0]-b[0])+(a[1]-b[1])*(a[1]-b[1]));
}

void hull(vector<array<int, 2>> v){
    int n=v.size();
    sort(v.begin(), v.end());
    sort(v.begin()+1, v.end(), [&](array<int, 2> a, array<int, 2> b){
         int c=(b[0]-v[0][0])*(a[1]-v[0][1])-(b[1]-v[0][1])*(a[0]-v[0][0]);
         if(c==0) return a[0]-v[0][0]<b[0]-v[0][0]; else return c>0;
    });
    vector<array<int, 2>> st;
    for(array<int, 2> i : v){
        while(st.size()>1 && ccw(st[st.size()-2], st.back(), i)<=0) st.pop_back();
        st.push_back(i);
    }

    st.push_back(st[0]);
    double ret;
    for(int i=0; i<st.size()-1; i++) ret+=dist(st[i], st[i+1]);
    cout << round(ret+l*acos(-1)*2);
}

signed main(){
    fastio;

    int n; cin >> n >> l;
    vector<array<int, 2>> v(n);
    for(array<int, 2>& i : v) cin >> i[0] >> i[1];
    hull(v);

    return 0;
}
