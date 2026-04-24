#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=4e18;

int n, m, rd;
int v[30303], u[30303];
array<int, 2> bn[30303];
array<int, 2> mn[202], mx[202];

signed main() {
	fastio;

	cin >> n >> m;
	for (int i=1; i<=n; i++){cin >> v[i]; v[i]+=v[i-1];}
	for (int i=1; i<=m; i++){cin >> u[i]; u[i]+=u[i-1];}

	for (int i=1; i<n; i++) {
		bn[i][0]=lower_bound(u+1, u+m+1, v[i]-100)-u;
		bn[i][1]=upper_bound(u+1, u+m+1, v[i]+100)-u-1;
		for (int j=bn[i][0]; j<=bn[i][1]; j++) {
			int df=v[i]-u[j];
			if (mn[df+100][0]==0) mn[df+100]={i, j};
			else mn[df+100]=min(mn[df+100], {i, j});
			if (mx[df+100][0]==0) mx[df+100]={i, j};
			else mx[df+100]=max(mx[df+100], {i, j});
		}
	}
	rd=v[n]-u[m];

	array<int, 7> ans={inf, 0, 0, 0, 0, 0, 0};
	for (int i=-50; i<=50; i++) for (int j=-100; j<=100; j++) {
		if (j-i<-50 || j-i>50) continue;
		if (rd-j<-50 || rd-j>50) continue;

		int df=max(max(abs(i), abs(j-i)), abs(rd-j));
		array<int, 7> ret; ret[0]=df;
		ret[1]=mn[i+100][0]; ret[2]=mx[j+100][0]-ret[1]; ret[3]=n-ret[1]-ret[2];
		ret[4]=mn[i+100][1]; ret[5]=mx[j+100][1]-ret[4]; ret[6]=m-ret[4]-ret[5];
		if (ret[1]<=0 || ret[2]<=0 || ret[3]<=0) continue;
		if (ret[4]<=0 || ret[5]<=0 || ret[6]<=0) continue;
		ans=min(ans, ret);
	}
	if (ans[0]==inf){cout << "-1"; return 0;}
	cout << ans[1] << " " << ans[2] << " " << ans[3] << "\n";
	cout << ans[4] << " " << ans[5] << " " << ans[6] << "\n";

	return 0;
}
