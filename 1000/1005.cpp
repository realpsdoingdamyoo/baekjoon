#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef array<ll, 2> pii;
typedef vector<pii> vpii;
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define vcin; for(int i=0; i<n; i++) cin >> v[i];
#define forf(i, s, e) for(int i=s; i<e; i++)
#define forb(i, s, e) for(int i=s-1; i>=e; i--)
#define sortv(v) sort(v.begin(), v.end())
#define sortc(v, cmp) sort(v.begin(), v.end(), cmp)
#define repeat(n) for(int not_used_name=0; not_used_name<n; not_used_name++)
const int mod=1e9+7, MOD=998244353;
const int dir4[4][2]={{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
const int dir8[8][2]={{0, 1}, {1, 0}, {-1, 0}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
const ll inf=2147483647, linf=9223372036854775807;
ll gcd(ll a, ll b){return b?gcd(b, a%b):a;}


ll n, q;
vi dp, t, dpv;
vvi bef;

ll dpf(ll x){
    if(dpv[x]) return dp[x];
    dpv[x]=1;
    if(bef[x].empty()) return dp[x];
    for(ll i : bef[x]) dp[x]=max(dp[x], dpf(i)+t[i]);
    return dp[x];
}

int main() {
    fastio;

    ll tt; cin >> tt;
    repeat(tt){
        cin >> n >> q;
        dp.resize(0); bef.resize(0); t.resize(0); dpv.resize(0);
        dp.resize(n); bef.resize(n); t.resize(n); dpv.resize(n);
        forf(i, 0, n) cin >> t[i];
        forf(i, 0, q){
            ll a, b; cin >> a >> b;
            bef[b-1].push_back(a-1);
        }
        ll e; cin >> e;
        cout << dpf(e-1)+t[e-1] << "\n";
    }

    return 0;
}
