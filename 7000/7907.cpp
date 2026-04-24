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
const double PI=acos(-1), E=2.718281828459;
ll gcd(ll a, ll b){return b?gcd(b, a%b):a;}

ll n, m, k;
vpii v, u; vi c;
vpii ord;

void Sort(ll t){
    vi C=c, s;
    s.pb(0);

    ll cnt=1;
    while(s.size()){
        ll p=s.back(); s.pop_back();
        ord[p][t]=cnt++;

        if(u[p][t]>=0) if(--C[u[p][t]]==0) s.pb(u[p][t]);
        if(u[p][t^1]>=0) if(--C[u[p][t^1]]==0) s.pb(u[p][t^1]);
    }
}

int main(){
    fastio;

    cin >> n >> m >> k;
    v.resize(n); u.resize(n); c.resize(n); ord.resize(n);
    forf(i, 0, n) cin >> v[i][0] >> v[i][1];
    forf(i, 0, n) v[i][1]=mod-v[i][1], u[i]={-1, -1};
    forf(i, 0, m){
        ll a, b; cin >> a >> b; a--; b--;
        if(v[a][0]+v[a][1]>v[b][0]+v[b][1]) swap(a, b);
        if(v[a][0]==v[b][0]) u[a][0]=b;
        else u[a][1]=b;
        c[b]++;
    }

    Sort(0); Sort(1);

    while(k--){
        ll a, b; cin >> a >> b; a--; b--;
        cout << ((ord[a][0]<ord[b][0])^(ord[a][1]<ord[b][1])?"NIE\n":"TAK\n");
    }

    return 0;
}
