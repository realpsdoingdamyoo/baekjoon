/*******************************
** coded by realpsdoingdamyoo **
*******************************/

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


ll n; vvi v(n);
vi dp(1<<20);
ll dpf(ll x){
    if(dp[x]|| x==0) return dp[x];

    ll j=0;
    forf(i, 0, n) j+=!!(x&(1<<i));

    dp[x]=linf;
    forf(i, 0, n){
        if(x&(1<<i)) dp[x]=min(dp[x], dpf(x-(1<<i))+v[j-1][i]);
    }
    if(dp[x]==linf) dp[x]=0;
    return dp[x];
}

int main() {
    fastio;

    cin >> n; v.resize(n);
    forf(i, 0, n){
        v[i].resize(n);
        forf(j, 0, n) cin >> v[i][j];
    }

    cout << dpf((1<<n)-1) <<"\n";

    return 0;
}
