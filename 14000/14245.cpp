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
const ll SZ=1<<X;
pii lazyseg[SZ*2];

void update(ll s, ll e, ll x){
    while(e>s){
        if(s%2!=0) lazyseg[s][1]^=x;
        s=(s+1)/2;

        if(e%2==0) lazyseg[e][1]^=x;
        e=(e-1)/2;
    }
    if(s==e) lazyseg[s][1]^=x;

}

ll query(ll x){
    ll ret=lazyseg[x][0];
    while(x){
        ret^=lazyseg[x][1];
        x/=2;
    }
    return ret;
}

int main() {
    fastio;

    ll n; cin >> n;
    forf(i, 0, n) cin >> lazyseg[SZ+i][0];
    forb(i, X, 0){
        forf(j, 1<<i, 1<<i+1) lazyseg[j][0]=lazyseg[j*2][0]+lazyseg[j*2+1][0];
    }


    ll q; cin >> q;
    while(q--){
        ll a; cin >> a;
        if(a==1){
            ll p, q, r; cin >> p >> q >> r;
            update(SZ+p, SZ+q, r);
        }
        else{
            ll p; cin >> p;
            cout << query(SZ+p) << "\n";
        }
    }

    return 0;
}
