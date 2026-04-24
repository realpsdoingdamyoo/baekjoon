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
V<vpii> lnk(100005);
vi centout(100005);
vi stsize(100005);
vvi cent_tree(100005);
vi centparent(100005);
vi closew(100005);
vi color(100005);
ll the_cent;
vi parent(100005);
vi depth(100005);
vi H(100005);

void parentfind(ll pnt, ll pre, ll dph, ll h){
    parent[pnt]=pre; depth[pnt]=dph; H[pnt]=h;
    for(pii i : lnk[pnt]){
        if(i[0]!=pre) parentfind(i[0], pnt, dph+1, h+i[1]);
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
    ll best_path=inf;
    ll subsize=stset(pnt, n);
    ll cent=centfind(pnt, n, subsize);
    centout[cent]=1;
    if(par!=n){
        cent_tree[par].pb(cent);
        centparent[cent]=par;
    }
    else the_cent=cent;
    for(pii i : lnk[cent]) if(!centout[i[0]]) decomp(i[0], cent);
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
    return H[a]+H[b]-H[lca(a, b)]*2;
}


pii dp_[100005];
ll cnt;
unordered_map<ll, ll> dp2[100005];

void query1(ll x){
    if(color[x]) return;
    cnt++; color[x]=1;
    dp_[x][0]++;

    ll pnt=centparent[x], prev=x;
    while(prev!=the_cent){
        ll d=pntdist(x, pnt);
        dp_[pnt][1]+=d;
        dp_[pnt][0]++;
        dp2[pnt][prev]+=d;
        prev=pnt;
        pnt=centparent[pnt];
    }
}

ll query2(ll x){
    ll r=dp_[x][1];
    ll pnt=centparent[x], prev=x;

    while(prev!=the_cent){
        ll cnt=dp_[pnt][0]-dp_[prev][0];
        r+=dp_[pnt][1]-dp2[pnt][prev];
        r+=cnt*pntdist(pnt, x);
        prev=pnt;
        pnt=centparent[pnt];
    }
    return r;
}

int main(){
    fastio;
    ll q;
    cin >> n;

    forf(i, 1, n){
        ll a, b; cin >> a >> b;
        lnk[i].pb({a, b});
        lnk[a].pb({i, b});
    }

    forf(i, 0, n) centparent[i]=n;

    decomp(0, n);
    parentfind(the_cent, n, 0, 0);
    dpset();


    cin >> q;
    forf(i, 0, q){
        ll a, b; cin >> a >> b;
        if(a==1) query1(b);
        else cout << query2(b) << "\n";
    }


    return 0;
}
