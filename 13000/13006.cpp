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

ll n, c;
vi v;
vi cst;

ll pri(ll bit){
    ll ret=0, cnt=0;
    forf(i, 0, n) if(bit&(1<<i)){
        ret+=v[i]; cnt++;
    }
    ll R=(ret/c)*cst[c];
    if(cnt-ret/c) R+=cst[ret%c]+cst[0]*(cnt-ret/c-1);
    return R;
}

int main(){
    fastio;

    cin >> n >> c;
    ll dp[1<<15]={};
    v.resize(n); vcin;
    cst.resize(c+1);
    forf(i, 0, c+1) cin >> cst[i];

    forf(i, 1, 1<<n){
        dp[i]=pri(i);
        for(ll j=(i-1)&i; j; j=(j-1)&i){
            dp[i]=max(dp[i], dp[j]+dp[i^j]);
        }
    }

    cout << dp[(1<<n)-1];

    return 0;
}
