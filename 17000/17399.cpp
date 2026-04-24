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

ll n;
vvi lnk;
vi dep, par;
vvi spt;

void dfs(ll pnt, ll pre, ll depth){
    dep[pnt]=depth; spt[pnt][0]=pre;
    for(ll i : lnk[pnt])
        if(i!=pre) dfs(i, pnt, depth+1);
}

void sparse(){
    forf(j, 1, 17){
        forf(i, 1, n+1)
            spt[i][j]=spt[spt[i][j-1]][j-1];
    }
}

ll lca(ll a, ll b){
    if(dep[a]<dep[b]) swap(a, b);
    ll diff=dep[a]-dep[b];

    forf(i, 0, 17) if(diff&(1<<i)) a=spt[a][i];

    if(a==b) return a;

    forb(i, 17, 0){
        if(spt[a][i]!=spt[b][i]){
            a=spt[a][i];
            b=spt[b][i];
        }
    }
    return spt[a][0];
}

ll dist(ll a, ll b){
    return dep[a]+dep[b]-2*dep[lca(a, b)];
}

ll goup(ll p, ll d){
    forb(i, 17, 0){
        if(d&(1<<i)) p=spt[p][i];
    }
    return p;
}

int main() {
    fastio;

    cin >> n;
    lnk.resize(n+1); dep.resize(n+1); spt.resize(n+1);
    forf(i, 0, n+1) spt[i].resize(17);

    forf(i, 0, n-1){
        ll a, b; cin >> a >> b;
        lnk[a].pb(b); lnk[b].pb(a);
    }

    dfs(1, 0, 0); sparse();

    ll q; cin >> q;
    while(q--){
        ll a, b, c; cin >> a >> b >> c;
        ll r=a, s=b;
        if(dist(b, c)>dist(r, s)) r=b, s=c;
        if(dist(c, a)>dist(r, s)) r=c, s=a;
        if(dep[r]<dep[s]) swap(r, s);
        ll d=dist(r, s);
        if(d%2==1){
            cout << "-1\n";
            continue;
        }
        ll m=goup(r, d/2);
        if(dist(m, a+b+c-r-s)==d/2) cout << m << "\n";
        else cout << "-1\n";

    }

    return 0;
}
