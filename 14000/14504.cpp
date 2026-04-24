#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=1e18;

int n, q, X=1000;
int v[101010], u[101010];

signed main() {
	fastio;

	cin >> n;
	for (int i=0; i<n; i++) {cin >> v[i]; u[i]=v[i];}
	for (int i=0; i<=n/X; i++) sort(u+i*X, u+min(i*X+X, n));

	cin >> q;
	while (q--) {
		int a, b, c, d, r=0; cin >> a;
		if (a==1) {
			cin >> b >> c >> d; b--; c--;
			while (b%X && b<=c) r+=(v[b++]>d);
			while ((c+1)%X && b<=c) r+=(v[c--]>d);
			while (b<=c) r+=u+b+X-upper_bound(u+b, u+b+X, d), b+=X;
			cout << r << "\n";
		}
		else {
			cin >> b >> c; b--;
			int s=b/X*X, e=min(n, b/X*X+X)-1;
			int p=lower_bound(u+s, u+e, v[b])-u;
			u[p]=c;
			while (s<p && u[p]<u[p-1]) swap(u[p], u[p-1]), p--;
			while (p<e && u[p]>u[p+1]) swap(u[p], u[p+1]), p++;
			v[b]=c;
		}
	}

	return 0;
}
