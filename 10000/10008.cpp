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
const ll mod=1e9+7, MOD=998244353;
const ll dir4[4][2]={{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
const ll dir8[8][2]={{0, 1}, {1, 0}, {-1, 0}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
const ll inf=2147483647, linf=9223372036854775807;
const double pi=acos(-1), E=2.718281828459;
ll gcd(ll a, ll b){return b?gcd(b, a%b):a;}


ll n;
vi num;
vvi lnk;
vi centout;
vi stsize;
ll ans;
string st;

ll stset(ll pnt, ll pre){
    ll stsz=1;
    for(ll i : lnk[pnt]){
        if(i!=pre && !centout[i])
            stsz+=stset(i, pnt);
    }
    stsize[pnt]=stsz;
    return stsz;
}

ll centfind(ll pnt, ll pre, ll subsize){
    for(ll i : lnk[pnt]){
        if(i!=pre && !centout[i] && stsize[i]>subsize/2)
            return centfind(i, pnt, subsize);
    }
    return pnt;
}


ll dfs(ll pnt, ll pre){
    ll ret=0;
    for(ll i : lnk[pnt])
        if(i!=pre && !centout[i])
            ret+=dfs(i, pnt);
    return ret+1;
}


/*
typedef complex<double> cpx;
void fft(vector<cpx> &a, bool inv){
    int n = a.size(), j = 0;
    vector<cpx> roots(n/2);
    for(int i=1; i<n; i++){
        int bit = (n >> 1);
        while(j >= bit) j -= bit, bit >>= 1;
        j += bit;
        if(i < j) swap(a[i], a[j]);
    }
    double ang = 2 * acos(-1) / n * (inv ? -1 : 1);
    for(int i=0; i<n/2; i++) roots[i] = cpx(cos(ang * i), sin(ang * i));
    for(int i=2; i<=n; i<<=1){
        int step = n / i;
        for(int j=0; j<n; j+=i) for(int k=0; k<i/2; k++){
            cpx u = a[j+k], v = a[j+k+i/2] * roots[step * k];
            a[j+k] = u+v; a[j+k+i/2] = u-v;
        }
    }
    if(inv) for(int i=0; i<n; i++) a[i] /= n;
}
vector<ll> mul(vector<ll> &v, vector<ll> &w){
    forf(i, 0, v.size()) v[i]=!!v[i];
    forf(i, 0, w.size()) w[i]=!!w[i];
    vector<cpx> fv(v.begin(), v.end()), fw(w.begin(), w.end());
    int n = 2; while(n < v.size() + w.size()) n <<= 1;
    fv.resize(n); fw.resize(n);
    fft(fv, 0); fft(fw, 0);
    for(int i=0; i<n; i++) fv[i] *= fw[i];
    fft(fv, 1);
    vector<ll> ret(n);
    for(int i=0; i<n; i++) ret[i] = (ll)round(fv[i].real());
    return ret;
}
*/




using cpx = complex<double>;
const double PI = acos(-1);
vector<cpx> roots = {{0, 0},
                     {1, 0}};
void ensure_capacity(int min_capacity) {
    for (int len = roots.size(); len < min_capacity; len *= 2) {
        for (int i = len >> 1; i < len; i++) {
            roots.emplace_back(roots[i]);
            double angle = 2 * PI * (2 * i + 1 - len) / (len * 2);
            roots.emplace_back(cos(angle), sin(angle));
        }
    }
}

void fft(vector<cpx> &z, bool inverse) {
    int n = z.size();
    assert((n & (n - 1)) == 0);
    ensure_capacity(n);
    for (unsigned i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j >= bit; bit >>= 1)
            j -= bit;
        j += bit;
        if (i < j)
            swap(z[i], z[j]);
    }
    for (int len = 1; len < n; len <<= 1) {
        for (int i = 0; i < n; i += len * 2) {
            for (int j = 0; j < len; j++) {
                cpx root = inverse ? conj(roots[j + len]) : roots[j + len];
                cpx u = z[i + j];
                cpx v = z[i + j + len] * root;
                z[i + j] = u + v;
                z[i + j + len] = u - v;
            }
        }
    }
    if (inverse)
        for (int i = 0; i < n; i++)
            z[i] /= n;
}

vector<ll> mul(vector<ll> &a, vector<ll> &b, ll m) {
    forf(i, 0, a.size()) a[i]=!!a[i];
    forf(i, 0, b.size()) b[i]=!!b[i];
    ll need = a.size() + b.size() - 1;
    ll n = 1;
    while (n < need) n <<= 1;
    vector<cpx> A(n);
    for (size_t i = 0; i < a.size(); i++) {
        ll x = (a[i] % m + m) % m;
        A[i] = cpx(x & ((1 << 15) - 1), x >> 15);
    }
    fft(A, false);

    vector<cpx> B(n);
    for (size_t i = 0; i < b.size(); i++) {
        ll x = (b[i] % m + m) % m;
        B[i] = cpx(x & ((1 << 15) - 1), x >> 15);
    }
    fft(B, false);

    vector<cpx> fa(n);
    vector<cpx> fb(n);
    for (ll i = 0, j = 0; i < n; i++, j = n - i) {
        cpx a1 = (A[i] + conj(A[j])) * cpx(0.5, 0);
        cpx a2 = (A[i] - conj(A[j])) * cpx(0, -0.5);
        cpx b1 = (B[i] + conj(B[j])) * cpx(0.5, 0);
        cpx b2 = (B[i] - conj(B[j])) * cpx(0, -0.5);
        fa[i] = a1 * b1 + a2 * b2 * cpx(0, 1);
        fb[i] = a1 * b2 + a2 * b1;
    }

    fft(fa, true);
    fft(fb, true);
    vector<ll> res(need);
    for (ll i = 0; i < need; i++) {
        long long aa = (long long) (fa[i].real() + 0.5);
        long long bb = (long long) (fb[i].real() + 0.5);
        long long cc = (long long) (fa[i].imag() + 0.5);
        res[i] = (aa % m + (bb % m << 15) + (cc % m << 30)) % m;
    }
    return res;
}










ll bagprob(vi& bag, ll n){
    vvi v;
    for(ll i : bag){
        vi onev(i+1);
        onev[0]=onev[i]=1;
        v.pb(onev);
    }
    ll x=0;
    while(x<v.size()-1){
        v.pb(mul(v[x], v[x+1], 998244353));
        x+=2;
    }
    vi u=v[v.size()-1];
    while(u[u.size()-1]==0) u.pop_back();
    ll mx=0;
    forf(i, 0, n) if(u[i]) mx=max(mx, i*(n-i-1));
    return mx;
}

ll sum_=0;
ll dfs2(ll pnt, ll pre){
    ll ret=1;
    for(ll i : lnk[pnt])
        if(i!=pre && !centout[i])
            ret+=dfs2(i, pnt);
    sum_+=ret;
    return ret;
}

ll centpick_(ll pnt){
    ll ret=0;
    vi bag;
    for(ll i : lnk[pnt]){
        if(centout[i]) continue;
        sum_=0;
        bag.pb(dfs(i, pnt));
        dfs2(i, pnt);
        ret+=sum_;
    }
    ret+=bagprob(bag, n);

    return ret;
}

ll decomp(ll pnt, ll par){
    ll best_path=inf;
    ll subsize=stset(pnt, n);
    ll cent=centfind(pnt, n, subsize);
    ll ret=0;
    ret+=centpick_(cent);
    centout[cent]=1;
    return ret;
}

int main(){
    fastio;
    cin >> n;
    if(n==1){cout << "0 0"; return 0;}
    num.resize(n); lnk.resize(n);
    centout.resize(n); stsize.resize(n);


    forf(i, 0, n-1){
        ll a, b; cin >> a >> b;
        lnk[a-1].pb(b-1);
        lnk[b-1].pb(a-1);
    }
    cout << n-1 << " " << decomp(0, n);

    return 0;
}
