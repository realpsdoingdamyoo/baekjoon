#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2147483647;

int n;
int v[1010101], u[1010101], ans[1010101];

signed main(){
    fastio;

	cin >> n;
	for(int i=1; i<=n; i++){
        cin >> v[i]; u[v[i]]++;
	}

	for(int i=1; i<1010101; i++){
        for(int j=i; j<1010101; j+=i) ans[j]+=u[i];
	}
	for(int i=1; i<=n; i++) cout << ans[v[i]]-1 << "\n";

	return 0;
}
