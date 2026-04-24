#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef array<ll, 2> pii;
typedef vector<pii> vpii;
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define vcin; for(int i=0; i<n; i++) cin >> v[i];
#define forf(i, s, e) for(int i=s; i<e; i++)
#define forb(i, s, e) for(int i=s-1; i>=e; i--)
#define sortv(v) sort(v.begin(), v.end())
#define sortc(v, cmp) sort(v.begin(), v.end(), cmp)
#define repeat(n) for(int not_used_name=0; not_used_name<n; not_used_name++)
const int mod=1e9+7, MOD=998244353;
const int dir4[4][2]={{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
const int dir8[8][2]={{0, 1}, {1, 0}, {-1, 0}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
const ll inf=2147483647, linf=9223372036854775807;
ll gcd(ll a, ll b){return b?gcd(b, a%b):a;}

ll n, m;
ll sum[101];
ll dp[101][51];

int main() {
    fastio;
	cin >> n >> m;
	forf(i, 1, n+1){
		ll x; cin >> x;
		sum[i]=x+sum[i-1];
	}

	forf(j, 1, m+1) dp[0][j]=-inf;


	forf(i, 1, n+1){
		forf(j, 1, m+1){
			dp[i][j] = dp[i-1][j];
			forf(k, 1, i+1){
				if(k>=2) dp[i][j] = max(dp[i][j], dp[k-2][j-1] + sum[i]-sum[k-1]);
				else if(k==1 && j==1) dp[i][j]=max(dp[i][j], sum[i]);
			}
		}
	}

	cout << dp[n][m];
	return 0;
}
