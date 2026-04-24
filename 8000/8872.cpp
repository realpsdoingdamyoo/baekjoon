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

ll n, m, l;
ll dist[2][101010];
vpii lnk[101010];
bool dfsed[101010];

vpii dp;
ll best;

void dfs(ll pnt, ll pre, ll dst, ll dfill){
    dfsed[pnt]=true;
    dist[dfill][pnt]=dst;
    dp.pb({dst, pnt});
    for(pii i : lnk[pnt])
        if(i[0]!=pre)
            dfs(i[0], pnt, dst+i[1], dfill);
}

void dfs2(ll pnt, ll pre){
    if(max(dist[0][pnt], dist[1][pnt])<best) best=max(dist[0][pnt], dist[1][pnt]);
    for(pii i : lnk[pnt])
        if(i[0]!=pre)
            dfs2(i[0], pnt);
}

pii radi(ll pnt){
    best=inf;
    dp.clear();
    dfs(pnt, -1, 0, 0);
    sortv(dp);

    pnt=dp.back()[1];
    dp.clear();
    dfs(pnt, -1, 0, 0);
    sortv(dp);

    ll pnt2=dp.back()[1];
    ll l=dp.back()[0];

    dfs(pnt2, -1, 0, 1);

    dfs2(pnt, -1);

    return {best, l};
}

int main() {
    fastio;

    cin >> n >> m >> l;

    forf(i, 0, m){
        ll a, b, c; cin >> a >> b >> c;
        lnk[a].pb({b, c});
        lnk[b].pb({a, c});
    }

    vpii lengs;

    forf(i, 0, n){
        if(dfsed[i]) continue;
        lengs.pb(radi(i));
    }


    sortv(lengs);
    reverse(all(lengs));


    if(lengs.size()==1){
        cout << lengs[0][1];
    }
    else if(lengs.size()==2){
        cout << max(lengs[0][1], lengs[0][0]+lengs[1][0]+l);
    }
    else{
        cout << max(max(lengs[0][1], lengs[0][0]+lengs[1][0]+l), lengs[1][0]+lengs[2][0]+2*l);

    }

    return 0;
}
