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

ll n, cnt;
vvi lnk;
vi dfsord;
vvi sub;
vi par;
vi inq;
vi sz;

void dfs(ll pnt, ll pre){
    dfsord[pnt]=cnt++;
    par[pnt]=pre;
    for(ll i : lnk[pnt])
        if(i!=pre)
            dfs(i, pnt);
}

bool cmp(ll a, ll b){
    return dfsord[a]>dfsord[b];
}

ll subp(vi& v){
    ll ret=0;
    for(ll i : v) ret+=i; ret*=ret;
    for(ll i : v) ret-=i*i; ret/=2;
    return ret;
}

ll query(vi& Q){
    ll s=Q.size(), ret=0;
    sortc(Q, cmp);
    vi stk;

    for(ll i : Q){
        ret+=subp(sub[i])+sz[i];
        sz[i]++;
        if(inq[par[i]]){
            sub[par[i]].pb(sz[i]);
            sz[par[i]]+=sz[i];
        }
        sub[i].clear();
        sz[i]=0;
    }
    return ret;
}

int main(){
    fastio;

    cin >> n;
    lnk.resize(n); dfsord.resize(n);
    sub.resize(n); par.resize(n); inq.resize(n+1);
    sz.resize(n);
    forf(i, 0, n-1){
        ll a, b; cin >> a >> b;
        lnk[a-1].pb(b-1); lnk[b-1].pb(a-1);
    }
    dfs(0, n);

    ll q; cin >> q;
    while(q--){
        vi Q;
        ll a; cin >> a;
        Q.resize(a);
        forf(i, 0, a) cin >> Q[i];
        forf(i, 0, a) Q[i]--;
        for(ll i : Q) inq[i]=1;
        cout << query(Q) << "\n";
        for(ll i : Q) inq[i]=0;
    }


    return 0;
}
