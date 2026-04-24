#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;/*
typedef array<ll, 2> pii;
typedef array<ll, 3> tii;
typedef vector<pii> vpii;*/
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

const ll X=18;
ll n;
vi lnk[101010];
ll dep[101010];
ll dp[101010][X];

void dfs(ll pnt, ll pre, ll _dep){
    dep[pnt]=_dep;
    for(ll i : lnk[pnt]){
        if(i!=pre){
            dp[i][0]=pnt;
            dfs(i, pnt, _dep+1);
        }
    }
}

void _dp(){
    forf(i, 1, X){
        forf(j, 1, n+1){
            dp[j][i]=dp[dp[j][i-1]][i-1];
        }
    }
}

ll lca(ll p, ll q){
    if(dep[p]>dep[q]) swap(p, q);
    ll depd=dep[q]-dep[p];
    forf(i, 0, X) if(depd&(1<<i)) q=dp[q][i];
    if(p==q) return p;
    forb(i, X, 0){
        if(dp[p][i]!=dp[q][i]){p=dp[p][i]; q=dp[q][i];}
    }
    return dp[p][0];
}

int main(){
    fastio;

    cin >> n;
    forf(i, 0, n-1){
        ll a, b; cin >> a >> b;
        lnk[a].pb(b);
        lnk[b].pb(a);
    }
    dfs(1, 0, 0);
    _dp();

    ll q; cin >> q;
    while(q--){
        ll a, b, c; cin >> a >> b >> c;
        ll lb=lca(a, b), lc=lca(a, c), l=lca(b, c);
        ll _d=lb;
        if(dep[_d]<dep[lc]) _d=lc;
        if(dep[_d]<dep[l]) _d=l;
        cout << _d << "\n";
    }

    return 0;
}
