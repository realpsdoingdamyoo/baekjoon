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

ll t, n, d;

struct mat{
    ll s;
    vvi v;
};

mat F(ll s, bool I){
    mat ret;
    ret.s=s;
    ret.v.resize(s);
    forf(i, 0, s) ret.v[i].resize(s);
    if(I){forf(i, 0, s) ret.v[i][i]=1;}
    return ret;
}

mat mk(V<tii> g){
    mat ret=F(n, false);
    for(tii p : g) ret.v[p[0]-1][p[1]-1]=p[2];
    return ret;
}

mat mul(mat a, mat b){
    mat ret=F(n, false);
    forf(i, 0, n){
        forf(j, 0, n){
            forf(k, 0, n){
                ret.v[i][j]+=a.v[i][k]*b.v[k][j]%mod;
            }
            ret.v[i][j]%=mod;
        }
    }
    return ret;
}

int main(){
    fastio;
    cin >> t >> n >> d;
    V<mat> mt;

    forf(i, 0, t){
        ll c; cin >> c;
        V<tii> g(c);
        forf(i, 0, c*3) cin >> g[i/3][i%3];
        mt.pb(mk(g));
    }

    mat ret=F(n, true);

    forf(i, 0, t) ret=mul(ret, mt[i]);
    ll x=d/t;


    mat p=F(n, true);
    while(x){
        if(x&1) p=mul(p, ret);
        ret=mul(ret, ret); x>>=1;
    }

    forf(i, 0, d%t) p=mul(p, mt[i]);

    forf(i, 0, n){
        forf(j, 0, n) cout << p.v[i][j] << " ";
        cout << "\n";
    }

    return 0;
}
