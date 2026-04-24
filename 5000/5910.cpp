#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=4e18;

bool cmp(array<int, 2> a, array<int, 2> b){
    if(a[0]>a[1] && b[0]>b[1]) return a[1]>b[1];
    if(a[0]>a[1] && b[0]<b[1]) return false;
    if(a[0]<a[1] && b[0]>b[1]) return true;
    if(a[0]<a[1] && b[0]<b[1]) return a[0]<b[0];
}

signed main(){
    fastio;

    int n, T; cin >> n;
    vector<array<int, 2>> v(n);
    for(array<int, 2>& i : v) cin >> i[0] >> i[1];
    sort(v.begin(), v.end(), cmp);

    vector<int> t(n), u(n);
    T=0; for(int i=0; i<n; i++) T=t[i]=T+v[i][0];
    T=0;
    for(int i=0; i<n; i++){
        T=max(T, t[i]);
        T=u[i]=T+v[i][1];
    }
    cout << T << "\n";

    return 0;
}
