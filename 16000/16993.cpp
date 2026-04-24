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

typedef array<ll, 4> qii;
const ll X=17;
V<qii> seg(1<<X+1); // lmx, rmx, sum, sex

qii mrg(qii a, qii b){
    if(a[0]==-inf) return b;
    if(b[0]==-inf) return a;
    qii r;
    r[0]=max(a[0], a[2]+b[0]);
    r[1]=max(b[1], b[2]+a[1]);
    r[2]=a[2]+b[2];
    r[3]=max(max(a[3], b[3]), a[1]+b[0]);
    return r;
}

void update(ll p, ll x){
    p+=1<<X;
    seg[p]={x, x, x, x};
    p>>=1;
    while(p){
        seg[p]=mrg(seg[p*2], seg[p*2+1]);
        p/=2;
    }
}

ll query(ll s, ll e){
    s+=1<<X; e+=1<<X;
    qii r={-inf, -inf, -inf, -inf};
    V<qii> sv, ev;
    while(s<=e){
        if(s%2==1) sv.pb(seg[s]); s=(s+1)/2;
        if(e%2==0) ev.pb(seg[e]); e=(e-1)/2;
    }
    while(sv.size()){r=mrg(sv[sv.size()-1], r); sv.pop_back();}
    while(ev.size()){r=mrg(r, ev[ev.size()-1]); ev.pop_back();}

    return r[3];
}

int main(){
    fastio;

    ll n, q; cin >> n;
    forf(i, 0, n){
        cin >> q;
        update(i, q);
    }

    cin >> q;
    while(q--){
        ll s, e; cin >> s >> e;
        cout << query(s-1, e-1) << "\n";
    }


    return 0;
}
