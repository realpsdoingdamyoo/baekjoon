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

ll n, m;
vpii e;
vvi v;

ll inv(ll a){
    ll r=1, x=mod-2;
    while(x){
        if(x&1) r=r*a%mod;
        a=a*a%mod; x>>=1;
    }
    return r;
}

ll solve(){
    forf(i, 0, n) forf(j, 0, n) v[i][j]=0;


    forf(i, 0, m){
        ll a=e[i][0], b=e[i][1];
        ll r=(1LL*rand()*rand()*rand()+477+rand()+rand()*28394)%mod;
        v[a][b]=r;
        v[b][a]=mod-r;
    }

    forf(i, 0, n){
        forf(j, i, n){
            if(v[j][i]) swap(v[i], v[j]);
        }
        if(v[i][i]==0){
            return 0;
        }

        forf(j, i+1, n){
            ll x=inv(v[i][i])*v[j][i]%mod;
            forf(k, i, n){
                v[j][k]=(v[j][k]-x*v[i][k]%mod+mod)%mod;
            }
        }
    }

    return 1;
}

int main(){
    fastio;

    srand(42);
    cin >> n >> m;
    v.resize(n);
    forf(i, 0, n) v[i].resize(n);

    forf(i, 0, m){
        ll a, b; cin >> a >> b;
        e.pb({a-1, b-1});
    }

    cout << max(solve(), max(solve(), solve()));



    return 0;
}
