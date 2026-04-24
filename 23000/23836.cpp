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

const ll X=18;

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

    void print(){
        forf(i, 0, X+1){
            forf(j, 1<<i, 1<<i+1){
                cout <<"[" << seg[j] <<" " << lazy[j][0] << " " << lazy[j][1] << "]";
            }
            cout <<"\n";
        }
    }
} seg;

ll n, q, pv=0;
vi lnk[101010];
ll par[101010], sz[101010], in[101010], out[101010];
ll tp[101010], dep[101010];
ll sp[101010][20];

void dfs0(ll pnt, ll pre){
    for(auto it=lnk[pnt].begin(); it!=lnk[pnt].end(); it++)
        if(*it==pre){lnk[pnt].erase(it); break;}
    for(ll i : lnk[pnt]) dfs0(i, pnt);
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

void sparse(){
    forf(i, 0, n) sp[i][0]=par[i];
    forf(j, 1, 20) forf(i, 0, n) sp[i][j]=sp[sp[i][j-1]][j-1];
}

ll lca(ll a, ll b){
    if(dep[a]<dep[b]) swap(a, b);
    ll df=dep[a]-dep[b];
    forb(i, 20, 0) if((1<<i)&df) a=sp[a][i];
    if(a==b) return a;

    forb(i, 20, 0){
        if(sp[a][i]!=sp[b][i]){
            a=sp[a][i]; b=sp[b][i];
        }
    }
    return sp[a][0];
}

ll pntdist(ll a, ll b){
    return dep[a]+dep[b]-2*dep[lca(a, b)];
}

void _update(ll a, ll b, ll s, ll e){
    ll z=(s<e)-(e<s);
    while(tp[a]!=tp[b]){
        ll d=in[b]-in[tp[b]]+1;
        seg.update(in[tp[b]], in[b], s+(d-1)*z, s);
        s+=d*z;
        b=par[tp[b]];
    }
    ll d=in[b]-in[a]+1;
    seg.update(in[a], in[b], s+(d-1)*z, s);
}

void update(ll a, ll b){
    ll l=lca(a, b);
    _update(l, a, 0, pntdist(a, l));
    _update(l, b, pntdist(a, b), pntdist(a, l));
    _update(l, l, -pntdist(a, l), -pntdist(a, l));
}

ll query(ll a, ll b){
    ll ret=0;

    while(tp[a]!=tp[b]){
        if(dep[tp[a]]<dep[tp[b]]) swap(a, b);
        ret+=seg.query(in[tp[a]], in[a]);
        a=par[tp[a]];
    }
    if(dep[a]>dep[b]) swap(a, b);
    ret+=seg.query(in[a], in[b]);
    return ret;
}

int main(){
    fastio;
    seg.init();

    cin >> n;
    forf(i, 1, n){
        ll a, b; cin >> a >> b;
        lnk[a-1].pb(b-1);
        lnk[b-1].pb(a-1);
    }
    dfs0(0, 0);
    dfs1(0); dfs2(0);
    sparse();

    ll q; cin >> q;
    while(q--){
        ll a; cin >> a;
        if(a==1){
            ll b, c; cin >> b >> c;
            update(b-1, c-1);
        }
        else{
            ll b; cin >> b;
            cout << query(b-1, b-1) << "\n";
        }
    }

    return 0;
}
