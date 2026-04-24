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

const ll X=18;
ll segtree[1<<X+1];

void update(ll p, ll x){
    p+=1<<X;
    while(p){
        segtree[p]+=x;
        p>>=1;
    }
}
ll sum(ll s, ll e){
    ll ret=0;
    s+=1<<X; e+=1<<X;
    while(s<=e){
        if(s&1) ret+=segtree[s];
        s=(s+1)>>1;
        if(!(e&1)) ret+=segtree[e];
        e=(e-1)>>1;
    }
    return ret;
}


int main(){
    fastio;

    ll n; cin >> n;
    forf(i, 0, n){
        ll a; cin >> a;
        update(i, a);
    }
    ll q, c1=0, c2=0; cin >> q;
    V<array<ll, 5>> query;
    while(q--){
        ll a; cin >> a;
        if(a==1){
            ll b, c; cin >> b >> c;
            query.pb({c1++, 1, b, c, 0});
        }
        else{
            ll b, c, d; cin >> b >> c >> d;
            query.pb({b, 0, c, d, c2++});
        }
    }
    sortv(query);
    vpii ans;
    for(array<ll, 5> qr : query){
        if(qr[1]==0) ans.pb({qr[4], sum(qr[2]-1, qr[3]-1)});
        else update(qr[2]-1, qr[3]-segtree[(1<<X)+qr[2]-1]);
    }

    sortv(ans);
    for(pii a : ans) cout << a[1] << "\n";

    return 0;
}
