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
#define cf cout.flush()

int main(){
    fastio;

    ll n; cin >> n;
    ll x=n+10;

    vi v(x), r(x), dp(x);
    vvi sm(x, vi(x));
    vvi inv(x, vi(x));


    for(ll i=1; i<=n; i++){
        cin >> v[i]; r[v[i]]=i;
    }

    for(ll j=1; j<=n; j++)
        for(ll i=1; i<=v[j]; i++)
            sm[i][j]++;

    for(ll i=1; i<=n; i++)
        for(ll j=1; j<=n; j++)
            sm[i][j]+=sm[i][j-1];

    for(ll i=n; i>=1; i--){
        for(ll j=i; j>=1; j--){
            inv[j][i]=inv[j+1][i]+sm[j][r[j]-1]-sm[i+1][r[j]-1];
        }
    }

    dp[0]=inv[1][n];
    for(ll i=1; i<=n; i++){
        dp[i]=inf;
        for(ll j=1; j<=i; j++){
            dp[i]=min(dp[i], dp[i-j]+j*(j-1)/2-inv[i-j+1][i]*2);
        }
    }

    cout << dp[n];

    return 0;
}
