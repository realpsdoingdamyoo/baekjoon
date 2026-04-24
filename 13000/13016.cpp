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
#define cf; cout.flush();

ll n;
V<vpii> lnk;
vi D[2];
ll farp[2];

void dfs(ll pnt, ll pre, ll dst, ll id){
    D[id][pnt]=dst;
    if(D[id][farp[id]]<dst) farp[id]=pnt;
    for(pii i : lnk[pnt])
        if(i[0]!=pre) dfs(i[0], pnt, dst+i[1], id);
}

int main(){
    fastio;

    cin >> n;
    lnk.resize(n);
    D[0].resize(n); D[1].resize(n);

    forf(i, 0, n-1){
        ll a, b, c; cin >> a >> b >> c;
        lnk[a-1].pb({b-1, c});
        lnk[b-1].pb({a-1, c});
    }

    dfs(0, -1, 0, 0);
    dfs(farp[0], -1, 0, 1);
    dfs(farp[1], -1, 0, 0);

    forf(i, 0, n) cout << max(D[0][i], D[1][i]) << "\n";


    return 0;
}
