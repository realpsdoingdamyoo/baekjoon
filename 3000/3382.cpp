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

ll n;
V<array<ll, 20>> dp;
vvi lnk;

void dfs(ll pnt, ll pre){
    forf(i, 0, 20) dp[pnt][i]=i;

    for(ll i : lnk[pnt]){
        if(i==pre) continue;
        dfs(i, pnt);

        forf(j, 0, 20){
            ll tp=inf;
            forf(l, 0, 20){
                if(j==l) continue;
                tp=min(tp, dp[i][l]);
            }
            dp[pnt][j]+=tp;
        }
    }
}

int main(){
    fastio;

    cin >> n;
    lnk.resize(n);
    dp.resize(n);
    forf(i, 1, n){
        ll a, b; cin >> a >> b;
        lnk[a-1].pb(b-1);
        lnk[b-1].pb(a-1);
    }

    dfs(0, -1);

    ll ret=inf;
    forf(i, 0, 20) ret=min(ret, dp[0][i]);

    cout << ret+n;

    return 0;
}
