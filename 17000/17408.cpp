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

const ll X=20;
pii _segtree[1<<X+1];

pii selpi(pii a, pii b){
    vi _v;
    _v.pb(a[0]); _v.pb(a[1]);
    _v.pb(b[0]); _v.pb(b[1]);
    sortv(_v);
    return {_v[2], _v[3]};
}

void update(ll i, ll v){
    _segtree[i]={v, 0}; i>>=1;
    while(i){
        _segtree[i]=selpi(_segtree[i*2], _segtree[i*2+1]);
        i>>=1;
    }
}

ll query(ll s, ll e){
    pii ret={0, 0};
    while(s<e){
        if(s%2==1) ret=selpi(ret, _segtree[s]);
        s=(s+1)/2;
        if(e%2==0) ret=selpi(ret, _segtree[e]);
        e=(e-1)/2;
    }
    if(s==e) ret=selpi(ret, _segtree[s]);
    return ret[0]+ret[1];
}

int main(){
    fastio;

    ll n; cin >> n;
    forf(i, 0, n) cin >> _segtree[(1<<X)+i][0];
    forb(i, X, 0) forf(j, 1<<i, 1<<i+1) _segtree[j]=selpi(_segtree[j*2], _segtree[j*2+1]);
    ll q; cin >> q;
    while(q--){
        ll a, b, c; cin >> a >> b >> c;
        if(a==1) update(b+(1<<X)-1, c);
        else cout << query(b+(1<<X)-1, c+(1<<X)-1) <<"\n";
    }


    return 0;
}
