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
#define cf; cout.flush();

ll n;
vpii v;

pii up(pii a, ll d){
    if(d>a[0]+a[1]) return {0, 0};
    ll x=0;
    forf(i, 0, 32){
        if((a[0]+a[1])&(1LL<<i)){
            if(a[0]&(1LL<<i)){
                a[0]-=min(1LL<<i, d);
                d-=min(1LL<<i, d);
            }
            else{
                a[1]-=min(1LL<<i, d);
                d-=min(1LL<<i, d);
            }
        }
    }
    return a;
}

pii lca(pii a, pii b){
    if(a[0]+a[1]>b[0]+b[1]) swap(a, b);
    b=up(b, b[0]+b[1]-a[0]-a[1]);
    if(a==b) return a;
    forf(i, 0, 32){
        if((a[0]+a[1])&(1LL<<i)){
            if(a[0]&(1LL<<i)) a[0]-=1LL<<i;
            else a[1]-=1LL<<i;

            if(b[0]&(1LL<<i)) b[0]-=1LL<<i;
            else b[1]-=1LL<<i;
            if(a==b) break;
        }
    }


    return a;
}

ll dist(pii a, pii b){
    pii l=lca(a, b);
    return a[0]+b[0]+a[1]+b[1]-l[0]*2-l[1]*2;
}

ll adist(pii c){
    ll ret=0;
    forf(i, 0, n) ret+=dist(c, v[i]);
    return ret;
}

int main() {
    fastio;

    cin >> n; v.resize(n);
    forf(i, 0, n) cin >> v[i][0] >> v[i][1];

    ll mv=1LL<<31, x=0, y=0;
    while(mv){
        V<tii> mc;
        mc.pb({adist({x, y}), x, y});
        for(pii d : dir4){
            ll nx=x+d[0]*mv, ny=y+d[1]*mv;
            if(nx<0 || ny<0 || nx&ny!=0) continue;
            mc.pb({adist({nx, ny}), nx, ny});
        }
        sortv(mc);
        ll a=mc[0][0];
        x=mc[0][1]; y=mc[0][2];
        mv/=2;
    }
    cout << adist({x, y});

    return 0;
 }
