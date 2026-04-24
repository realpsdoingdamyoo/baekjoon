#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=4e18;

int n, ans;
int v[20202];

unordered_map<int, int> ump;
int Div(int x) {
	if (ump.find(x)!=ump.end()) return ump[x];
	map<int, int> mp; int ret=0;
	for (int i=1; i<=n; i++) mp[v[i]%x]++;
	for (pair<int, int> i : mp) ret=max(ret, i.second);
	return ump[x]=ret;
}

signed main() {
	fastio;
	srand(1557);

	cin >> n;
	for (int i=1; i<=n; i++) cin >> v[i];
	ans=max(ans, Div(2));

	for (int i=1; i<=100; i++) {
		int a=rand()%n+1, b=rand()%n+1;

		int x=abs(v[a]-v[b]);
		if (a==b) continue;
		while (x%2==0) x>>=1;
		if (x<=1) continue;

		for (int j=2; j*j<=x; j++) {
			if (x%j) continue;
			while (x%j==0) x/=j;
			ans=max(ans, Div(j));
		}
		if (x>1) ans=max(ans, Div(x));
	}
	cout << ans;

	return 0;
}
