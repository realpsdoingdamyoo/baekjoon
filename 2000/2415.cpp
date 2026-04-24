#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef array<ll, 2> pii;
typedef array<ll, 3> tii;
typedef vector<pii> vpii;
typedef double lf;
typedef string S;
#define V vector
#define PQ priority_queue
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define vcin; for(int i=0; i<n; i++) cin >> v[i];
#define forf(i, s, e) for(ll i=s; i<e; i++)
#define forb(i, s, e) for(ll i=s-1; i>=e; i--)
#define pb push_back
#define sortv(v) sort(v.begin(), v.end())
#define sortc(v, cmp) sort(v.begin(), v.end(), cmp)
#define all(v) v.begin(), v.end()
const ll mod=1e9+7, MOD=998244353;
const ll dir4[4][2]={{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
const ll dir8[8][2]={{0, 1}, {1, 0}, {-1, 0}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
const ll inf=2147483647, linf=9223372036854775807/11;
const double pi=acos(-1), E=2.718281828459;
ll gcd(ll a, ll b){return b?gcd(b, a%b):a;}

int main() {
    fastio;

	ll n; cin >> n;
	vpii v(n);
	forf(i, 0, n) cin >> v[i][0] >> v[i][1];
	V<array<ll, 5>> p;
	forf(i, 0, n){
        forf(j, i+1, n){
            p.pb({v[i][0]+v[j][0], v[i][1]+v[j][1], (v[i][0]-v[j][0])*(v[i][0]-v[j][0])+(v[i][1]-v[j][1])*(v[i][1]-v[j][1]), v[j][0]-v[i][0], v[j][1]-v[i][1]});
        }
	}

	V<array<ll, 5>> s;
	sortv(p);
	s.pb({-1, -1, -1, -1, -1});
	ll ans=0;
	forf(i, 0, n*(n-1)/2){
	    s.pb(p[i]);
        if(p[i][0]!=p[i+1][0] || p[i][1]!=p[i+1][1] || p[i][2]!=p[i+1][2]){
            ll ms=0;
            forf(j, 0, s.size()){
                forf(k, j+1, s.size()){
                    ll ns=abs(s[j][3]*s[k][4]-s[j][4]*s[k][3]);
                    ms=max(ms, ns);
                }
            }
            ans=max(ms, ans);
            s.clear();
        }
	}

	cout << ans/2 << "\n";


	return 0;
}
