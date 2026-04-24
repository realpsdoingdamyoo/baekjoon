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
    ll X;
    vi sg;
    vi ar;

    void update(ll p, ll x){
        p+=1<<X;
        while(p){
            sg[p]=(sg[p]+x)%mod;
            p>>=1;
        }
    }

    ll sum(ll s, ll e){
        s+=1<<X; e+=1<<X;
        ll ret=0;
        while(s<=e){
            if(s&1) ret+=sg[s];
            if(~e&1) ret+=sg[e];
            s=s+1>>1; e=e-1>>1;
        }
        return ret%mod;
    }
} M;

V<segtree> seg;

int main(){
    fastio;

    ll n; cin >> n;
    vi v(n), u(n);
    forf(i, 0, n) cin >> v[i];

    vi lis;

    forf(i, 0, n){
        if(lis.size()==0 || lis.back()<v[i]){
            lis.pb(v[i]); u[i]=lis.size()-1;
            seg.pb(M);
        }
        else{
            ll a=lower_bound(all(lis), v[i])-lis.begin();
            lis[a]=v[i]; u[i]=a;
        }
        seg[u[i]].ar.pb(v[i]);
    }

    for(segtree& s : seg){
        sortv(s.ar);
        vi nar;
        ll mn=-inf;
        for(ll i : s.ar){
            if(i>mn) nar.pb(i);
            mn=max(mn, i);
        }
        s.ar=nar;
        s.ar.pb(inf);

        while((1<<s.X)<s.ar.size()) s.X++;
        s.sg.resize(1<<s.X+1);
    }

    forf(i, 0, n){
        if(u[i]==0){
            seg[0].update(lower_bound(all(seg[0].ar), v[i])-seg[0].ar.begin(), 1);
        }
        else{
            ll p=seg[u[i]-1].sum(0, prev(lower_bound(all(seg[u[i]-1].ar), v[i]))-seg[u[i]-1].ar.begin());
            seg[u[i]].update(lower_bound(all(seg[u[i]].ar), v[i])-seg[u[i]].ar.begin(), p);
        }
    }
    cout << lis.size() << " " << seg[lis.size()-1].sum(0, (1<<seg.back().X)-1);

    return 0;
}
