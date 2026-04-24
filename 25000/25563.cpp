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

ll qand(ll n, vi v, ll k){

    vi dp(1<<20);
    forf(i, 0, n) dp[v[i]]++;
    forf(i, 0, 20){
        forf(j, 0, 1<<20){
            if(j&(1<<i)) continue;
            dp[j|(1<<i)]+=dp[j];
        }
    }
    forf(i, 0, 1<<20) dp[i]=dp[i]*(dp[i]-1)/2;

    ll kc=0, K=k, ret=0;
    while(K){K=K&(K-1); kc++;}

    forf(i, 0, k+1){
        if(((i|k)^k)) continue;
        ll c=0, I=i;
        while(I){I=I&(I-1); c++;}
        if(kc-c&1) ret-=dp[i];
        else ret+=dp[i];

    }
    return ret;
}

ll qxor(ll n, vi v, ll k){
    vi cnt(1<<20); ll ret=0;
    forf(i, 0, n) cnt[v[i]]++;
    if(k==0){
        forf(i, 0, 1<<20) ret+=cnt[i]*(cnt[i]-1)/2;
        return ret;
    }


    forf(i, 0, 1<<20) ret+=cnt[i]*cnt[i^k];
    return ret/2;
}

int main(){
    fastio;

    ll n, k, X=(1<<20)-1; cin >> n >> k;
    vi v(n); vcin;
    ll o=qand(n, v, k);
    ll x=qxor(n, v, k);

    forf(i, 0, n){
        v[i]=X^v[i];
    } k=X^k;
    ll a=qand(n, v, k);

    cout << a << " " << o << " " << x << "\n";


    return 0;
}
