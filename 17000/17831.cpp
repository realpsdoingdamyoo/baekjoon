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
const ll dir4[4][2]={{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
const ll dir8[8][2]={{0, 1}, {1, 0}, {-1, 0}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
const ll inf=2147483647, linf=9223372036854775807;
const double pi=acos(-1), E=2.718281828459;
ll gcd(ll a, ll b){return b?gcd(b, a%b):a;}
#define cf; cout.flush();

vvi lnk;
vi v;

tii dfs(ll pnt){
    tii ret={0, 0, pnt};
    V<tii> bs;
    for(ll i : lnk[pnt]) bs.pb(dfs(i));
    for(tii i : bs){
        ret[0]+=max(i[0], i[1]);
        ret[1]+=max(i[0], i[1]);
    }

    ll op=-inf;
    for(tii i : bs){
        ll dp=-max(i[0], i[1]);
        dp+=v[pnt]*v[i[2]]+i[0];
        op=max(op, dp);
    }
    ret[1]+=op;
    return ret;
}

int main(){
    fastio;

    ll n; cin >> n;
    lnk.resize(n);
    v.resize(n);
    forf(i, 1, n){ll a; cin >> a; lnk[a-1].pb(i);}
    forf(i, 0, n) cin >>v[i];

    tii rt=dfs(0);

    cout << max(rt[0], rt[1]);

    return 0;
}
