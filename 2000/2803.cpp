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

int main(){
    fastio;

    ll n, m; cin >> n >> m;
    vi sos(1<<m);

    forf(i, 0, n){
        ll a, r=0; cin >> a;
        forf(j, 0, a){
            ll b; cin >> b;
            r|=1<<b-1;
        }
        sos[r]++;
    }

    forf(i, 0, m){
        forf(j, 0, 1<<m){
            if(j&(1<<i)) continue;
            sos[j|(1<<i)]+=sos[j];
        }
    }

    vi pwr(n+1); pwr[0]=1;
    forf(i, 1, n+1) pwr[i]=pwr[i-1]*2%mod;

    forf(i, 0, 1<<m) sos[i]=pwr[sos[i]];
    ll ret=0;
    forf(i, 0, 1<<m){
        ll c=0, I=i;
        while(I){I=I&(I-1); c++;}
        ret+=(1-(m-c&1)*2)*sos[i];
    }
    cout << (ret+mod*1234567)%mod;

    return 0;
}
