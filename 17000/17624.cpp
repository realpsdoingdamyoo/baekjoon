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

ll n, b;
vvi lnk;
V<bool> black;
vpii res;

vpii X(vpii v, vpii u){
    vpii ret(v.size()+u.size()-1);
    forf(i, 1, ret.size()) ret[i]={inf, -1};

    forf(i, 1, v.size()){
        forf(j, 0, u.size()){
            ret[i+j][0]=min(ret[i+j][0], v[i][0]+u[j][0]);
            ret[i+j][1]=max(ret[i+j][1], v[i][1]+u[j][1]);
        }
    }
    return ret;
}

vpii dfs(ll pnt, ll pre){
    vpii ret;
    ret.pb({0, 0});
    ret.pb({black[pnt], black[pnt]});

    for(ll i : lnk[pnt])
        if(i!=pre) ret=X(ret, dfs(i, pnt));
    forf(i, 0, ret.size()){
        res[i][0]=min(res[i][0], ret[i][0]);
        res[i][1]=max(res[i][1], ret[i][1]);
    }


    return ret;
}

int main(){
    fastio;

    cin >> n;
    lnk.resize(n);
    black.resize(n);
    res.resize(n+1);
    forf(i, 0, n+1) res[i]={inf, -1};

    cin >> b;
    while(b--){
        ll a; cin >> a;
        black[a-1]=true;
    }
    forf(i, 1, n){
        ll x, y; cin >> x >> y;
        lnk[x-1].pb(y-1);
        lnk[y-1].pb(x-1);
    }

    dfs(0, -1);


    ll q, cnt=0;
    cin >> q;

    while(q--){
        ll a, b; cin >> a >> b;
        cnt+=(res[a][0]<=b && b<=res[a][1]);
    }
    cout << cnt << "\n";


    return 0;
}
