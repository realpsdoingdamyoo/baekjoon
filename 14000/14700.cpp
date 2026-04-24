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

ll n, m;
int dp[300][1<<18];
ll _p;

int main(){
    fastio;

    cin >> n >> m;
    if(n<m) swap(n, m); _p=1<<m;
    dp[0][0]=dp[0][1]=1;
    forf(i, 1, n*m){
        forf(j, 0, 1<<m+1){
            if(i%m==0) dp[i][j]=dp[i-1][(j>>1)+_p]+dp[i-1][j>>1];
            else if((j&_p) && (j&2) && (j&1)) dp[i][j]=dp[i-1][j>>1];
            else dp[i][j]=dp[i][j]=dp[i-1][(j>>1)+_p]+dp[i-1][j>>1];
            dp[i][j]%=mod;
        }
    }

    ll ret=0;
    forf(i, 0, 1<<m+1) ret+=dp[n*m-1][i];
    cout << ret%mod;

    return 0;
}
