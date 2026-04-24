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

vpii era(vpii v, ll xs, ll xe, ll ys, ll ye){
    vpii u;
    for(pii i : v){
        if(i[0]<xs || i[0]>xe || i[1]<ys || i[1]>ye)
            u.pb(i);
    }
    return u;
}

bool cvr(vpii v, ll sz, ll c){
    if(c==0) return !v.size();

    ll xs=inf, ys=inf;
    ll xe=-inf, ye=-inf;

    for(pii i : v){
        xs=min(xs, i[0]);
        xe=max(xe, i[0]);
        ys=min(ys, i[1]);
        ye=max(ye, i[1]);
    }


    bool ret=false;
    ret=ret || cvr(era(v, xs, xs+sz, ys, ys+sz), sz, c-1);
    ret=ret || cvr(era(v, xs, xs+sz, ye-sz, ye), sz, c-1);
    ret=ret || cvr(era(v, xe-sz, xe, ys, ys+sz), sz, c-1);
    ret=ret || cvr(era(v, xe-sz, xe, ye-sz, ye), sz, c-1);
    return ret;
}

void solve(){
    ll n; cin >> n;
    vpii v(n);
    forf(i, 0, n*2) cin >> v[i/2][i%2];

    ll s=0, e=inf;
    while(s<=e){
        ll m=(s+e)/2;
        if(cvr(v, m, 3)) e=m-1;
        else s=m+1;
    }
    cout << s << "\n";
}



int main(){
    fastio;

    ll t; cin >> t;
    while(t--) solve();


    return 0;
}
