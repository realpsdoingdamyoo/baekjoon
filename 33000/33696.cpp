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
const vpii dir4={{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
const vpii dir8={{0, 1}, {1, 0}, {-1, 0}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
const ll inf=2147483647, linf=9223372036854775807;
const double pi=acos(-1), E=2.718281828459;
ll gcd(ll a, ll b){return b?gcd(b, a%b):a;}
#define cf cout.flush()

ll dp1[5005]={1};
ll dp2[5005]={1};

ll mpw(ll n, ll r){
    ll ret=1;
    while(r){
        if(r&1) ret=ret*n%mod;
        n=n*n%mod; r>>=1;
    }
    return ret;
}

ll inv(ll n){
    return mpw(n, mod-2);
}

int main(){
    fastio;

    forf(i, 1, 5005){
        dp1[i]=dp1[i-1]*((i*3-2)*(i*3-1)*(i*3)%mod)%mod;
        dp1[i]=dp1[i]*inv(i*i*i%mod)%mod;
        dp2[i]=dp1[i];
    }

    forf(i, 1, 5005){
        forf(j, 1, i) dp2[i]=(dp2[i]-dp2[j]*dp1[i-j]%mod+mod)%mod;
    }

    ll n; cin >> n;
    cout << dp2[n];

    return 0;
}
