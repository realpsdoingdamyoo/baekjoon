#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=4e18;

int n, m;
int v[101010];
double up[1010];
int con[1010];

void update(int a, int b, int x) {
	if (a==b) {
		for (int i=a+1; i<1010; i++) con[i]+=x;
		return;
	}
	if (a>b) swap(a, b);
	if (b==inf) return;
	double d=1.0/(b-a);
	up[a]+=d*x; up[b]-=d*x;
}

signed main() {
	fastio;

	cin >> n >> m;
	for (int i=1; i<=n; i++) cin >> v[i];
	v[0]=v[n+1]=inf;
	for (int i=1; i<=n; i++) update(v[i], v[i+1], 1);
	for (int x=1; x<=m; x++) {
		string s; cin >> s;
		if (s=="U") {
			int a, b; cin >> a >> b; a++;
			update(v[a], v[a-1], -1); update(v[a], v[a+1], -1);
			v[a]=b;
			update(v[a], v[a-1], 1); update(v[a], v[a+1], 1);
		}
		else {
			int a; cin >> a;
			double ret=0;
			for (int i=0; i<=a; i++) {
				ret+=con[i];
				ret+=up[i]*(a-i)*(a-i)/2;
			}
			printf("%.3Lf\n", ret);
		}
	}

	return 0;
}
