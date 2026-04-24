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
const ll dir4[4][2]={{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
const ll dir8[8][2]={{0, 1}, {1, 0}, {-1, 0}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
const ll inf=2147483647, linf=9223372036854775807;
const double pi=acos(-1), E=2.718281828459;
ll gcd(ll a, ll b){return b?gcd(b, a%b):a;}

const ll X=18;
ll seg[1<<X+1];

void update(ll p, ll x){
    p+=1<<X;
    seg[p]=x;
    p>>=1;
    while(p){
        seg[p]=max(seg[p*2], seg[p*2+1]);
        p>>=1;
    }
}

ll FND(ll x){
    if(seg[1]<x) return 1<<X;
    ll r=1;
    while(r<(1<<X)){
        r<<=1;
        if(seg[r]<x) r++;
    }
    return r-(1<<X);
}

void solve(){
    forf(i, 0, 1<<X+1) seg[i]=0;

    ll n, m; cin >> n >> m;
    forf(i, 0, n){
        ll a; cin >> a;
        update(i, a);
    }
    ll ret=0;
    forf(i, 0, m){
        ll a; cin >> a;
        ll f=FND(a);
        if(f==1<<X) continue;
        update(f, 0);
        ret+=(i+1)*(f+1);
    }
    cout << ret << "\n";
}

int main(){
    fastio;

    ll t; cin >> t;
    while(t--) solve();

    return 0;
}
