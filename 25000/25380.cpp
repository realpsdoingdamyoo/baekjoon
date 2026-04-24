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

ll solve(vi p, vi l){
    ll ret=0;
    l.pb(-inf); l.pb(inf);
    sortv(p); sortv(l);

    ll n=p.size(); ll m=l.size();

    forf(i, 0, n) ret+=p[i]*(i*2-n+1);

    forf(i, 0, m-1){
        ll s=l[i], e=l[i+1];
        ll sit=lower_bound(all(p), s)-p.begin();
        ll eit=lower_bound(all(p), e)-p.begin();

        vi tp;
        ll sz=eit-sit;
        forf(j, sit, eit) tp.pb(min(p[j]-s, e-p[j]));
        sortv(tp);

        forf(j, 0, sz){
            ret+=tp[j]*2*(sz-j-1);
        }
    }
    return ret;
}

int main(){
    fastio;

    ll n, m, k; cin >> n >> m >> k;

    vi xl(n), yl(m);
    forf(i, 0, n) cin >> xl[i];
    forf(i, 0, m) cin >> yl[i];
    vi xp(k), yp(k);
    forf(i, 0, k) cin >> xp[i] >> yp[i];

    cout << solve(xp, xl)+solve(yp, yl);


    return 0;
}
