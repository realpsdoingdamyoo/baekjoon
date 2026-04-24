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


int main(){
    fastio;

    ll n, x; cin >> n >> x;
    vpii v;
    forf(i, 0, n){
        ll a, b, c, t;
        cin >> a >> b >> c >> t;
        ll ft=(x-1)/a+1;
        ll bt=(c-1)/a+1;
        if(ft>bt) continue;

        ll ds=bt*a-x;

        ll st=ds/b+1;

        v.pb({t+ft, t+bt+st-1});
    }

    map<ll, ll> mp;
    for(pii i : v){
        mp[i[0]]++;
        mp[i[1]+1]--;
    }

    ll prv=0, P=0, ret=0;
    for(pair<ll, ll> p : mp){
        if(prv>=3) ret+=(p.first-P);
        prv+=p.second; P=p.first;
    }
    cout << ret;

    return 0;
}
