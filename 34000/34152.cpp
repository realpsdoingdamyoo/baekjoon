#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
const int mod=1e9+7, MOD=998244353, inf=2e18;

int fac[2020202]={1}, ifac[2020202];

int n;
int v[505050], o[505050];
vector<vector<int>> r;

int NHR(int N, int R) {
    if (R<0) return 0;
    return fac[N+R-1]*ifac[N-1]%MOD*ifac[R]%MOD;
}


const int w = 3;

int sq(int a, int b) {
    int ret = 1;
    while (b) {
        if (b & 1) ret = ret * a % MOD;
        b >>= 1;
        a = a * a % MOD;
    }
    return ret;
}

int R(int x) {
    x %= MOD;
    if (x < 0) x += MOD;
    return x;
}

void NTT(vector<int> &f, bool intt = false) {
    int N = f.size(), j = 0;
    vector<int> root(N / 2);
    for (int i = 1; i < N; i++) {
        int bit = (N >> 1);
        while (j >= bit) {
            j -= bit;
            bit >>= 1;
        }
        j += bit;
        if (i < j) swap(f[i], f[j]);
    }
    int ang = sq(w, (MOD - 1) / N);
    if (intt) ang = sq(ang, MOD - 2);
    root[0] = 1;
    for (int i = 1; i < (N >> 1); i++) root[i] = root[i - 1] * ang % MOD;
    for (int i = 2; i <= N; i <<= 1) {
        int step = N / i;
        for (int j = 0; j < N; j += i) {
            for (int k = 0; k < (i >> 1); k++) {
                int u = f[j | k], v = f[j | k | i >> 1] * root[step * k] % MOD;
                f[j | k] = (u + v) % MOD;
                f[j | k | i >> 1] = (u - v) % MOD;
                if (f[j | k | i >> 1] < 0) f[j | k | i >> 1] += MOD;
            }
        }
    }
    int t = sq(N, MOD - 2);
    if (intt) for (int i = 0; i < N; i++) f[i] = f[i] * t % MOD;
}

vector<int> mtp(vector<int> &_a, vector<int> &_b) {
    vector<int> a(_a.begin(), _a.end()), b(_b.begin(), _b.end());
    int n = 1;
    while (n < a.size() + b.size()) n <<= 1;
    a.resize(n); b.resize(n);
    NTT(a, false); NTT(b, false);
    for (int i = 0; i < n; i++) a[i] = a[i] * b[i] % MOD;
    NTT(a, true);
    return a;
}

signed main() {
    fastio;

    for (int i=1; i<=20010; i++) fac[i]=fac[i-1]*i%MOD;
    ifac[20010]=478569465; for (int i=20009; i>=0; i--) ifac[i]=ifac[i+1]*(i+1)%MOD;

    cin >> n;
    for (int i=1; i<=n; i++) cin >> v[i];
    for (int i=1; i<=n; i++) if (o[i]==0) {
        int x=i, c=0; while (!o[x]++) c++, x=v[x];
        if (c==1) r.push_back({1, MOD-1});
        else {
            r.push_back({});
            for (int j=0; j<=c; j++) {
                int a=(2*NHR(j+1, 2*c-2*j)-NHR(j+1, 2*c-2*j-1))*(j%2?-1:1);
                r.back().push_back((a%MOD+MOD)%MOD);
            }
        }
    }

    for (int i=0; i<r.size()-1; i+=2) r.push_back(mtp(r[i], r[i+1]));

    int ans=0;
    for (int i=0; i<=n; i++) ans=(ans+r.back()[i]*fac[n-i])%MOD;
    cout << ans;

    return 0;
}
