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

    const ll X=1000005;
    ll n; cin >> n;
    vi dp(X), v(n);

    forf(i, 0, n){
        cin >> v[i];

        for(ll j=1; j*j<=v[i]; j++){
            if(v[i]%j) continue;
            dp[j]++; dp[v[i]/j]++;
            if(j*j==v[i]) dp[j]--;
        }
    }

    forf(i, 0, X) dp[i]=dp[i]*(dp[i]-1)*(dp[i]-2)/6;

    forb(i, X, 1){
        for(ll j=i*2; j<X; j+=i)
            dp[i]-=dp[j];
    }
    cout << dp[1];


    return 0;
}
