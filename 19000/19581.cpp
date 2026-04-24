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

ll n;
V<V<pii>> lnk;
V<bool> vsd;
ll mxdist, mxp;
ll ban;


void dfs(ll pnt, ll dist){
    if(vsd[pnt] || pnt==ban) return;
    if(dist>mxdist){
        mxdist=dist;
        mxp=pnt;
    }
    vsd[pnt]=1;
    for(auto nxt : lnk[pnt]){
        if(!vsd[nxt[0]]) dfs(nxt[0], dist+nxt[1]);
    }

}

int main(){
    fastio;
    ll n; cin >> n;
    lnk.resize(n+1); vsd.resize(n+1);
    forf(i, 0, n-1){
        ll a, b, c; cin >> a >> b >> c;
        lnk[a].pb({b, c});
        lnk[b].pb({a, c});
    }
    dfs(1, 0);
    ll mxp1=mxp;
    forf(i, 0, n+1) vsd[i]=0;
    mxdist=0;

    dfs(mxp, 0);
    ll mxp2=mxp;

    ll sr=0;



    ll f=1;
    while(f==mxp1 || f==mxp2) f++;

    ban=mxp1;
    forf(i, 0, n+1) vsd[i]=0;
    mxdist=0;
    dfs(f, 0);
    forf(i, 0, n+1) vsd[i]=0;
    mxdist=0;
    dfs(mxp, 0);
    sr=max(sr, mxdist);


    ban=mxp2;
    forf(i, 0, n+1) vsd[i]=0;
    mxdist=0;
    dfs(f, 0);
    forf(i, 0, n+1) vsd[i]=0;
    mxdist=0;
    dfs(mxp, 0);
    sr=max(sr, mxdist);

    cout << sr;


    return 0;
}
