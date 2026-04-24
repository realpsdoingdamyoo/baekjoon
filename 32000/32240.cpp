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

const ll MX=20000000;
ll ep[MX], ipi[MX];
unordered_map<ll, ll> mp;

void init(){
    forf(i, 1, MX) ep[i]=i;
    forf(i, 2, MX){
        if(ep[i]!=i) continue;
        forf(j, 1, MX/i+1){
            ep[j*i]=ep[j*i]*(i-1)/i;
        }
    }

    forf(i, 1, MX){
        ipi[i]=(ipi[i-1]+i*ep[i])%mod;
    }

}

ll f(ll n){
    if(n<MX) return ipi[n];
    if(mp.find(n)!=mp.end()) return mp[n];
    ll N=n%mod;
    ll ret=N*(N+1)%mod*(2*N+1)%mod*166666668%mod;

    ll i, j;
    for(i=2; i<=n; i=j+1){
        j=n/(n/i);
        ll js=(j%mod)*(j%mod+1)%mod*500000004%mod;
        ll is=(i%mod)*(i%mod+mod-1)%mod*500000004%mod;
        ll ijs=(js-is+mod)%mod;
        ret=(ret-ijs*f(n/i)%mod+mod)%mod;
    }
    return mp[n]=ret;
}


int main(){
    fastio;

    init();

    ll n; cin >> n;

    cout << (f(n)*3+mod-1)%mod;


    return 0;
}
