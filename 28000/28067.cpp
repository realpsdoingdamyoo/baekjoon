#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef array<ll, 2> pii;
typedef array<ll, 3> tii;
typedef vector<pii> vpii;
typedef double lf;
typedef priority_queue<ll> pqi;
#define V vector
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
const double PI=acos(-1), EU=2.718281828459;
ll gcd(ll a, ll b){return b?gcd(b, a%b):a;}


V<pii> v;

ll dis(pii a, pii b){
    return (a[0]-b[0])*(a[0]-b[0])+(a[1]-b[1])*(a[1]-b[1]);
}


int main() {
    fastio;

    ll n, m, s=0; cin >> n >> m;
    V<tii> v(0);
    n++; m++;
    ll sz=n*m;
    forf(i, 0, sz){
        forf(j, i+1, sz){
            forf(k, j+1, sz){
                vi x; tii p;
                x.pb(dis({i/n, i%n}, {j/n, j%n}));
                x.pb(dis({j/n, j%n}, {k/n, k%n}));
                x.pb(dis({k/n, k%n}, {i/n, i%n}));
                sortv(x);
                if(sqrt(x[2])+0.0001>=sqrt(x[1])+sqrt(x[0])) continue;
                forf(i, 0, 3) p[i]=x[i];
                v.pb(p);
            }
        }
    }

    sortv(v);
    v.pb({0, 0, 0});
    forf(i, 0, v.size()-1){
        s+=(v[i]!=v[i+1]);
    }

    cout << s;

    return 0;
}
