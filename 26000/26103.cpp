#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
const int mod=1e9+7, MOD=998244353, inf=4e18;

int n;
string s;
int v[101010];
int ls[4];

int us, ds;
int u[101010], d[101010];

int dp[5050][5050];

void solvemin() {
	for (int i=0; i<4; i++) ls[i]=0;
	for (int i=1; i<=n; i++) v[i]=(v[i-1]+(s[i]=='L')-(s[i]=='R')+4)%4;
	for (int i=1; i<=n; i++) if (s[i]=='L' && s[i+1]=='L') ls[v[i]]=(ls[v[i]]==0)?i:-1;
	rotate(v+1, v+ls[0], v+n+1);

	for (int i=2; i<=n && v[i]==v[2]; i+=2) u[us+1]=u[us]+(v[i-1]==v[1])*2-1, us++;
	reverse(v+2, v+n+1);
	for (int i=2; i<=n && v[i]==v[2]; i+=2) d[ds+1]=d[ds]+(v[i-1]==v[1])*2-1, ds++;

	for (int i=us; i>=1; i--) u[i]-=u[1]; for (int i=ds; i>=1; i--) d[i]-=d[1];
	if (us<ds) swap(us, ds), swap(u, d);

	int ud1=max(us, ds);

	us=0; ds=0;
	for (int i=0; i<4; i++) ls[i]=0;
	for (int i=1; i<=n; i++) v[i]=(v[i-1]+(s[i]=='L')-(s[i]=='R')+4)%4;
	for (int i=1; i<=n; i++) if (s[i]=='L' && s[i+1]=='L') ls[v[i]]=(ls[v[i]]==0)?i:-1;
	rotate(v+1, v+ls[1], v+n+1);

	for (int i=2; i<=n && v[i]==v[2]; i+=2) u[us+1]=u[us]+(v[i-1]==v[1])*2-1, us++;
	reverse(v+2, v+n+1);
	for (int i=2; i<=n && v[i]==v[2]; i+=2) d[ds+1]=d[ds]+(v[i-1]==v[1])*2-1, ds++;

	for (int i=us; i>=1; i--) u[i]-=u[1]; for (int i=ds; i>=1; i--) d[i]-=d[1];
	if (us<ds) swap(us, ds), swap(u, d);

	int ud2=max(us, ds);

	for (int i=0; i<4; i++) ls[i]=0;
	for (int i=1; i<=n; i++) v[i]=(v[i-1]+(s[i]=='L')-(s[i]=='R')+4)%4;
	for (int i=1; i<=n; i++) if (s[i]=='L' && s[i+1]=='L') ls[v[i]]=(ls[v[i]]==0)?i:-1;
	rotate(v+1, v+ls[1], v+n+1);

	int ret=(ud1+ud2)*2;
	if (ls[0]%n+1==ls[1] && ls[2]%n+1==ls[3] && (ls[2]-ls[0]+n)%n==n/2) ret+=2;
	else if (ls[1]%n+1==ls[2] && ls[3]%n+1==ls[0] && (ls[3]-ls[1]+n)%n==n/2) ret+=2;

	cout << ret;
}

signed main() {
	fastio;

	cin >> s; n=s.length(); s=" "+s+s[0];
	if (n>10000){solvemin(); return 0;}

	for (int i=1; i<=n; i++) v[i]=(v[i-1]+(s[i]=='L')-(s[i]=='R')+4)%4;
	for (int i=1; i<=n; i++) if (s[i]=='L' && s[i+1]=='L') ls[v[i]]=(ls[v[i]]==0)?i:-1;
	for (int i=0; i<2; i++) if (ls[i]>=1 && ls[i+2]>=1){rotate(v+1, v+ls[i], v+n+1); break;}

	for (int i=2; i<=n && v[i]==v[2]; i+=2) u[us+1]=u[us]+(v[i-1]==v[1])*2-1, us++;
	reverse(v+2, v+n+1);
	for (int i=2; i<=n && v[i]==v[2]; i+=2) d[ds+1]=d[ds]+(v[i-1]==v[1])*2-1, ds++;

	for (int i=us; i>=1; i--) u[i]-=u[1]; for (int i=ds; i>=1; i--) d[i]-=d[1];

	if (us<ds) swap(us, ds), swap(u, d);

	for (int i=1; i<=us; i++) dp[0][i]=dp[i][0]=inf;
	for (int i=1; i<=us; i++) for (int j=1; j<=ds; j++) {
		int cst=0;
		for (int k=max(1LL, i-1); k<=min(us, i+1); k++) cst=max(cst, -u[k]-d[j]);
		dp[i][j]=max(min(dp[i-1][j], dp[i-1][j-1]), cst);
	}

	cout << max(dp[us][ds], 0LL)*2+u[us]+d[ds]+us-ds+n;

	return 0;
}
