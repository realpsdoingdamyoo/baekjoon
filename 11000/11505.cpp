#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define mod 1000000007
ll n, m, k, from;
ll arr[10000000];
void update(ll location, ll v) {
    ll idx = location + from - 1;
    arr[idx] = v;
    for (ll i = idx / 2; i >= 1; i /= 2) {
        arr[i] = (arr[i * 2] * arr[i * 2 + 1]) % mod;
    }
}
ll sum(ll l, ll r, ll idx = 1, ll L = 1, ll R = from) {
    if (l > R or r < L) return 1;
    else if (l <= L and r >= R) return arr[idx];
    ll m = (L + R) / 2;
    return (sum(l, r, idx * 2, L, m) * sum(l, r, idx * 2 + 1, m + 1, R)) % mod;
}
 
int main() {
    scanf("%lld %lld %lld", &n, &m, &k);
    from = ((n & (n - 1)) == 0) ? pow(2, (int)log2(n)) : pow(2, (int)log2(n) + 1);
    for (int i = 1; i < from + n; i++) arr[i] = 1;
    for (ll i = from; i < from + n; i++) cin >> arr[i];
    for (ll i = from - 1; i >= 1; --i) arr[i] = (arr[i * 2] * arr[i * 2 + 1]) % mod;
    for (ll i = 0; i < m + k; i++) {
        ll a, b, c;
        scanf("%lld %lld %lld", &a, &b, &c);
        if (a == 1) {
            update(b, c);
        }
        else {
            printf("%lld\n", sum(b, c));
        }
    }
}
