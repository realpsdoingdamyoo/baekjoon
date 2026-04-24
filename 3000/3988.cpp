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
const int mod=1e9+7, MOD=998244353;
const int dir4[4][2]={{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
const int dir8[8][2]={{0, 1}, {1, 0}, {-1, 0}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
const ll inf=2147483647, linf=9223372036854775807;
const double pi=acos(-1), eu=2.718281828459;
ll gcd(ll a, ll b){return b?gcd(b, a%b):a;}


int main(){
    fastio;

	ll n, k; cin >> n >> k; k=n-k;
	vi v(n); vcin;
    sortv(v);
	priority_queue<ll, vi, greater<ll>> pq, dpq;
	forf(i, 0, k) pq.push(v[i+1]-v[i]);
	ll s=0, e=k-1;
    ll Mm=v[e]-v[s]+pq.top();
    forf(i, 0, n-k){
        pq.push(v[e+1]-v[e]); e++;
        dpq.push(v[s+1]-v[s]); s++;
        while(dpq.size() && dpq.top()==pq.top()){
            pq.pop(); dpq.pop();
        }
        Mm=min(Mm, v[e]-v[s]+pq.top());
    }

    cout << Mm;

	return 0;
}
