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
#define cf; cout.flush();

const ll X=31;
unordered_map<ll, ll> mp[X];

void ID(ll p, ll x){
    forb(i, X, 0){
        mp[i][p]+=x;
        if(mp[i][p]==0) mp[i].erase(p);
        p>>=1;
    }
}

ll Q(ll p){
    ll ret=0;
    forf(i, 0, X){
        if(mp[i].find(ret<<1)==mp[i].end()){
            ret=ret<<1|1;
        }
        else if(mp[i].find(ret<<1|1)==mp[i].end()){
            ret<<=1;
        }
        else{
            ll sh=X-i-1;
            if((((ret<<1)<<sh)^p)<(((ret<<1|1)<<sh)^p)) ret=ret<<1|1;
            else ret<<=1;
        }
    }
    return ret;
}

int main(){
    fastio;

    ll t; cin >> t;
    while(t--){
        forf(i, 0, X) mp[i].clear();
        ID(0, 1);
        ll n, mx=0, x=0; cin >> n;
        forf(i, 0, n){
            ll a; cin >> a;
            x^=a;
            ID(x, 1);
            mx=max(mx, x^Q(x));
        }
        cout << mx << "\n";
    }

    return 0;
}
