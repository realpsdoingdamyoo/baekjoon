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
#define cf cout.flush()

ll fac[500005]={1};

ll inv(ll p){
    ll ret=1, x=mod-2;
    while(x){
        if(x&1) ret=ret*p%mod;
        p=p*p%mod; x>>=1;
    }
    return ret;
}

void solve(){
    ll n, q; cin >> n >> q;
    vpii v(q);
    forf(i, 0, q) cin >> v[i][0] >> v[i][1];
    sortv(v);

    forf(i, 0, q-1){
        if(v[i][1]>=v[i+1][0]){
            cout << "0\n";
            return;
        }
    }

    map<ll, ll> mp;
    for(pii i : v){
        mp[i[0]]=i[1]-1;
        mp[i[1]+1]=i[1];
    }
    mp[n+1]=n;

    ll ret=fac[n+1];
    for(pair<ll, ll> p : mp){
        ret=ret*inv(p.second+1)%mod;
    }
    cout << ret << "\n";
}

int main(){
    fastio;

    forf(i, 1, 500005)
        fac[i]=fac[i-1]*i%mod;


    ll t; cin >> t;
    while(t--) solve();

    return 0;
}
