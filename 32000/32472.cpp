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

ll n, a, b, x;
vi sz;
vvi lnk;
ll dp[101010][555];

void dfs(ll pnt, ll pre){
    dp[pnt][1]=1; sz[pnt]=1;

    for(ll i : lnk[pnt]){
        if(i==pre) continue;
        dfs(i, pnt);

        forb(j, min(b, sz[pnt])+1, 1){
            forf(k, 1, min(b-j, sz[i])+1)
                dp[pnt][j+k]=(dp[pnt][j+k]+dp[pnt][j]*dp[i][k])%mod;
            dp[pnt][j]=dp[pnt][j]*dp[i][0]%mod;
        }
        sz[pnt]+=sz[i];
    }
    dp[pnt][0]=(dp[pnt][a]+dp[pnt][b])%mod;
}

int main(){
    fastio;

    cin >> n >> a >> b;
    lnk.resize(n); sz.resize(n);
    forf(i, 1, n){
        ll x, y; cin >> x >> y;
        lnk[x-1].pb(y-1);
        lnk[y-1].pb(x-1);
    }

    dfs(0, -1);
    cout << dp[0][0];

    return 0;
}
