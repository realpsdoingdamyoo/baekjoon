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

vi press(vi v){
    vi u=v; sortv(u);
    u.erase(unique(all(u)), u.end());
    forf(i, 0, v.size()){
        v[i]=lower_bound(all(u), v[i])-u.begin();
    }
    return v;
}

const ll X=18;
ll seg[1<<X+1];

void update(ll p, ll x){
    p+=1<<X;
    while(p){seg[p]=max(seg[p], x); p>>=1;}
}
ll MX(ll e){
    ll s=1<<X; e+=1<<X; ll ret=0;
    while(s<=e){
        ret=max(ret, seg[e]);
        s>>=1; e=(e-1)>>1;
    }
    return ret;
}

void solve(){
    forf(i, 0, 1<<X+1) seg[i]=0;

    ll n, ret=0; cin >> n;
    vi v(n); vcin; v=press(v);
    forf(i, 0, n) v[i]++;

    ll i=0, j=0;
    for(ll i=0; i<n; i=j+1){
        j=i; while(j<n-1 && v[j]<v[j+1]) j++;
        ll c=j-i+1;
        for(ll l=i; l<=j; l++){
            ret=max(ret, c+MX(v[l]-1));
            c--;
        }

        c=1;
        for(ll l=i; l<=j; l++){
            update(v[l], c);
            c++;
        }
    }
    cout << ret << "\n";
}

int main(){
    fastio;

    ll t; cin >>t;
    while(t--) solve();


    return 0;
}
