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


const int MAX = 200005;
const ll MOD1 = 1e9+9;
const ll MOD2 = 1e8+7;
const ll BASE = 31;

ll p1 = 1, p2 = 1;
int nd[26], hs[26];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string N, H;
    cin >> N >> H;

    if (N.size() > H.size()) {
        cout << 0;
        return 0;
    }

    for (int i = 1; i < N.size(); i++) {
        p1 = p1*BASE%MOD1;
        p2 = p2*BASE%MOD2;
    }

    for (char c : N) {
        nd[c-'a']++;
    }

    ll h1 = 0, h2 = 0;
    ll ans = 0;
    unordered_set<ll> us;
    for (int i = 0; i <= H.size()-N.size(); i++) {
        if (i == 0) {
            for (int j = 0; j < N.size(); j++) {
                h1 = (h1*BASE+H[j])%MOD1;
                h2 = (h2*BASE+H[j])%MOD2;
                hs[H[j]-'a']++;
            }
        }
        else {
            h1 = h1-p1*H[i-1]%MOD1+MOD1;
            h2 = h2-p2*H[i-1]%MOD2+MOD2;
            hs[H[i-1]-'a']--;
            h1 = (h1*BASE+H[i-1+N.size()])%MOD1;
            h2 = (h2*BASE+H[i-1+N.size()])%MOD2;
            hs[H[i-1+N.size()]-'a']++;
        }

        bool chk = true;
        for (int j = 0; j < 26; j++) {
            if (nd[j] != hs[j]) {
                chk = false;
                break;
            }
        }
        ll key = (h1<<32)|h2;
        if (chk && us.find(key) == us.end()) {
            // cout << i << ' ' << h1 << ' ' << h2 << ' ' << key <<'\n';
            us.insert(key);
            ans++;
        }
    }

    cout << ans;

    return 0;
}
