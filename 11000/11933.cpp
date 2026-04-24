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
vi num;
V<vpii> lnk;
vi centout;
vi stsize;
vvi cent_tree;
vi centparent;
vi closew;
vi color;
ll the_cent;
vi parent;
vi depth;
vi centdist;

void parentfind(ll pnt, ll pre, ll dph, ll cds){
    parent[pnt]=pre; depth[pnt]=dph; centdist[pnt]=cds;
    for(pii i : lnk[pnt]){
        if(i[0]!=pre) parentfind(i[0], pnt, dph+1, cds+i[1]);
    }
}

ll stset(ll pnt, ll pre){
    ll stsz=1;
    for(pii i : lnk[pnt]){
        if(i[0]!=pre && !centout[i[0]])
            stsz+=stset(i[0], pnt);
    }
    stsize[pnt]=stsz;
    return stsz;
}

ll centfind(ll pnt, ll pre, ll subsize){
    for(pii i : lnk[pnt]){
        if(i[0]!=pre && !centout[i[0]] && stsize[i[0]]>=subsize/2)
            return centfind(i[0], pnt, subsize);
    }
    return pnt;
}

void decomp(ll pnt, ll par){
    ll best_path=inf*123456;
    ll subsize=stset(pnt, n);
    ll cent=centfind(pnt, n, subsize);
    centout[cent]=1;
    if(par!=n) cent_tree[par].pb(cent);
    for(pii i : lnk[cent]) if(!centout[i[0]]) decomp(i[0], cent);
}

/*vvi dp(20);

void dpset(){
    forf(i, 0, 20) dp[i].resize(n+1);
    forf(i, 0, 20) dp[i][n]=n;
    forf(i, 0, n) dp[0][i]=parent[i];

    forf(i, 1, 20){
        forf(j, 0, n){
            dp[i][j]=dp[i-1][dp[i-1][j]];
        }
    }
    return;
}

ll lca(ll a, ll b){
    if(depth[a]>depth[b]) swap(a, b);
    ll dst=depth[b]-depth[a];
    forf(i, 0, 20){
        if(dst&(1<<i)) b=dp[i][b];
    }
    if(a==b) return a;

    forb(i, 20, 0){
        if(dp[i][a]!=dp[i][b]){a=dp[i][a]; b=dp[i][b];}
    }

    return dp[0][a];
}

ll pntdist(ll a, ll b){
    return centdist[a]+centdist[b]-centdist[lca(a, b)]*2;
}*/


ll ettc;
ll ett[1010101];
ll app[505050];
ll spt[1010101][20];

void ett_dfs(ll pnt, ll pre){
    app[pnt]=ettc;
    ett[ettc++]=pnt;
    for(pii i : lnk[pnt]){
        if(i[0]==pre) continue;
        ett_dfs(i[0], pnt);
        ett[ettc++]=pnt;
    }
}

void sparse(){
    ett_dfs(the_cent, -1);
    forf(i, 0, ettc) spt[i][0]=centdist[ett[i]];

    forf(d, 1, 20){
        forf(i, 0, ettc){
            if(i+(1<<d)>ettc) break;
            spt[i][d]=min(spt[i+(1<<d-1)][d-1], spt[i][d-1]);
        }
    }
}

ll pntdist(ll a, ll b){
    ll l=app[a], r=app[b];
    if(l>r) swap(l, r);
    ll w=(ll)log2(r-l+1);
    ll ret=min(spt[l][w], spt[r-(1<<w)+1][w]);
    return centdist[a]+centdist[b]-2*ret;
}

void changequery(ll p){
    ll pnt=p;
    color[p]=!color[p];
    ll pon=color[p];

    while(p!=n){
        if(pon) closew[p]=min(closew[p], pntdist(pnt, p));
        else closew[p]=inf*123456;
        p=centparent[p];
    }
    return;
}

ll distquery(ll p){
    ll bestpath=inf*123456, pnt=p;

    while(p!=n){
        bestpath=min(bestpath, closew[p]+pntdist(p, pnt));
        p=centparent[p];
    }
    return bestpath;
}

ll query(vi x, vi y){
    for(ll i : x) changequery(i);
    ll bp=inf*123456;
    for(ll i : y) bp=min(bp, distquery(i));
    for(ll i : x) changequery(i);
    return bp;
}

int main(){
    fastio;
    ll q;
    cin >> n >> q;
    num.resize(n); lnk.resize(n);
    centout.resize(n); stsize.resize(n);
    cent_tree.resize(n); centparent.resize(n);
    closew.resize(n); color.resize(n);
    parent.resize(n); depth.resize(n);
    centdist.resize(n);

    forf(i, 0, n){closew[i]=inf*123456; color[i]=0; centparent[i]=n;}

    forf(i, 0, n-1){
        ll a, b, c; cin >> a >> b >> c;
        lnk[a].pb({b, c});
        lnk[b].pb({a, c});
    }

    decomp(0, n);

    forf(i, 0, n){for(ll j : cent_tree[i]) centparent[j]=i;}
    forf(i, 0, n) if(centparent[i]==n) the_cent=i;

    parentfind(the_cent, n, 0, 0);
    sparse();
    //cout << the_cent << "\n";
    //forf(i, 0, n) cout << depth[i] << " "; cout << "\n";

    while(q--){
        ll a, b; cin >> a >> b;
        vi x(a), y(b);
        forf(i, 0, a) cin >> x[i];
        forf(i, 0, b) cin >> y[i];
        cout << query(x, y) << "\n";
    }



    return 0;
}
