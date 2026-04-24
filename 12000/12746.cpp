#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef array<ll, 2> pii;
typedef array<ll, 3> tii;
typedef vector<pii> vpii;
typedef __float128 lf;
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

ll n, q;
vvi lnk;
vi dep, C;
V<array<ll, 20>> dp;

void dfs(ll pnt, ll pre, ll D){
    dep[pnt]=D;
    dp[pnt][0]=pre;
    for(ll i : lnk[pnt])
        if(i!=pre) dfs(i, pnt, D+1);
}

void DP(){
    forf(i, 1, 20){
        forf(j, 1, n+1){
            dp[j][i]=dp[dp[j][i-1]][i-1];
        }
    }
}

ll lca(ll p, ll q){
    if(dep[p]>dep[q]) swap(p, q);
    ll depd=dep[q]-dep[p];
    forf(i, 0, 20) if(depd&(1<<i)) q=dp[q][i];
    if(p==q) return p;
    forb(i, 20, 0){
        if(dp[p][i]!=dp[q][i]){p=dp[p][i]; q=dp[q][i];}
    }
    return dp[p][0];
}

tii ans={-1, -1, -1234567};

ll FND(ll pnt, ll pre){
    ll ret=C[pnt];
    for(ll i : lnk[pnt])
        if(i!=pre) ret+=FND(i, pnt);

    if(ret>ans[2]) ans={min(pnt, pre), max(pnt, pre), ret};
    else if(ret==ans[2]){
        if(min(pnt, pre)<ans[0] || (min(pnt, pre)==ans[0] && max(pnt, pre)==ans[1]))
            ans={min(pnt, pre), max(pnt, pre), ret};
    }
    return ret;
}

int main(){
    fastio;

    cin >> n >> q;
    lnk.resize(n+1);
    dep.resize(n+1);
    dp.resize(n+1);
    C.resize(n+1);

    forf(i, 1, n){
        ll a, b; cin >> a >> b;
        lnk[a].pb(b);
        lnk[b].pb(a);
    }

    dfs(1, 0, 0); DP();

    while(q--){
        ll a, b; cin >> a >> b;
        C[a]++;
        C[b]++;
        C[lca(a, b)]-=2;
    }

    FND(1, 0);

    forf(i, 0, 3) cout << ans[i] << " ";

    return 0;
}
