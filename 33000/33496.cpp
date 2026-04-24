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


int main(){
    fastio;

    ll n; cin >> n;
    vi vx, ux, v, u, sx, s;
    forf(i, 0, n){
        ll a, b; cin >> a >> b;
        vx.pb(a-b);
        ux.pb(a+b);
        sx.pb(a-b);
        sx.pb(a+b);
    }
    sortv(vx); sortv(ux); sortv(sx);

    v.pb(vx[0]); u.pb(ux[0]); s.pb(sx[0]);
    forf(i, 1, n) if(vx[i]!=vx[i-1]) v.pb(vx[i]);
    forf(i, 1, n) if(ux[i]!=ux[i-1]) u.pb(ux[i]);
    forf(i, 1, n*2) if(sx[i]!=sx[i-1]) s.pb(sx[i]);

    ll ret=s.size();

    for(ll i : u){
        ret+=lower_bound(all(v), i)-v.begin();
    }

    cout << ret << "\n";


    return 0;
}
