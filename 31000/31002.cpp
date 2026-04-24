#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef array<ll, 2> pii;
typedef array<ll, 3> tii;
typedef vector<pii> vpii;
typedef double lf;
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
const ll inf=2147483647, linf=9223372036854775807;
const double pi=acos(-1), E=2.718281828459;
ll gcd(ll a, ll b){return b?gcd(b, a%b):a;}

ll rvs(ll a){
    ll r=1, x=mod-2;
    while(x){
        if(x&1) r=r*a%mod;
        a=a*a%mod; x/=2;
    }
    return r;
}

int main() {
    fastio;

    ll n, k; cin >> n >> k;
    ll v=n, e=n*(n-1)/2;
    forf(i, 0, k){
        if(v==0) break;
        ll lnk=e*2*rvs(v)%mod;
        ll ne=lnk*(lnk-1)/2%mod*v%mod;
        v=e; e=ne;
        v%=mod; e%=mod;
    }
    cout << v << "\n";


    return 0;
 }
