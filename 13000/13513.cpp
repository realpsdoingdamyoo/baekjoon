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

ll n, the_cent;
V<vpii> lnk;
vvi cent_tree, dp;
V<bool> centout, color;
vi treesz, centparent, depth, oned, parent, cparent;
V<V<array<PQ<ll>, 2>>> subt;
V<array<PQ<ll>, 2>> submx;
array<PQ<ll>, 2> st;
ll q;

void viset(){
    lnk.resize(n+1);
    centout.resize(n+1);
    color.resize(n+1);
    treesz.resize(n+1);
    cent_tree.resize(n+1);
    dp.resize(n+1);
    centparent.resize(n+1);
    depth.resize(n+1);
    oned.resize(n+1);
    parent.resize(n+1);
    cparent.resize(n+1);
    subt.resize(n+1);
    submx.resize(n+1);
}

ll szdp(ll pnt, ll pre){
    ll ret=1;
    for(pii i : lnk[pnt]){
        if(i[0]!=pre && !centout[i[0]])
            ret+=szdp(i[0], pnt);
    }
    return treesz[pnt]=ret;
}

ll centdfs(ll pnt, ll pre, ll sz){
    for(pii i : lnk[pnt]){
        if(i[0]!=pre && !centout[i[0]] && treesz[i[0]]>sz/2)
            return centdfs(i[0], pnt, sz);
    }
    return pnt;
}

void decomp(ll pnt, ll pre){
    ll sz=szdp(pnt, 0);
    ll cent=centdfs(pnt, 0, sz);
    if(!pre) the_cent=cent;
    else cent_tree[pre].pb(cent);
    centparent[cent]=pre;
    centout[cent]=true;
    for(pii i : lnk[cent]) if(!centout[i[0]]) decomp(i[0], cent);
}

void dfs_pfind(ll pnt, ll pre, ll dep, ll onedep){
    dp[pnt][0]=pre; depth[pnt]=dep; oned[pnt]=onedep;
    ll cnt=0;
    for(pii i : lnk[pnt]){
        if(i[0]!=pre){
            parent[i[0]]=pnt;
            dfs_pfind(i[0], pnt, dep+1, onedep+i[1]);
        }
    }
}

void dpset(){
    forf(i, 0, n+1) dp[i].resize(20);
    dfs_pfind(1, 0, 0, 0);
    forf(j, 1, 20) forf(i, 1, n+1){
        dp[i][j]=dp[dp[i][j-1]][j-1];
    }
}

ll lca(ll p1, ll p2){
    if(depth[p1]<depth[p2]) swap(p1, p2);
    forf(i, 0, 20){
        if((depth[p1]-depth[p2])&(1<<i)) p1=dp[p1][i];
    }
    if(p1==p2) return p1;
    forb(i, 20, 0) if(dp[p1][i]!=dp[p2][i]){p1=dp[p1][i]; p2=dp[p2][i];}
    return dp[p1][0];
}

ll pntdist(ll p1, ll p2){
    return oned[p1]+oned[p2]-2*oned[lca(p1, p2)];
}

void del(array<PQ<ll>, 2>& pq){
    while(pq[1].size() && pq[0].top()==pq[1].top()){
        pq[0].pop(); pq[1].pop();
    }
}

ll toptwo(array<PQ<ll>, 2>& pq){

    ll _mx=pq[0].top(); ll a=_mx;
    pq[0].pop(); del(pq);
    _mx+=pq[0].top(); pq[0].push(a);
    return _mx;
}


void update(ll pnt){
    color[pnt]=!color[pnt];
    ll cent=centparent[pnt], prv=pnt;

    if(submx[pnt][0].size()){
        if(submx[pnt][0].size()-submx[pnt][1].size()==1){
            st[1].push(0); del(st);
        }
        else{
            ll _submx=toptwo(submx[pnt]);
            st[1].push(_submx); del(st);
        }
    }
    if(color[pnt]) submx[pnt][0].push(0);
    else{
        submx[pnt][1].push(0);
        del(submx[pnt]);
    }
    if(submx[pnt][0].size()){
        if(submx[pnt][0].size()-submx[pnt][1].size()==1) st[0].push(0);
        else{
            ll _submx=toptwo(submx[pnt]);
            st[0].push(_submx);
        }
    }
    while(cent){
        if(submx[cent][0].size()){
            if(submx[cent][0].size()-submx[cent][1].size()==1){
                st[1].push(0); del(st);
            }
            else{
                ll _submx=toptwo(submx[cent]);
                st[1].push(_submx); del(st);
            }
        }

        if(!color[pnt]){
            submx[cent][1].push(subt[cent][cparent[prv]][0].top()); del(submx[cent]);
            subt[cent][cparent[prv]][1].push(pntdist(pnt, cent)); del(subt[cent][cparent[prv]]);
            if(subt[cent][cparent[prv]][0].size())
                submx[cent][0].push(subt[cent][cparent[prv]][0].top());
        }
        else{
            if(subt[cent][cparent[prv]][0].size()){
                submx[cent][1].push(subt[cent][cparent[prv]][0].top());
                del(submx[cent]);
            }
            subt[cent][cparent[prv]][0].push(pntdist(pnt, cent));
            submx[cent][0].push(subt[cent][cparent[prv]][0].top());
        }

        if(submx[cent][0].size()){
            if(submx[cent][0].size()-submx[cent][1].size()==1) st[0].push(0);
            else{
                ll _submx=toptwo(submx[cent]);
                st[0].push(_submx);
            }
        }
        prv=cent;
        cent=centparent[cent];
    }
}

ll query(){
    if(st[0].size()) return st[0].top();
    return -1;
}

int main(){
    fastio;
    cin >> n; viset();
    forf(i, 0, n-1){
        ll a, b, c; cin >> a >> b >> c;
        lnk[a].pb({b, c});
        lnk[b].pb({a, c});
    }
    decomp(1, 0); dpset();
    forf(i, 1, n+1) subt[i].resize(cent_tree[i].size());
    forf(i, 1, n+1){
        ll cnt=0;
        for(ll j : cent_tree[i]) cparent[j]=cnt++;
    }

    forf(i, 1, n+1) update(i);

    cin >> q;
    while(q--){
        ll t; cin >> t;
        if(t==1){
            ll a; cin >> a;
            update(a);
        }
        else cout << query() <<"\n";
    }


    return 0;
}
