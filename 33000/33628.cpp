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

const ll X=17;
ll n, q;
ll sp[101010][X];
ll dep[101010];
ll unn[101010];
vi uf[101010];
ll minp[101010];
vi lnk[101010];

void dfs(ll pnt, ll pre, ll d_ep){
    sp[pnt][0]=pre; dep[pnt]=d_ep;
    forf(j, 1, X) sp[pnt][j]=sp[sp[pnt][j-1]][j-1];
    for(ll i : lnk[pnt])
        if(i!=pre) dfs(i, pnt, d_ep+1);
}

ll lca(ll a, ll b){
    if(dep[a]<dep[b]) swap(a, b);
    ll dif=dep[a]-dep[b];
    forb(i, X, 0) if(dif&(1<<i)) a=sp[a][i];

    if(a==b) return a;
    forb(i, X, 0){
        if(sp[a][i]!=sp[b][i]){
            a=sp[a][i];
            b=sp[b][i];
        }
    }
    return sp[a][0];
}

ll dist(ll a, ll b){
    return dep[a]+dep[b]-2*dep[lca(a, b)];
}

ll Query(ll a, ll b){
    if(unn[a]!=unn[b]) return 0;
    ll p=minp[unn[a]];
    ll t=lca(a, b), u=lca(a, p), v=lca(b, p);
    return t^u^v;
}

void Merge(ll a, ll b){
    if(uf[unn[a]].size()<uf[unn[b]].size()) swap(a, b);

    dfs(b, a, dep[a]+1);
    minp[unn[a]]=min(minp[unn[a]], minp[unn[b]]);

    ll x=unn[b];
    for(ll i : uf[unn[b]]){
        uf[unn[a]].pb(i); unn[i]=unn[a];
    } uf[x].clear();
}

int main(){
    fastio;

    cin >> n >> q;

    forf(i, 1, n+1){
        unn[i]=i;
        uf[i].pb(i);
        minp[i]=i;
    }

    ll lans=0;
    while(q--){
        ll a, b, c; cin >> a >> b >> c;
        b^=lans; c^=lans;

        if(a==1){
            lnk[b].pb(c);
            lnk[c].pb(b);
            Merge(b, c);
        }
        else{
            ll ret=Query(b, c);
            cout << ret << "\n";
            lans=ret;
        }
    }

    return 0;
}
