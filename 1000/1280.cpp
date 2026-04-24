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
ll segtree[2][1<<X+1];

void update(ll t, ll p, ll x){
    p+=1<<X;
    while(p){
        segtree[t][p]+=x;
        p>>=1;
    }
}
ll sum(ll t, ll s, ll e){
    ll ret=0;
    s+=1<<X; e+=1<<X;
    while(s<=e){
        if(s&1) ret+=segtree[t][s];
        s=(s+1)>>1;
        if(!(e&1)) ret+=segtree[t][e];
        e=(e-1)>>1;
    }
    return ret;
}

int main(){
    fastio;

    ll n, r=1; cin >> n;
    forf(i, 0, n){
        ll a; cin >> a;
        update(0, a, 1);
        update(1, a, a);
        ll s=0;
        s+=sum(0, 0, a-1)*a-sum(1, 0, a-1);
        s+=sum(1, a+1, 200001)-sum(0, a+1, 200001)*a;
        if(i) r=s%mod*r%mod;
    }
    cout << r << "\n";

    return 0;
}
