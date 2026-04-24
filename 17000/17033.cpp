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

struct segtree{
    ll X=18;
    ll ar[1<<19]={};

    void update(ll p, ll x){
        p+=1<<X;
        ar[p]=x;
        p>>=1;

        while(p){
            ar[p]=ar[p*2]^ar[p*2+1];
            p>>=1;
        }
    }

    ll mx(ll s, ll e){
        ll ret=0;
        s+=1<<X; e+=1<<X;
        while(s<=e){
            if(s&1) ret^=ar[s];
            if(~e&1) ret^=ar[e];
            s=(s+1)/2; e=(e-1)/2;
        }
        return ret;
    }
} seg;

ll n, q, pv=0;
vi lnk[101010];
ll par[101010], cst[101010], sz[101010], dep[101010];
ll tp[101010], in[101010], out[101010];

void dfs0(ll pnt, ll pre){
    for(auto it=lnk[pnt].begin(); it!=lnk[pnt].end(); it++)
        if(*it==pre){lnk[pnt].erase(it); break;}
    for(ll& i : lnk[pnt]) dfs0(i, pnt);
}

void dfs1(ll pnt){
    sz[pnt]=1;
    for(ll& i : lnk[pnt]){
        par[i]=pnt; dep[i]=dep[pnt]+1;
        dfs1(i); sz[pnt]+=sz[i];
        if(sz[i]>sz[lnk[pnt][0]]) swap(i, lnk[pnt][0]);
    }
}

void dfs2(ll pnt){
    in[pnt]=++pv;
    for(ll i : lnk[pnt]){
        if(i==lnk[pnt][0]) tp[i]=tp[pnt];
        else tp[i]=i;
        dfs2(i);
    }
    out[pnt]=pv;
}

void update(ll pnt, ll x){
    seg.update(in[pnt], x);
}

ll query(ll a, ll b){
    ll ret=0;

    while(tp[a]!=tp[b]){
        if(dep[tp[a]]<dep[tp[b]]) swap(a, b);
        ret^=seg.mx(in[tp[a]], in[a]);
        a=par[tp[a]];
    }
    if(dep[a]>dep[b]) swap(a, b);
    ret^=seg.mx(in[a], in[b]);
    return ret;
}

int main(){
    fastio;

    ll q;
    cin >> n >> q;
    vi x(n);
    forf(i, 0, n) cin >> x[i];
    forf(i, 1, n){
        ll a, b; cin >> a >> b;
        lnk[a-1].pb(b-1);
        lnk[b-1].pb(a-1);
    }
    dfs0(0, -1);
    dfs1(0);
    dfs2(0);

    forf(i, 0, n) update(i, x[i]);

    while(q--){
        ll a, b, c; cin >> a >> b >> c;
        if(a==1) update(b-1, c);
        else cout << query(b-1, c-1) << "\n";
    }

    return 0;
}
