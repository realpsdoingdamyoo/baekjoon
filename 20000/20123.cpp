#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef array<ll, 2> pii;
typedef vector<pii> vpii;
typedef double lf;
typedef priority_queue<ll> pql;
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define vcin; for(int i=0; i<n; i++) cin >> v[i];
#define forf(i, s, e) for(int i=s; i<e; i++)
#define forb(i, s, e) for(int i=s-1; i>=e; i--)
#define pb push_back
#define sortv(v) sort(v.begin(), v.end())
#define sortc(v, cmp) sort(v.begin(), v.end(), cmp)
#define repeat(n) for(int not_used_name=0; not_used_name<n; not_used_name++)
//const int mod=1e9+7, MOD=998244353;
const int dir4[4][2]={{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
const int dir8[8][2]={{0, 1}, {1, 0}, {-1, 0}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
const ll inf=2147483647, linf=9223372036854775807;
const double pi=acos(-1), eu=2.718281828459;
ll gcd(ll a, ll b){return b?gcd(b, a%b):a;}


void FILL(int n) {
	if (n==0) return;
	else if (n==9) cout << "|\nb-\np-|\n||b-\n|b--q\nb-p-||\n-q|p-b-\n||||p-||\nb-b-|-db-\n";
	else if (n%3==2) {
		FILL(n - 2);
		repeat(n/3) cout << "p-|"; cout << "|" << "\n";
		repeat(n/3) cout << "|-d"; cout << "b-" << "\n";
	}
	else {
		FILL(n - 4);
		repeat(n/3-2) cout << "p-|"; cout << "p-|" << "\n";
		repeat(n/3-2) cout << "|-d"; cout << "||b-" << "\n";
		repeat(n/3-2) cout << "p-|"; cout << "|b-||" << "\n";
		repeat(n/3-2) cout << "|-d"; cout << "b--db-" << "\n";
	}
}

int main() {
	fastio;
	int n; cin >> n;
	if (n%3==1 || n==3 || n==5) cout << "impossible";
	else FILL(n);
}
