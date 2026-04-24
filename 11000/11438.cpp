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
ll lcm(ll a, ll b){return a/gcd(a, b)*b;}

ll n;
vvi lnk;
vi depth;
vvi dp(20);

void dfs(ll pnt, ll pre, ll dph){
    dp[0][pnt]=pre; depth[pnt]=dph;
    for(ll i : lnk[pnt]){
        if(i!=pre) dfs(i, pnt, dph+1);
    }
}

int main(){
    fastio;

    cin >> n;
    lnk.resize(n+1); depth.resize(n+1);

    forf(i, 0, n-1){
        ll a, b; cin >> a >> b;
        lnk[a].pb(b);
        lnk[b].pb(a);
    }
    forf(i, 0, 20) dp[i].resize(n+1);
    dfs(1, 0, 0);

    forf(i, 0, 19){
        forf(j, 0, n+1){
            dp[i+1][j]=dp[i][dp[i][j]];
        }
    }

    ll q; cin >> q;

    while(q--){
        ll a, b; cin >> a >> b;
        if(depth[a]>depth[b]) swap(a, b);
        ll dst=depth[b]-depth[a];
        forf(i, 0, 20){
            if(dst&(1<<i)) b=dp[i][b];
        }

        if(a==b){cout << a << "\n"; continue;}

        forb(i, 20, 0){
            if(dp[i][a]!=dp[i][b]){a=dp[i][a]; b=dp[i][b];}
        }

        cout << dp[0][a] << "\n";
    }

    return 0;
}
