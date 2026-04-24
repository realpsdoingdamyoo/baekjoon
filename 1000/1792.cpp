#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2147483647;

int m[50505];

signed main(){
    fastio;

    m[1]=1;
    for(int i=1; i<50505; i++){
        for(int j=2*i; j<50505; j+=i) m[j]-=m[i];
        m[i]+=m[i-1];
    }

    int q; cin >> q;
    while(q--){
        int a, b, d, r=0; cin >> a >> b >> d;
        a/=d; b/=d;
        for(int i=1, j; i<=min(a, b); i=j+1){
            j=min(a/(a/i), b/(b/i));
            r+=(a/i)*(b/i)*(m[j]-m[i-1]);
        }
        cout << r << "\n";
    }

	return 0;
}
