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

ll n, m;

vi uf;
vvi unions;
vpii e;

void sum(ll a, ll b){
    a=uf[a]; b=uf[b];
    if(a==b) return;

    if(unions[a].size()<unions[b].size()) swap(a, b);

    for(ll i : unions[b]){
        unions[a].pb(i);
        uf[i]=a;
    } unions[b].clear();
}

bool rmv(ll a, ll b){
    return (max(uf[a], uf[b])==max(uf[0], uf[n-1]) && min(uf[a], uf[b])==min(uf[0], uf[n-1]));
}

ll pw(ll x){
    ll t=3, r=1;
    while(x){
        if(x&1) r=r*t%mod;
        t=t*t%mod; x/=2;
    }
    return r;
}

int main(){
    fastio;

    cin >> n >> m; e.resize(m);
    uf.resize(n); unions.resize(n);
    forf(i, 0, m) cin >> e[i][0] >> e[i][1];
    forf(i, 0, n){
        uf[i]=i;
        unions[i].pb(i);
    }

    ll ans=0;
    forb(i, m, 0){
        if(rmv(e[i][0], e[i][1])) ans+=pw(i);
        else sum(e[i][0], e[i][1]);
    }
    cout << ans%mod;

    return 0;
}
