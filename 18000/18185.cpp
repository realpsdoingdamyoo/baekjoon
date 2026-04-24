#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef array<ll, 2> pii;
typedef vector<pii> vpii;
typedef double lf;
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define vcin; for(int i=0; i<n; i++) cin >> v[i];
#define forf(i, s, e) for(int i=s; i<e; i++)
#define forb(i, s, e) for(int i=s-1; i>=e; i--)
#define pb push_back
#define sortv(v) sort(v.begin(), v.end())
#define sortc(v, cmp) sort(v.begin(), v.end(), cmp)
#define repeat(n) for(int not_used_name=0; not_used_name<n; not_used_name++)
const int mod=1e9+7, MOD=998244353;
const int dir4[4][2]={{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
const int dir8[8][2]={{0, 1}, {1, 0}, {-1, 0}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
const ll inf=2147483647, linf=9223372036854775807;
const double pi=acos(-1), eu=2.718281828459;
ll gcd(ll a, ll b){return b?gcd(b, a%b):a;}


ll small2(ll a, ll b){
	return a>b?b:a;
}

ll small3(ll a, ll b, ll c){
	return (a>b?b:a)>c?c:(a>b?b:a);
}

vi arr(1000005);
int main(){
	ll n, cnt=0, ss=0, b=3, c=2, s=0;
	cin >> n;
	for(ll i=0; i<n; i++) {cin >> arr[i]; ss+=arr[i];}
	if(b<c){cout << ss*b; return 0;}
	for(ll i=0; i<n; i++){
		if(arr[i+1]>arr[i+2]){
			cnt=small2(arr[i], arr[i+1]-arr[i+2]);
			s+=(b+c)*cnt;
			arr[i]-=cnt;arr[i+1]-=cnt;
			cnt=small3(arr[i], arr[i+1], arr[i+2]);
			s+=(b+2*c)*cnt;
			arr[i]-=cnt; arr[i+1]-=cnt; arr[i+2]-=cnt;
		}
		else{
			cnt=small3(arr[i], arr[i+1], arr[i+2]);
			s+=(b+2*c)*cnt;
			arr[i]-=cnt; arr[i+1]-=cnt; arr[i+2]-=cnt;
			cnt=small2(arr[i], arr[i+1]);
			s+=(b+c)*cnt;
			arr[i]-=cnt;arr[i+1]-=cnt;
		}
		s+=b*arr[i]; arr[i]=0;
	}
	cout << s;
	return 0;
}
