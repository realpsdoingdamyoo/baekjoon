#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=4e18;

signed main(){
    fastio;

    int n; cin >> n;
    vector<int> r(n);
    for(int& i : r) cin >> i;

    double s=1e-11, e=2000;

    while(s<=e){
        double m=(s+e)/2;
        double sum=0;

        for(int i : r){
            if(m>i*2) continue;
            sum+=acos(m/i/2);
        }
        if(sum<acos(-1)) e=m-(1e-12);
        else s=m+(1e-12);
    }
    cout.precision(10);

    double ret=0;
    for(int i : r){
        if(e>i*2) continue;
        double t=acos(e/i/2);
        ret+=e*i*sin(t);
        ret+=i*i*2*t;
    }
    cout << ret;

    return 0;
}
