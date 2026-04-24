#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2147483647;

int n, k, kp=1, ans;

int ep[1010101], cn[1010101];

int pw(int m, int p){
    int ret=1;
    while(p){
        if(p&1) ret=ret*m%mod;
        m=m*m%mod; p>>=1;
    } return ret;
}

signed main(){
    fastio;

    cin >> n >> k;

    for(int i=1; i<=n; i++) ep[i]=i;
    for(int i=2; i<=n; i++) if(ep[i]==i)
        for(int j=i; j<=n; j+=i) ep[j]=ep[j]*(i-1)/i;

    for(int g=1; g<=n; g++){
        kp=kp*k%mod;
        for(int i=g; i<=n; i+=g){
            cn[i]+=ep[i/g]*kp;
            cn[i]%=mod;
        }
    }

    for(int i=1; i<=n; i++){
        if(i%2==1) cn[i]+=i*pw(k, i/2+1);
        else{
            cn[i]+=i/2*pw(k, i/2);
            cn[i]+=i/2*pw(k, i/2+1);
        }
        cn[i]%=mod;

        ans+=cn[i]*pw(i*2, mod-2)%mod;
    }
    cout << (ans+1)%mod;

	return 0;
}
