#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef array<ll, 2> pii;
typedef vector<pii> vpii;
typedef double lf;
typedef priority_queue<ll> pql;
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define vcin; for(int i=0; i<n; i++) cin >> v[i];
#define forf(i, s, e) for(int i=s; i<e; i++)
#define forb(i, s, e) for(int i=s-1; i>=e; i--)
#define pb push_back
#define sortv(v) sort(v.begin(), v.end())
#define sortc(v, cmp) sort(v.begin(), v.end(), cmp)
#define repeat(n) for(int not_used_name=0; not_used_name<n; not_used_name++)
//const int mod=1e9+7, MOD=998244353;
const int dir4[4][2]={{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
const int dir8[8][2]={{0, 1}, {1, 0}, {-1, 0}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
const ll inf=2147483647, linf=9223372036854775807;
const double pi=acos(-1), eu=2.718281828459;
ll gcd(ll a, ll b){return b?gcd(b, a%b):a;}


typedef vector<ll> vi;

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

vi mul(const vector<vi> &v, ll l, ll r) {
    if(l == r) return v[l];

    vi x = mul(v, l, (l + r) / 2);
    vi y = mul(v, (l + r) / 2 + 1, r);

    return mtp(x, y);
}

vi golomb(int M){
    vi G;
    G.push_back(1);
    G.push_back(2);
    G.push_back(2);
    int i=2;
    while(G.size()<M){
        int rpt=G[i];
        while(rpt-- && G.size()<M){
            G.push_back(i+1);
        }
        i++;
    }
    return G;
}

int main(){
    fastio;

    int N,M; cin >> N >> M;

    if (N == 1 && M == 1){
        cout << 1;
        return 0;
    }

    vi G = golomb(M);

    vector<vi> tmp;
    for (int i = 0 ; i < M - 1 ; i++){
        tmp.push_back({1, G[i]});
    }

    vi ans = mul(tmp , 0 , M - 2);

    cout << (G[M - 1] * ans[N-1]) % mod;
}
