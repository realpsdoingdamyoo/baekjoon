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
#define cf cout.flush()

vvi dag, tree;
vpii ed;
vi dc, cnt, dst;
V<bool> col;

ll dfs(ll p){
    ll ret=(dst[p]%2+1)*cnt[p];

    for(ll i : tree[p]){
        dst[i]=dst[p]+1;
        ret+=dfs(i);
    }
    return ret;
}

void solve(){
    ll n, m; cin >> n >> m;
    dag.clear(); dag.resize(n);
    dc.clear(); dc.resize(n);
    cnt.clear(); cnt.resize(n);
    ed.clear();
    tree.clear(); tree.resize(n);
    dst.clear(); dst.resize(n);

    forf(i, 0, n) cin >> cnt[i];

    forf(i, 0, m){
        ll a, b; cin >> a >> b;
        dag[b-1].pb(a-1); dc[a-1]++;
        ed.pb({a-1, b-1});
    }

    col.clear(); col.resize(n);
    vi z; forf(i, 0, n) if(dc[i]==0) z.pb(i);

    while(z.size()){
        ll p=z.back(); z.pop_back();
        for(ll i : dag[p]){
            if(!--dc[i]) z.pb(i);
            if(!col[p]) col[i]=true;
        }
    }

    set<ll> root;
    forf(i, 0, n) if(col[i]) root.insert(i);

    for(pii i : ed){
        if(!col[i[0]] || !col[i[1]]) continue;
        tree[i[1]].pb(i[0]);
        if(root.find(i[0])!=root.end())
            root.erase(root.find(i[0]));
    }

    ll nim=0;
    for(ll i : root) nim^=dfs(i)%3;
    if(nim==0) cout << "Second\n";
    else cout << "First\n";
}


int main(){
    fastio;

    ll t; cin >> t;
    while(t--) solve();

    return 0;
}
