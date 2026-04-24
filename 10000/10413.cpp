#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=1e15;

int n;
string s;
int sp[101010][20], u[101010];

void comp(int x) {
	vector<int> cmp={0};
	for (int i=1; i<=n; i++) cmp.push_back(sp[i][x]);
	sort(cmp.begin(), cmp.end());
	cmp.erase(unique(cmp.begin(), cmp.end()), cmp.end());
	for (int i=1; i<=n; i++) sp[i][x]=lower_bound(cmp.begin(), cmp.end(), sp[i][x])-cmp.begin();
}

int ovp(int x, int y) {
	int ret=0;
	for (int i=19; i>=0; i--) {
		if (max(x, y)+(1<<i)-1>n) continue;
		if (sp[x][i]==sp[y][i]) x+=1<<i, y+=1<<i, ret+=1<<i;
	}
	return ret;
}

void solve() {
	cin >> s; n=s.length(); s=" "+s;
	for (int i=1; i<=n; i++) sp[i][0]=s[i], u[i]=i;
	comp(0);

	for (int j=1; j<20; j++) {
		for (int i=1; i<=n; i++) sp[i][j]=sp[i][j-1]*mod+(i+(1<<j-1)>n?0:sp[i+(1<<j-1)][j-1]);
		comp(j);
	}

	sort(u+1, u+n+1, [&](int a, int b){return sp[a][19]<sp[b][19];});

	int ans=0, psa=0;
	for (int i=2; i<=n; i++) {
		int nsa=ovp(u[i], u[i-1]);
		ans+=nsa-min(nsa, psa); psa=nsa;
	}
	cout << ans << "\n";
}

signed main() {
	fastio;

	int T; cin >> T;
	while (T--) solve();

	return 0;
}
