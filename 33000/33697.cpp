#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef array<ll, 2> pii;
typedef array<ll, 3> tii;
typedef vector<pii> vpii;
typedef double lf;
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
const vpii dir4={{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
const vpii dir8={{0, 1}, {1, 0}, {-1, 0}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
const ll inf=2147483647, linf=9223372036854775807;
const double pi=acos(-1), E=2.718281828459;
ll gcd(ll a, ll b){return b?gcd(b, a%b):a;}
#define cf cout.flush()

ll n, m, q;
pii u[101010], d[101010];
vi lu[101010], ld[101010];

int main(){
    fastio;

    cin >> n >> m >> q;
    while(m--){
        ll a, b; cin >> a >> b;
        a--; b--;
        lu[a].pb(b);
        ld[b].pb(a);
    }

    forf(i, 1, q+1){
        ll a, b, c; cin >> a >> b >> c; a--;
        if(b==2) d[a]={i, c};
        else u[a]={i, c};
    }

    forf(i, 0, n){
        for(ll j : lu[i]) u[j]=max(u[j], u[i]);
    }
    forb(i, n, 0){
        for(ll j : ld[i]) d[j]=max(d[j], d[i]);
    }

    forf(i, 0, n) cout << max(u[i], d[i])[1] << " ";

    return 0;
}
