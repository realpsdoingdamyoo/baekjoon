#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef array<ll, 2> pii;
typedef vector<pii> vpii;
typedef double lf;
typedef priority_queue<ll> pqi;
#define V vector
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define vcin; for(int i=0; i<n; i++) cin >> v[i];
#define forf(i, s, e) for(ll i=s; i<e; i++)
#define forb(i, s, e) for(ll i=s-1; i>=e; i--)
#define pb push_back
#define sortv(v) sort(v.begin(), v.end())
#define sortc(v, cmp) sort(v.begin(), v.end(), cmp)
#define repeat(n) for(ll not_used_name=0; not_used_name<n; not_used_name++)
#define all(v) v.begin(), v.end()
const int mod=1e9+7, MOD=998244353;
const int dir4[4][2]={{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
const int dir8[8][2]={{0, 1}, {1, 0}, {-1, 0}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
const ll inf=2147483647, linf=9223372036854775807;
const double pi=acos(-1), eu=2.718281828459;
ll gcd(ll a, ll b){return b?gcd(b, a%b):a;}



int main() {
    fastio;
    ll n, k;
    cin >> n >> k;
    vi v, u;
    forf(i, 0, n){
        ll x; cin >> x;
        if(x>0) v.pb(x);
        else u.pb(-x);
    }
    ll s=0, r=0;
    sortv(u); sortv(v);
    while(v.size()){ 
        s+=2*v[v.size()-1]; r=max(r, v[v.size()-1]);
        ll vs=v.size();
        forf(i, 0, min(vs, k)) v.pop_back();
    }
    while(u.size()){ 
        s+=2*u[u.size()-1]; r=max(r, u[u.size()-1]);
        ll us=u.size();
        forf(i, 0, min(us, k)) u.pop_back();
    }
    cout << s-r;

    return 0;
}
