#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=4e18;

int sq[50505]={0, 1};

signed main(){
    fastio;

    for(int i=2; i<=50505; i++){
        int c=1;
        for(int j=2; j*j<=i; j++){
            if(i%j) continue;
            if(i%(j*j)==0) sq[i]=0;
            else sq[i]=-sq[i/j];
            c=0;
            break;
        }
        if(c) sq[i]=-1;
    }

    int n; cin >> n;
    int s=1, e=n*3;

    while(s<=e){
        int m=s+e>>1;
        int cnt=0;
        for(int i=1; i*i<=m; i++)
            cnt+=sq[i]*(m/i/i);
        if(cnt<n) s=m+1;
        else e=m-1;
    }
    cout << s;

    return 0;
}
