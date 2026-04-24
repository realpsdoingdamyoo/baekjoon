#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e9;

int deg[202020], cnt[202020];
int fac[202020]={1};

int inv(int p){
    int ret=1, x=mod-2;
    while(x){
        if(x&1) ret=ret*p%mod;
        p=p*p%mod; x>>=1;
    } return ret;
}
signed main(){
	fastio;
	for(int i=1; i<202020; i++) fac[i]=fac[i-1]*i%mod;
	int n, m; cin >> n >> m;
	for(int i=1; i<=m; i++){
        int a, b; cin >> a >> b;
        deg[a]++; deg[b]++;
	}
	for(int i=1; i<=n; i++) cnt[deg[i]]++;
	sort(deg+1, deg+n+1);
	int sum=0, uc=0, ans=0;
	for(int i=n, c=1; i>=1; i--, c++){
        sum+=deg[i]; uc=(deg[i]==deg[i+1]?uc+1:1);
        if(sum!=m+c*(c-1)/2) continue;
        int nc=cnt[deg[i]]-uc;
        ans+=fac[nc+uc]*inv(fac[nc]*fac[uc]%mod)%mod;
	}
	cout << ans%mod;
    return 0;
}
