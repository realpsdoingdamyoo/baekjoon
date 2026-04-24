#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=2147483647;

signed main() {
    fastio;

	int n, k, q; cin >> n >> k >> q;
	vector<int> ps(n);

	int c=0;
	for(int i=0; i<n; i++){
        for(int j=0; j<k; j++){
            int a; cin >> a; a--;
            if(a>=i) ps[i]++, ps[a]--;
            else ps[i]++, ps[0]++, ps[a]--;
            if(i==0 && a!=0) c++;
        }
	}

	for(int i=1; i<n; i++) ps[i]+=ps[i-1];

	int s=ps[0]; s+=!c;

	if(s>q) cout << "0";
	else cout << "1";

	return 0;
}
