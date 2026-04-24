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

vvi mst;
ll n, t=1;

void jgf(ll p){
    if(p>=t) return;
    jgf(p*2); jgf(p*2+1);
    for(ll i : mst[p*2]) mst[p].pb(i);
    for(ll i : mst[p*2+1]) mst[p].pb(i);
    sortv(mst[p]);
}

ll onevec(ll p, ll k){
    vi& v=mst[p];

    ll s=0, e=v.size()-1;
    while(s<=e){
        ll m=(s+e)/2;
        if(v[m]>k) e=m-1;
        else s=m+1;
    }
    return v.size()-1-e;
}

ll query(ll s, ll e, ll k, ll t){
    if(s==e) return onevec(s, k);
    ll res=0;
    while(t){
        if((s&t)==(e&t)) t>>=1;
        else{
            if(e-s==t*2-1) return onevec(s/t/2, k);
            else return query(s, e/t*t-1, k, t)+query(e/t*t, e, k, t);
        }
    }
    return onevec(s, k);
}

int main(){
    fastio;

    cin >> n;
    while(t<n) t<<=1;
    mst.resize(t*2);
    forf(i, t, t+n){
        ll a; cin >> a;
        mst[i].pb(a);
    }
    jgf(1);

    /*forf(i, 1, t+n){
        cout << i << "  " << mst[i].size() << " ";
        for(ll j : mst[i]) cout << j << " ";
        cout << "/" << onevec(i, 3);
        cout << "\n";
    }*/

    ll q, a=0; cin >> q;
    while(q--){
        ll i, j, k; cin >> i >> j >> k;
        i^=a; j^=a; k^=a;
        a=query(t+i-1, t+j-1, k, t);
        cout << a << "\n";
    }

    return 0;
}
