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
const ll inf=2147483647, linf=9223372036854775807;
const double pi=acos(-1), E=2.718281828459;
ll gcd(ll a, ll b){return b?gcd(b, a%b):a;}

ll n, k, ans;
vi lnk[200005];

pii piiput(pii p, ll x){
    vi np;
    np.pb(p[0]); np.pb(p[1]); np.pb(x);
    sortv(np);
    return {np[1], np[2]};
}

ll _dfs(ll pnt, ll pre){
    pii dep={0, 0};
    for(ll i : lnk[pnt]){
        if(i==pre) continue;
        ll _d=_dfs(i, pnt);
        dep=piiput(dep, _d);
    }

    if(dep[0]+dep[1]>=k){
        ans++;
        return 0;
    }
    return max(dep[0], dep[1])+1;
}

int main(){
    fastio;

    cin >> n >> k;
    forf(i, 0, n-1){
        ll a, b; cin >> a >> b;
        lnk[a].pb(b);
        lnk[b].pb(a);
    }

    _dfs(1, 0);
    cout << ans;

    return 0;
}
