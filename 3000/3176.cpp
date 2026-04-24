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
V<vpii> lnk;
V<array<ll, 20>> dp;
V<array<pii, 20>> sps;
vi dep;

pii MRG(pii a, pii b){
    return {min(a[0], b[0]), max(a[1], b[1])};
}

void dfs(ll pnt, ll pre, ll RD, ll D){
    dp[pnt][0]=pre;
    dep[pnt]=RD;
    sps[pnt][0]={D, D};

    for(pii i : lnk[pnt])
        if(i[0]!=pre) dfs(i[0], pnt, RD+1, i[1]);
}

void sparse(){
    forf(i, 1, 20) forf(j, 1, n+1){
        dp[j][i]=dp[dp[j][i-1]][i-1];
        sps[j][i]=MRG(sps[j][i-1], sps[dp[j][i-1]][i-1]);
    }
}

pii query(ll a, ll b){
    pii ret={inf, -inf};
    if(dep[a]>dep[b]) swap(a, b);
    ll ddf=dep[b]-dep[a];

    forf(i, 0, 20){
        if(ddf&(1<<i)){
            ret=MRG(ret, sps[b][i]);
            b=dp[b][i];
        }
    }

    if(a==b) return ret;

    forb(i, 20, 0){
        if(dp[a][i]==dp[b][i]) continue;
        ret=MRG(ret, sps[a][i]);
        ret=MRG(ret, sps[b][i]);
        a=dp[a][i]; b=dp[b][i];
    }
    ret=MRG(ret, sps[a][0]);
    ret=MRG(ret, sps[b][0]);
    return ret;
}

int main(){
    fastio;

    cin >> n;
    lnk.resize(n+1);
    dp.resize(n+1);
    dep.resize(n+1);
    sps.resize(n+1);

    forf(i, 0, n-1){
        ll a, b, c; cin >> a >> b >> c;
        lnk[a].pb({b, c});
        lnk[b].pb({a, c});
    }

    dfs(1, 1, 0, 0);
    sparse();

    ll q; cin >> q;
    while(q--){
        ll a, b; cin >> a >> b;
        pii ans=query(a, b);
        cout << ans[0] << " " << ans[1] << "\n";
    }

    return 0;
}
