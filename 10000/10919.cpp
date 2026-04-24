#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2e18;

int t[10101010];

signed main(){
	fastio;

	int n, k, l;
	cin >> n >> k >> l;
	for(int i=0; i<n; i++) cin >> t[i];

	int ret=inf;
	for(int i=0; i<k; i++){
        int s=i, e=n/k*k+(i+1)%k;
        if(e>=n) e-=k;
        s-=k; e+=k;

        int res=0;
        while(s+k<n && t[s+k]<=l-t[s+k]) s+=k, res+=t[s]*2;
        while(e-k>=max(-1LL, s)+1 && l-t[e-k]<=t[e-k]) e-=k, res+=(l-t[e])*2;
        ret=min(ret, res+(e-s>1)*l);
    }
	cout << ret;


    return 0;
}
