#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef array<ll, 2> pii;
typedef vector<pii> vpii;
typedef double lf;
typedef priority_queue<ll> pqi;
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define vcin; for(int i=0; i<n; i++) cin >> v[i];
#define forf(i, s, e) for(ll i=s; i<e; i++)
#define forb(i, s, e) for(ll i=s-1; i>=e; i--)
#define pb push_back
#define sortv(v) sort(v.begin(), v.end())
#define sortc(v, cmp) sort(v.begin(), v.end(), cmp)
#define repeat(n) for(ll not_used_name=0; not_used_name<n; not_used_name++)
#define all(v) v.begin(), v.end()
const int mod=1e9+7, MOD=998244353;
const int dir4[4][2]={{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
const int dir8[8][2]={{0, 1}, {1, 0}, {-1, 0}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
const ll inf=2147483647, linf=9223372036854775807;
const double pi=acos(-1), eu=2.718281828459;
ll gcd(ll a, ll b){return b?gcd(b, a%b):a;}

string s = "$";
vi A(4000005);

int main()
{
    fastio;
    string tmp; cin >> tmp;
    for (char c : tmp){s.pb(c); s.pb('$');}

    ll m = -1, k = -1;

    ll ans = 0;
    forf(i, 0, s.size()){
        if (i <= m) A[i] = min(m - i, A[2 * k - i]);
        while (0 <= i - A[i] - 1 && i + A[i] + 1 < s.size() && s[i - A[i] - 1] == s[i + A[i] + 1]){
            if (i + ++A[i] > m) m = i + A[i], k = i;
        }
        ans += (A[i] + 1) / 2;
    }
    cout << ans;
}
