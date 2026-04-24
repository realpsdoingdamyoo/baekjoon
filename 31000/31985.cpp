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

ll fac[2000008]={1};
ll rfac[2000008];

ll rvs(ll N){
    ll r=1, x=mod-2;
    while(x){
        if(x&1) r=r*N%mod;
        N=N*N%mod; x>>=1;
    }
    return r;
}

ll ncr(ll N, ll r){
    return fac[N]*rfac[N-r]%mod*rfac[r]%mod;
}

vpii obs;
ll n, m, k;

ll ways(ll sx, ll sy, ll ex, ll ey){
    ll ret=ncr(ex+ey-sx-sy, ex-sx);

    vi dp(k);
    forf(i, 0, k){
        pii& o=obs[i];
        if(o[0]<sx || o[0]>ex || o[1]<sy || o[1]>ey) continue;

        dp[i]=ncr(o[0]+o[1]-sx-sy, o[0]-sx);

        forf(j, 0, i){
            pii& O=obs[j];
            if(O[0]<sx || O[0]>ex || O[1]<sy || O[1]>ey) continue;
            if(O[0]>o[0] || O[1]>o[1]) continue;

            dp[i]=(dp[i]+mod-dp[j]*ncr(o[0]+o[1]-O[0]-O[1], o[0]-O[0])%mod)%mod;
        }
        ret=(ret+mod-dp[i]*ncr(ex+ey-o[0]-o[1], ex-o[0])%mod)%mod;
    }

    //cout << sx << " " << sy << " " << ex << " " << ey << " " << ret << "\n";

    return ret;
}

bool cmp(pii a, pii b){
    return a[0]+a[1]<b[0]+b[1];
}

int main(){
    fastio;

    forf(i, 1, 2000008) fac[i]=fac[i-1]*i%mod;
    forf(i, 0, 2000008) rfac[i]=rvs(fac[i]);

    cin >> n >> m >> k;
    obs.resize(k);
    forf(i, 0, k) cin >> obs[i][0] >> obs[i][1];
    forf(i, 0, 2*k) obs[i/2][i%2]--;
    sortc(obs, cmp);

    ll rou1=ways(0, 1, n-2, m-1)*ways(1, 0, n-1, m-2)%mod;
    ll rou2=ways(1, 0, n-2, m-1)*ways(0, 1, n-1, m-2)%mod;
    cout << (rou1-rou2+mod)%mod;



    return 0;
}
