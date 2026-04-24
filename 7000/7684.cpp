#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=4e18;

double err(){
    int x=1LL*rand()*rand()*rand()%mod;
    x-=mod/2;
    return 1e-7*x/mod;
}

bool solve(){
    int n; cin >> n;
    if(n==0) return false;
    double ans=0;
    vector<array<double, 3>> v(n);
    for(array<double, 3>& i : v) for(double& j : i){
        cin >> j; j+=err();
    }

    for(int i=0; i<n; i++) for(int j=i+1; j<n; j++) for(int k=j+1; k<n; k++){
        array<double, 4> pl;
        array<double, 3> l1, l2;
        l1={v[j][0]-v[i][0], v[j][1]-v[i][1], v[j][2]-v[i][2]};
        l2={v[k][0]-v[i][0], v[k][1]-v[i][1], v[k][2]-v[i][2]};
        pl={l1[1]*l2[2]-l2[1]*l1[2], l1[2]*l2[0]-l2[2]*l1[0], l1[0]*l2[1]-l2[0]*l1[1], 0};
        pl[3]=pl[0]*v[i][0]+pl[1]*v[i][1]+pl[2]*v[i][2];

        int cnt=0;
        for(int p=0; p<n; p++){
            if(p==i || p==j || p==k) continue;
            cnt+=(pl[0]*v[p][0]+pl[1]*v[p][1]+pl[2]*v[p][2]<pl[3]);
        }
        if(cnt!=0 && cnt!=n-3) continue;
        ans+=sqrt(pl[0]*pl[0]+pl[1]*pl[1]+pl[2]*pl[2]);
    }
    cout << round(ans/2) << "\n";
    return true;
}

signed main(){
    fastio;
    srand(6969);

    while(solve()){}


    return 0;
}
