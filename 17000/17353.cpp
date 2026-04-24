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

const ll X=17;

struct lazyseg{
    ll seg[1<<X+1];
    pii lazy[1<<X+1];
    ll sz[1<<X+1];

    void init(){
        forf(i, 0, X+1){
            forf(j, 1<<i, 1<<i+1)
                sz[j]=1<<(X-i);
        }
    }

    ll val(ll p){
        return lazy[p][0]*sz[p]+lazy[p][1]*sz[p]*(sz[p]-1)/2;
    }

    void prop(ll p){
        lazy[p<<1][0]+=lazy[p][0];
        lazy[p<<1][1]+=lazy[p][1];
        lazy[p<<1|1][0]+=lazy[p][0]+lazy[p][1]*sz[p<<1];
        lazy[p<<1|1][1]+=lazy[p][1];
        seg[p]+=val(p);
        lazy[p]={0, 0};
    }

    void segup(ll p){
        seg[p]=seg[p<<1]+seg[p<<1|1]+val(p<<1)+val(p<<1|1);
    }

    void update(ll s, ll e, ll x, ll y){
        ll S=s+=1<<X;
        ll E=e+=1<<X;
        ll z;
        if(s==e) z=0;
        else z=(y-x)/(e-s);

        forb(i, X+1, 1) prop(s>>i), prop(e>>i);

        while(s<=e){
            if(s&1){
                lazy[s][0]+=x;
                lazy[s][1]+=z;
                x+=z*sz[s];
            }
            if(~e&1){
                lazy[e][0]+=y-z*(sz[e]-1);
                lazy[e][1]+=z;
                y-=z*sz[e];
            }
            s=s+1>>1; e=e-1>>1;
        }

        forf(i, 1, X+1) segup(S>>i), segup(E>>i);
    }

    ll query(ll s, ll e){
        s+=1<<X; e+=1<<X;

        forb(i, X+1, 1) prop(s>>i), prop(e>>i);

        ll ret=0;

        while(s<=e){
            if(s&1) ret+=val(s);
            if(~e&1) ret+=val(e);
            s=s+1>>1; e=e-1>>1;
        }
        return ret;
    }
} seg;


int main(){
    fastio;
    seg.init();

    ll n; cin >> n;
    forf(i, 0, n){
        ll a; cin >> a;
        seg.update(i, i, a, a);
    }

    ll q; cin >> q;
    while(q--){
        ll a; cin >> a;
        if(a==1){
            ll b, c; cin >> b >> c;
            seg.update(b-1, c-1, 1, c-b+1);
        }
        else{
            ll b; cin >> b;
            cout << seg.query(b-1, b-1) << "\n";
        }
    }

    return 0;
}
