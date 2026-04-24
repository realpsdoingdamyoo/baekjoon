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

int main(){
    fastio;

    ll n, m; cin >> n >> m;
    V<vpii> lnk(n);
    V<bool> cg(n);
    vi dst(n);
    forf(i, 0, n){
        ll a; cin >> a;
        cg[i]=a;
    }
    cg[n-1]=false;

    forf(i, 0, m){
        ll a, b, c; cin >> a >> b >> c;
        if(cg[a] || cg[b]) continue;
        lnk[a].pb({b, c});
        lnk[b].pb({a, c});
    }

    forf(i, 1, n) dst[i]=inf*910191;

    PQ<pii> pq; pq.push({0, 0});

    while(pq.size()){
        ll pd=-pq.top()[0];
        ll pn=pq.top()[1];
        pq.pop();

        if(dst[pn]<pd) continue;

        for(pii i : lnk[pn]){
            ll nn=i[0];
            ll nd=pd+i[1];
            if(nd<dst[nn]){
                dst[nn]=nd;
                pq.push({-nd, nn});
            }
        }
    }

    cout << (dst[n-1]>910190*inf?-1:dst[n-1]);


    return 0;
}
