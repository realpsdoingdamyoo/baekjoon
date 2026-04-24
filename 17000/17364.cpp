#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=1e15;

int n, k, t, c;
array<int, 2> v[101010];
multiset<int> st;

signed main() {
	fastio;

	cin >> n >> k;
	for (int i=1; i<=n; i++) cin >> v[i][0] >> v[i][1];
	sort(v+1, v+n+1, [&](array<int, 2> a, array<int, 2> b){return a[1]*mod+a[0]<b[1]*mod+b[0];});

	for (int i=1; i<k; i++) st.insert(0); if (k==1) st.insert(inf);
	for (int i=1; i<=n; i++) {
		if (t>=v[i][0]) continue;
		if (*st.begin()>=v[i][0]) c++, t=v[i][1];
		else if (k>1) {
			st.erase(prev(st.lower_bound(v[i][0])));
			st.insert(v[i][1]);
		}
	}
	cout << c;

	return 0;
}
