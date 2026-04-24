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
const double PI=acos(-1), E=2.718281828459;
ll gcd(ll a, ll b){return b?gcd(b, a%b):a;}

const ll X=300, Y=131313/X;
ll n, m, ans[50505];
pii ed[131313];
V<tii> query[Y];

ll uc;
ll g[707];
vpii vec;

bool cmp(tii a, tii b){return a[1]<b[1];}

ll Find(ll x){return g[x]>0?Find(g[x]):x;}

void Union(ll a, ll b){
    a=Find(a); b=Find(b);
    if(a==b) vec.push_back({0, 0}), vec.push_back({0, 0});
    else{
        uc++;
        if(-g[a]<-g[b]) swap(a, b);
        vec.pb({a, g[a]}); vec.pb({b, g[b]});
        g[a]+=g[b]; g[b]=a;
    }
}

void rollback(){
    if(vec.back()[0]) uc--;
    g[vec.back()[0]]=vec.back()[1]; vec.pop_back();
    g[vec.back()[0]]=vec.back()[1]; vec.pop_back();
}

void solve(ll st, V<tii> Q){
    if(st>m) return;
    for(ll i=1; i<=n; i++) g[i]=-1; vec.clear(); uc=0;
    for(ll i=0; i<st; i++) Union(ed[i][0], ed[i][1]);

    ll en=st;
    for(ll i=m-1; i>=en; i--) Union(ed[i][0], ed[i][1]);

    for(tii t : Q){
        while(en<=t[1]) en++, rollback();
        for(ll i=st; i<t[0]; i++) Union(ed[i][0], ed[i][1]);
        ans[t[2]]=n-uc;
        for(ll i=t[0]-1; i>=st; i--) rollback();
    }
}

int main(){
    fastio;

    cin >> n >> m;
    for(ll i=0; i<m; i++) cin >> ed[i][0] >> ed[i][1];
    for(ll i=m; i<131313; i++) ed[i]={1, 1};

    ll q; cin >> q;
    for(ll i=0; i<q; i++){
        ll a, b; cin >> a >> b; a--; b--;
        query[a/X].pb({a, b, i});
    }

    for(V<tii>& i : query) sortc(i, cmp);
    for(ll i=0; i<Y; i++) solve(X*i, query[i]);

    for(ll i=0; i<q; i++) cout << ans[i] << "\n";

    return 0;
}
