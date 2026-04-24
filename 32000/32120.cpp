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
#define cf cout.flush()

ll n;
vvi lnk;
vi H;
V<array<ll, 20>> dp;

pii df(ll pnt, ll pre, ll dst){
    pii fp={dst, pnt};
    for(ll i : lnk[pnt])
        if(i!=pre) fp=max(fp, df(i, pnt, dst+1));
    return fp;
}

void df2(vi& d, ll pnt, ll pre, ll dst){
    d[pnt]+=dst;
    for(ll i : lnk[pnt])
        if(i!=pre) df2(d, i, pnt, dst+1);
}

void dfs(ll pnt, ll pre, ll dst){
    H[pnt]=dst; dp[pnt][0]=pre;
    for(ll i : lnk[pnt])
        if(i!=pre) dfs(i, pnt, dst+1);
}

void dpset(){
    forf(i, 1, 20){
        forf(j, 0, n){
            dp[j][i]=dp[dp[j][i-1]][i-1];
        }
    }
}

ll lca(ll a, ll b){
    if(H[a]<H[b]) swap(a, b);
    ll df=H[a]-H[b];
    forf(i, 0, 20) if(df&(1<<i)) a=dp[a][i];

    if(a==b) return a;

    forb(i, 20, 0){
        if(dp[a][i]!=dp[b][i]){
            a=dp[a][i];
            b=dp[b][i];
        }
    }
    return dp[a][0];
}

ll dist(ll a, ll b){
    return H[a]+H[b]-2*H[lca(a, b)];
}

int main(){
    fastio;

    cin >> n;
    lnk.resize(n);
    H.resize(n);
    dp.resize(n);

    forf(i, 1, n){
        ll a, b; cin >> a >> b;
        lnk[a-1].pb(b-1);
        lnk[b-1].pb(a-1);
    }

    ll d1=df(0, -1, 0)[1];
    ll d2=df(d1, -1, 0)[1];
    ll d3=0;

    vi dv(n);
    df2(dv, d1, -1, 0);
    df2(dv, d2, -1, 0);
    forf(i, 0, n)
        if(dv[d3]<dv[i]) d3=i;

    dfs(0, 0, 0);
    dpset();

    ll q; cin >> q;
    while(q--){
        ll a, b; cin >> a >> b;
        a--; b--;

        ll ret=0;
        ret=max(ret, dist(d1, a)+dist(d1, b));
        ret=max(ret, dist(d2, a)+dist(d2, b));
        ret=max(ret, dist(d3, a)+dist(d3, b));

        cout << ret << "\n";
    }

    return 0;
}
