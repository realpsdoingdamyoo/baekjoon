#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=1e18;

int n;
array<int, 2> v[252525];
int p=0, ans;
priority_queue<int> pq;

signed main() {
	fastio;

	cin >> n;
	for (int i=1; i<=n; i++) cin >> v[i][0] >> v[i][1];
	sort(v+1, v+n+1, [&](array<int, 2> a, array<int, 2> b){return a[0]+a[1]<b[0]+b[1];});

	for (int i=1; i<=n; i++) {
		if (p<=v[i][0]) {ans++; p+=v[i][1]; pq.push(v[i][1]); continue;}
		if (p-pq.top()<=v[i][0] && v[i][1]<=pq.top()) {p-=pq.top()-v[i][1]; pq.pop(); pq.push(v[i][1]);}
	}

	cout << ans;

	return 0;
}
