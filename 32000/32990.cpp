#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ;                                 \
    ios_base::sync_with_stdio(false); \
    cin.tie(0), cout.tie(0);
#define forf(i, s, e) for (ll i = s; i < e; i++)
#define forb(i, s, e) for (ll i = e - 1; i >= s; i--)
typedef long long int ll;
typedef vector<ll> vi;
typedef array<ll, 2> pii;
#define pb push_back

int main() {
    fastio;

    ll n;
    cin >> n;
    ll m = n * n / 4;
    cout << m << "\n";
    if (m > 1000000)
        return 0;
    forf(i, 1, n) {
        forf(j, 0, min(i, n - i)) {
            vector<pii> v;
            for (ll k = 0; i * k + i + j + 1 <= n; k++) {
                v.pb({i * k + j + 1, i * k + i + j + 1});
            }
            cout << v.size() << " ";
            for (pii p : v)
                cout << p[0] << " " << p[1] << " ";
            cout << "\n";
        }
    }

    return 0;
}
