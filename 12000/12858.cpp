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
const vpii dir4={{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
const vpii dir8={{0, 1}, {1, 0}, {-1, 0}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
const ll inf=2147483647, linf=9223372036854775807;
const double pi=acos(-1), E=2.718281828459;
ll gcd(ll a, ll b){return b?gcd(b, a%b):a;}
#define cf; cout.flush();

const ll X=18;
ll segtree[1<<X+1];
ll lazy[1<<X+1];

void update(ll p, ll x){
    p+=1<<X; segtree[p]+=x; p>>=1;
    while(p){
        segtree[p]=gcd(abs(segtree[p*2]), abs(segtree[p*2+1]));
        p>>=1;
    }
}

ll g(ll s, ll e){
    s+=1<<X; e+=1<<X;
    ll r=0;
    while(s<=e){
        if(s%2==1) r=gcd(r, abs(segtree[s])); s=(s+1)/2;
        if(e%2==0) r=gcd(r, abs(segtree[e])); e=(e-1)/2;
    }
    return r;
}

void lupdate(ll s, ll e, ll x){
    s+=1<<X; e+=1<<X;
    while(s<=e){
        if(s%2==1) lazy[s]+=x; s=(s+1)/2;
        if(e%2==0) lazy[e]+=x; e=(e-1)/2;
    }
}

ll lval(ll p){
    p+=1<<X;
    ll r=0;
    while(p){
        r+=lazy[p];
        p>>=1;
    }
    return r;
}

void uquery(ll s, ll e, ll t){
    update(s-1, -t); update(e, t);
    lupdate(s, e, t);
}

ll uval(ll s, ll e){
    return gcd(g(s, e-1), lval(s));
}

int main() {
    fastio;

    ll n; cin >> n;
    forf(i, 1, n+1) cin >> lazy[i+(1<<X)];
    forf(i, 0, n+2) update(i, lazy[i+(1<<X)]-lazy[i+(1<<X)+1]);
    ll q; cin >> q;
    while(q--){
        ll t, s, e; cin >> t >> s >> e;
        if(t) uquery(s, e, t);
        else cout << uval(s, e) << "\n";

        /*forf(i, 0, X+1){
            forf(j, 1<<i, 1<<i+1) cout << segtree[j] << " ";
            cout << "\n";
        }*/
    }

    return 0;
}
