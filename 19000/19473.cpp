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
//const ll mod=1e9+7, MOD=998244353;
const ll dir4[4][2]={{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
const ll dir8[8][2]={{0, 1}, {1, 0}, {-1, 0}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
const ll inf=2147483647, linf=9223372036854775807;
const double pi=acos(-1), E=2.718281828459;
ll gcd(ll a, ll b){return b?gcd(b, a%b):a;}
#define cf cout.flush()

const ll w = 3;
const ll mod = 998244353;

ll sq(ll a, ll b, ll mod) {
    ll ret = 1;
    while (b) {
        if (b & 1) ret = ret * a % mod;
        b >>= 1;
        a = a * a % mod;
    }
    return ret;
}

ll R(ll x) {
    x %= mod;
    if (x < 0) x += mod;
    return x;
}

void NTT(vi &f, bool intt = false) {
    int n = f.size(), j = 0;
    vi root(n / 2);
    for (int i = 1; i < n; i++) {
        int bit = (n >> 1);
        while (j >= bit) {
            j -= bit;
            bit >>= 1;
        }
        j += bit;
        if (i < j) swap(f[i], f[j]);
    }
    ll ang = sq(w, (mod - 1) / n, mod);
    if (intt) ang = sq(ang, mod - 2, mod);
    root[0] = 1;
    for (int i = 1; i < (n >> 1); i++) root[i] = root[i - 1] * ang % mod;
    for (int i = 2; i <= n; i <<= 1) {
        int step = n / i;
        for (int j = 0; j < n; j += i) {
            for (int k = 0; k < (i >> 1); k++) {
                ll u = f[j | k], v = f[j | k | i >> 1] * root[step * k] % mod;
                f[j | k] = (u + v) % mod;
                f[j | k | i >> 1] = (u - v) % mod;
                if (f[j | k | i >> 1] < 0) f[j | k | i >> 1] += mod;
            }
        }
    }
    ll t = sq(n, mod - 2, mod);
    if (intt) for (int i = 0; i < n; i++) f[i] = f[i] * t % mod;
}

vi mtp(vi &_a, vi &_b) {
    vi a(_a.begin(), _a.end()), b(_b.begin(), _b.end());
    int n = 1;
    while (n < a.size() + b.size()) n <<= 1;
    a.resize(n); b.resize(n);
    NTT(a, false); NTT(b, false);
    for (int i = 0; i < n; i++) a[i] = a[i] * b[i] % mod;
    NTT(a, true);
    return a;
}

vi PLUS(vi a, vi b){
    if(a.size()<b.size()) swap(a, b);
    forf(i, 0, b.size()) a[i]=(a[i]+b[i])%mod;
    return a;
}

V<vi> sv;

vi dnc(vi v){
    if(v.size()==1) return v;

    ll X=0;
    while((2<<X)<v.size()) X++;

    vi v1, v2;
    forf(i, 0, 1<<X) v1.pb(v[i]);
    forf(i, 1<<X, v.size()) v2.pb(v[i]);

    vi dv1=dnc(v1), dv2=dnc(v2);

    vi ret=PLUS(dv1, mtp(dv2, sv[X]));

    return ret;
}

int main(){
    fastio;

    ll n; cin >> n;
    vi v(n); vcin;

    sv.pb({1, 1});
    forf(i, 0, 18) sv.pb(mtp(sv.back(), sv.back()));

    sortv(v);
    ll gv=1;
    forf(i, 0, n){
        v[i]=v[i]*gv%mod;
        gv=gv*2%mod;
    }
    reverse(all(v));

    vi r=dnc(v);

    forf(i, 1, n) r[i]=(r[i]+r[i-1])%mod;
    forf(i, 0, n) cout << r[i] << " ";

    return 0;
}
