#include <bits/stdc++.h>
using namespace std;
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=1e15;

int n, m, k;
int v[1515][1515];
int dp1[4][1515][1515];
int dp2[4][1515][1515];

int sum(int x, int y) {return v[x][y]-v[x-k][y]-v[x][y-k]+v[x-k][y-k];}

signed main() {
	fastio;

	cin >> n >> m >> k;
	for (int i=1; i<=n; i++) for (int j=1; j<=m; j++) cin >> v[i][j];
	for (int i=1; i<=n; i++) for (int j=1; j<=m; j++) v[i][j]+=v[i][j-1];
	for (int i=1; i<=n; i++) for (int j=1; j<=m; j++) v[i][j]+=v[i-1][j];

	for (int i=k; i<=n; i++) for (int j=k; j<=m; j++) {
		dp1[0][i][j]=max(sum(i, j), max(dp1[0][i-1][j], dp1[0][i][j-1]));
		dp2[0][i][j]=max(dp1[0][i-k][j], dp1[0][i][j-k])+sum(i, j);
		dp2[0][i][j]=max(dp2[0][i][j], max(dp2[0][i-1][j], dp2[0][i][j-1]));
	}
	for (int i=n-k+1; i>=1; i--) for (int j=k; j<=m; j++) {
		dp1[1][i][j]=max(sum(i+k-1, j), max(dp1[1][i+1][j], dp1[1][i][j-1]));
		dp2[1][i][j]=max(dp1[1][i+k][j], dp1[1][i][j-k])+sum(i+k-1, j);
		dp2[1][i][j]=max(dp2[1][i][j], max(dp2[1][i+1][j], dp2[1][i][j-1]));
	}
	for (int i=k; i<=n; i++) for (int j=m-k+1; j>=1; j--) {
		dp1[2][i][j]=max(sum(i, j+k-1), max(dp1[2][i-1][j], dp1[2][i][j+1]));
		dp2[2][i][j]=max(dp1[2][i-k][j], dp1[2][i][j+k])+sum(i, j+k-1);
		dp2[2][i][j]=max(dp2[2][i][j], max(dp2[2][i-1][j], dp2[2][i][j+1]));
	}
	for (int i=n-k+1; i>=1; i--) for (int j=m-k+1; j>=1; j--) {
		dp1[3][i][j]=max(sum(i+k-1, j+k-1), max(dp1[3][i+1][j], dp1[3][i][j+1]));
		dp2[3][i][j]=max(dp1[3][i+k][j], dp1[3][i][j+k])+sum(i+k-1, j+k-1);
		dp2[3][i][j]=max(dp2[3][i][j], max(dp2[3][i+1][j], dp2[3][i][j+1]));
	}

	int ans=0;
	for (int i=1; i<n; i++) ans=max(ans, max(dp2[0][i][m]+dp1[3][i+1][1], dp1[0][i][m]+dp2[3][i+1][1]));
	for (int j=1; j<m; j++) ans=max(ans, max(dp2[0][n][j]+dp1[3][1][j+1], dp1[0][n][j]+dp2[3][1][j+1]));
	for (int i=1; i<n; i++) ans=max(ans, max(dp2[1][i][1]+dp1[2][i+1][m], dp1[1][i][1]+dp2[2][i+1][m]));
	for (int j=1; j<m; j++) ans=max(ans, max(dp2[1][1][j]+dp1[2][n][j+1], dp1[1][1][j]+dp2[2][n][j+1]));
	cout << ans;

	return 0;
}
