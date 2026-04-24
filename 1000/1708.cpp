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
    sort(v.begin()+1, v.end(), [&](array<int, 2> a, array<int, 2> b){
         int c=(b[0]-v[0][0])*(a[1]-v[0][1])-(b[1]-v[0][1])*(a[0]-v[0][0]);
         if(c==0) return a[0]-v[0][0]<b[0]-v[0][0]; else return c>0;
    });
    vector<array<int, 2>> st;
    for(array<int, 2> i : v){
        while(st.size()>1 && ccw(st[st.size()-2], st.back(), i)<=0) st.pop_back();
        st.push_back(i);
    }
    return st;
}

signed main(){
    fastio;

    int n; cin >> n;
    vector<array<int, 2>> v(n);
    for(array<int, 2>& i : v) cin >> i[0] >> i[1];

    cout << hull(v).size();

    return 0;
}
