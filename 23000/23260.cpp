#include "bits/stdc++.h"
#define all(x) ((x).begin()), ((x).end())

using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;
ll factorial[1010101], inverse[1010101];
ll  mu[1010101];
bool isPrime[1010101];
vector<ll> prime;

ll fpow(ll a, ll m) {
    if (m == 0) return 1ll;
    ll next = fpow(a, m / 2);
    next = next * next % mod;
    if (m % 2) return next * a % mod;
    else return next;
}

ll nCr(int n, int k) { 
    if(n < k) return 0;
    return (factorial[n] * inverse[n - k] % mod) * inverse[k] % mod; 
}

void init(){
    factorial[0] = 1;
    for (int i = 1; i <= 1000000ll; i++) factorial[i] = factorial[i - 1] * i % mod;
    inverse[1000000] = fpow(factorial[1000000], mod - 2);
    for (int i = 999999; i >= 0; i--) inverse[i] = inverse[i + 1] * (i + 1) % mod;
    fill(isPrime, isPrime+1000000+1, true);
    fill(mu, mu+1000000+1, -1);
    mu[1] = 1;
    for(ll i=2;i<=1000000ll;i++)
    {
        if(isPrime[i]) prime.push_back(i);
        for(ll& p : prime) {
            if(i*p > 1000000ll) break;
            isPrime[i*p] = false;
            if(i%p == 0) {
                mu[i*p] = 0;
                break;
            }
            mu[i*p] = mu[i]*mu[p];
        }
    }
}
 
int main(){
    ios::sync_with_stdio(0);cin.tie(0);

    init();
    ll N, K; cin >> N >> K;
    vector<int> cnt(1010101);
    for(int i=1; i<=N; i++) {
        ll x; cin >> x;
        cnt[x]++;
    }
    ll ans = 0;
    for(int i=1; i<=1000000ll; i++){
        ll c = 0;
        for(int j=i; j<=1000000ll; j+=i) c += cnt[j];
        ll t = mu[i] * nCr(c, K) % mod;
        ans = (ans + t) % mod;
        ans = (ans + mod) % mod;
        assert(ans >= 0);
    }
    cout << ans << endl;
}
