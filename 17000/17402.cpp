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

ll n, m;
vvi lnk;
vi match;
V<bool> cons;

bool dfs(ll pnt){
    for(ll i : lnk[pnt]){
        if(cons[i]) continue;
        cons[i]=true;
        if(match[i]==-1 || dfs(match[i])){
            match[i]=pnt; return true;
        }
    }
    return false;
}

ll BM(){
    ll r=0;
    forf(i, 0, n){
        forf(j, 0, m) cons[j]=false;
        r+=dfs(i);
    }
    return r;
}

int main(){
    fastio;

    cin >> n >> m;
    lnk.resize(n);
    match.resize(m);
    cons.resize(m);
    forf(i, 0, m) match[i]=-1;

    ll c; cin >> c;
    forf(i, 0, c){
        ll s, e; cin >> s >> e;
        lnk[s-1].pb(e-1);
    }

    cout << n+m-BM();


    return 0;
}
