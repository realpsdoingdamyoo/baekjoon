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

const ll X=17;
ll seg[1<<X+1];
ll lazy[1<<X+1];
ll sz[1<<X+1];

void prop(ll p){
    if(p==1) return;
    prop(p>>1);

    if(lazy[p>>1]){
        seg[p]=sz[p]-seg[p]; lazy[p]^=1;
        seg[p^1]=sz[p^1]-seg[p^1]; lazy[p^1]^=1;
        lazy[p>>1]=0;
    }
}


void upseg(ll p){
    if(p==1) return;
    seg[p>>1]=seg[p]+seg[p^1];
    upseg(p>>1);
}

void update(ll s, ll e){
    s+=1<<X; e+=1<<X;
    while(s<=e){
        if(s%2==1){
            prop(s);
            seg[s]=sz[s]-seg[s];
            lazy[s]^=1;
            upseg(s);
        }
        if(e%2==0){
            prop(e);
            seg[e]=sz[e]-seg[e];
            lazy[e]^=1;
            upseg(e);
        }
        s=(s+1)/2;
        e=(e-1)/2;
    }
}

ll Q(ll s, ll e){
    s+=1<<X; e+=1<<X;
    ll r=0;
    while(s<=e){
        if(s%2==1){
            prop(s);
            r+=seg[s];
        }
        if(e%2==0){
            prop(e);
            r+=seg[e];
        }
        s=(s+1)/2;
        e=(e-1)/2;
    }
    return r;
}

int main(){
    fastio;

    forf(i, 0, X+1) forf(j, 1<<i, 1<<i+1) sz[j]=1<<X-i;

    ll n, q; cin >> n >> q;
    while(q--){
        ll a, b, c; cin >> a >> b >> c;
        if(a==0) update(b-1, c-1);
        else cout << Q(b-1, c-1) << "\n";

        /*forf(i, 0, X+1){
            forf(j, 1<<i, 1<<i+1) cout << "[" << seg[j] << " " << lazy[j] << "]";
            cout << "\n";
        }*/

    }

    return 0;
}
