#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef array<ll, 2> pii;
typedef vector<pii> vpii;
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define vcin; for(int i=0; i<n; i++) cin >> v[i];
#define forf(i, s, e) for(int i=s; i<e; i++)
#define forb(i, s, e) for(int i=s-1; i>=e; i--)
#define pb push_back
#define repeat(n) for(int not_used_name=0; not_used_name<n; not_used_name++)
const int mod=1e9+7, MOD=998244353;
const int dir[4][2]={{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
const ll inf=2147483647, linf=9223372036854775807;
ll gcd(ll a, ll b){return b?gcd(b, a%b):a;}

int main(void) {
    fastio;
    ll n, m; cin >> n >> m;
    vi v(2*n); vpii d;
    repeat(m){
        ll a, b; cin >> a >> b;
        d.push_back({a, b});
    }
    forf(i, n+1, 2*n+1){
        v[i]=linf;
        forf(j, 0, m){
            v[i]=min(v[i], v[i-d[j][0]]+d[j][1]);
        }
        cout << v[i] << "\n";
    }
    return 0;
}
