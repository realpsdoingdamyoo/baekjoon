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

ll n;
vi lnk[252525];
pii dp[252525];

void dfs(ll pnt, ll pre){
    dp[pnt][1]=1;
    for(ll i : lnk[pnt]){
        if(i==pre) continue;
        dfs(i, pnt);

        dp[pnt][0]+=max(dp[i][0], dp[i][1]);
        dp[pnt][1]+=dp[i][0];
    }
}

void rrt(ll pnt, ll pre){
    for(ll i : lnk[pnt]){
        if(i==pre) continue;

        pii tmp=dp[pnt];
        tmp[0]-=max(dp[i][0], dp[i][1]);
        tmp[1]-=dp[i][0];

        dp[i][0]+=max(tmp[0], tmp[1]);
        dp[i][1]+=tmp[0];

        rrt(i, pnt);
    }
}

int main(){
    fastio;

    cin >> n;

    forf(i, 0, n-1){
        ll a, b; cin >> a >> b;
        lnk[a].pb(b); lnk[b].pb(a);
    }

    dfs(1, 0);
    ll ret=max(dp[1][0], dp[1][1]);

    rrt(1, 0);

    ll cnt=n;
    for(ll i=1; i<=n; i++) if(dp[i][0]==ret) cnt--;
    cout << n*(n-1)/2-cnt*(cnt-1)/2;

    return 0;
}
