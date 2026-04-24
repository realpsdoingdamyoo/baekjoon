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
#define cf cout.flush()

ll pw(ll a, ll p){
    ll ret=1;
    while(p){
        if(p&1) ret=ret*a%mod;
        a=a*a%mod; p>>=1;
    }
    return ret;
}

void solve(){
    ll n, g, l; cin >> n >> g >> l;
    if(l%g){cout << "0\n"; return;}

    l/=g;

    vi v;
    for(ll i=2; i*i<=l; i++){
        ll x=0;
        while(l%i==0){
            l/=i;
            x++;
        }
        if(x) v.pb(x+1);
    }
    if(l>1) v.pb(2);

    ll ans=1;
    for(ll p : v){
        ll m=pw(p, n)-2*pw(p-1, n)+pw(p-2, n);
        m=(m+2*mod)%mod;
        ans=ans*m%mod;
    }
    cout << ans << "\n";
}

int main(){
    fastio;

    ll t; cin >> t;
    while(t--) solve();


    return 0;
}
