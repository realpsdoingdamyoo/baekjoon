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
const vpii dir4={{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
const vpii dir8={{0, 1}, {1, 0}, {-1, 0}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
const ll inf=2147483647, linf=9223372036854775807;
const double pi=acos(-1), E=2.718281828459;
ll gcd(ll a, ll b){return b?gcd(b, a%b):a;}
#define cf cout.flush()

vi solve(ll n, vi v){
    if(n==1) return v;

    vi o, e, p;
    for(ll i : v) if(i&1) o.pb(i); else e.pb(i);

    map<ll, vpii> mp;
    forf(i, 0, o.size()/2){
        mp[o[i*2]+o[i*2+1]>>1].pb({o[i*2], o[i*2+1]});
        p.pb(o[i*2]+o[i*2+1]>>1);
    }
    forf(i, 0, e.size()/2){
        mp[e[i*2]+e[i*2+1]>>1].pb({e[i*2], e[i*2+1]});
        p.pb(e[i*2]+e[i*2+1]>>1);
    }

    vi u=solve(n>>1, p);

    vi ret;
    for(ll i : u){
        pii pr=mp[i].back(); mp[i].pop_back();
        ret.pb(pr[0]); ret.pb(pr[1]);
    }

    return ret;
}

int main(){
    fastio;

    ll n; cin >> n;
    vi v(n*2-1);
    forf(i, 0, n*2-1) cin >> v[i];
    vi u=solve(n, v);
    for(ll i : u) cout << i << " ";

    return 0;
}
