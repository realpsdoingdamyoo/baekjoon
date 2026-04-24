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
vvi lnk;
vi centout;
vi stsize;
vvi cent_tree;
vi centparent;
vi closew;
vi color;
ll the_cent;
vi parent;
vi depth;

void parentfind(ll pnt, ll pre, ll dph){
    parent[pnt]=pre; depth[pnt]=dph;
    for(ll i : lnk[pnt]){
        if(i!=pre) parentfind(i, pnt, dph+1);
    }
}

ll stset(ll pnt, ll pre){
    ll stsz=1;
    for(ll i : lnk[pnt]){
        if(i!=pre && !centout[i])
            stsz+=stset(i, pnt);
    }
    stsize[pnt]=stsz;
    return stsz;
}

ll centfind(ll pnt, ll pre, ll subsize){
    for(ll i : lnk[pnt]){
        if(i!=pre && !centout[i] && stsize[i]>=subsize/2)
            return centfind(i, pnt, subsize);
    }
    return pnt;
}

void decomp(ll pnt, ll par){
    ll best_path=inf;
    ll subsize=stset(pnt, n);
    ll cent=centfind(pnt, n, subsize);
    centout[cent]=1;
    if(par!=n) cent_tree[par].pb(cent);
    for(ll i : lnk[cent]) if(!centout[i]) decomp(i, cent);
}

vvi dp(20);

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

ll ancefind(ll pnt, ll dst){
    forf(i, 0, 20){
        if(dst&(1<<i)) pnt=dp[i][pnt];
    }
    return pnt;
}

ll lca(ll a, ll b){
    if(depth[a]>depth[b]) swap(a, b);
    b=ancefind(b, depth[b]-depth[a]);

    ll s=0, e=depth[a];
    while(s<=e){
        ll m=(s+e)/2;
        if(ancefind(a, m)==ancefind(b, m)) e=m-1;
        else s=m+1;
    }
    return ancefind(a, s);
}

ll pntdist(ll a, ll b){
    return depth[a]+depth[b]-depth[lca(a, b)]*2;
}

V<PQ<pii>> whitepq;
V<PQ<pii>> whitedpq;


void changequery(ll p){
    ll pnt=p;
    color[p]=!color[p];
    ll pon=color[p];

    while(p!=n){
        if(pon) whitepq[p].push({-pntdist(pnt, p), -pnt});
        else whitedpq[p].push({-pntdist(pnt, p), -pnt});
        while(whitedpq[p].size() && whitedpq[p].top()==whitepq[p].top()){
            whitedpq[p].pop(); whitepq[p].pop();
        }
        p=centparent[p];
    }
    return;
}

ll printquery(ll p){

    /*forf(i, 0, n){
        cout << "(";
        if(whitepq[i].size()){
            pii a=whitepq[i].top();
            cout << a[1];
        }
        cout << ")";
    }
    cout << "\n";*/



    ll bestpath=inf, bestpnt=n, pnt=p;

    while(p!=n){
        if(whitepq[p].size()){
            pii a=whitepq[p].top();
            //cout << p << " " << a[1] << "\n";
            if(bestpath>pntdist(pnt, -a[1])){
                bestpath=pntdist(pnt, -a[1]);
                bestpnt=-a[1];
            }
            else if(bestpath==pntdist(pnt, -a[1]) && -a[1]<bestpnt){
                bestpnt=-a[1];
            }
            //cout << "[" << -a[1] << " " << pntdist(pnt, -a[1]) << "]";
            //cout << "[" <<pnt << " " << a[1] << " " << pntdist(pnt, a[1]) << " " << lca(pnt, a[1]) << "]";
        }
        p=centparent[p];

    }
    if(bestpath>=inf) return n-1;
    else return bestpnt;
}

int main(){
    fastio;

    cin >> n;
    num.resize(n); lnk.resize(n);
    centout.resize(n); stsize.resize(n);
    cent_tree.resize(n); centparent.resize(n);
    closew.resize(n); color.resize(n);
    whitepq.resize(n); whitedpq.resize(n);
    parent.resize(n); depth.resize(n);

    forf(i, 0, n){closew[i]=inf; color[i]=0; centparent[i]=n;}

    forf(i, 0, n-1){
        ll a, b; cin >> a >> b;
        lnk[a-1].pb(b-1);
        lnk[b-1].pb(a-1);
    }

    decomp(0, n);

    forf(i, 0, n){for(ll j : cent_tree[i]) centparent[j]=i;}
    forf(i, 0, n) if(centparent[i]==n) the_cent=i;

    parentfind(the_cent, n, 0);
    dpset();

    /*forf(i, 0, n){
        cout << i+1 << " " << depth[i] << ")";
        forf(j, 0, 3) if(dp[j][i]!=n) cout << dp[j][i]+1 << " ";
        cout << "\n";
    }*/




    vi ans(n);
    forb(i, n, 0){
        ans[i]=printquery(i);
        changequery(i);
    }
    forf(i, 0, n) cout << ans[i]+1 << " ";


    return 0;
}
