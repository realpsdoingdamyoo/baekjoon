#include <bits/stdc++.h>
using namespace std;
typedef int ll;
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

ll n, dmy, C, N;
vi plnk[500000];
vpii lnk[500000];
ll parent[500000];

void dfs(ll pnt, ll pre){
    C+=max(0, (ll)plnk[pnt].size()-3+!pnt);
    parent[pnt]=pre;
    if(pre!=-1) plnk[pnt].erase(find(all(plnk[pnt]), pre));
    for(ll i : plnk[pnt])
        if(i!=pre) dfs(i, pnt);
}

void con(ll a, ll b, ll w){
    lnk[a].pb({b, w}); lnk[b].pb({a, w});
}

void rdfs(ll pnt){
    for(ll i : plnk[pnt]) rdfs(i);
    if(plnk[pnt].size()<=2){
        for(ll i : plnk[pnt]) con(i, pnt, 1);
        return;
    }
    ll sz=plnk[pnt].size()-1;

    con(pnt, plnk[pnt][0], 1);
    forf(i, 1, sz) con(dmy+i-1, plnk[pnt][i], 1);
    con(dmy+sz-2, plnk[pnt].back(), 1);

    forf(i, 1, sz-1) con(dmy+i-1, dmy+i, 0);
    con(pnt, dmy, 0);
    dmy+=sz-1;
}

void rebuild(){
    dfs(0, -1);
    rdfs(0);
    n=C;
}

void init(){
    cin >> n;
    dmy=n; C=n; N=n;

    forf(i, 0, n-1){
        ll a, b;
        cin >> a >> b;
        plnk[a-1].pb(b-1);
        plnk[b-1].pb(a-1);
    }
    rebuild();
}

ll stsize[500000], centparent[500000];
ll centdist[500000], depth[500000];
bool centout[500000], chk[250005];
vi cent_tree[500000];
ll the_cent;
PQ<pii> pq[500000][4];
ll cid[500000];

void parentfind(ll pnt, ll pre, ll dst, ll dep){
    parent[pnt]=pre; centdist[pnt]=dst; depth[pnt]=dep+1;
    for(pii i : lnk[pnt]){
        if(i[0]!=pre) parentfind(i[0], pnt, dst+i[1], dep+1);
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
        if(i[0]!=pre && !centout[i[0]] && stsize[i[0]]>subsize/2)
            return centfind(i[0], pnt, subsize);
    }
    return pnt;
}

void decomp(ll pnt, ll par){
    ll subsize=stset(pnt, -1);
    ll cent=centfind(pnt, -1, subsize);
    centout[cent]=1;
    if(par!=-1) cent_tree[par].pb(cent);
    for(pii i : lnk[cent]) if(!centout[i[0]]) decomp(i[0], cent);
}

const ll X=20;
ll ettc;
ll ett[1<<X+1];
ll app[505050];

void ett_dfs(ll pnt, ll pre){
    app[pnt]=ettc;
    ett[(1<<X)+ettc++]=centdist[pnt];
    for(pii i : lnk[pnt]){
        if(i[0]==pre) continue;
        ett_dfs(i[0], pnt);
        ett[(1<<X)+ettc++]=centdist[pnt];
    }
}

void seginit(){
    forb(i, X, 0){
        forf(j, 1<<i, 1<<i+1)
            ett[j]=min(ett[j*2], ett[j*2+1]);
    }
}

ll MIN(ll s, ll e){
    s+=1<<X; e+=1<<X;
    ll ret=inf;
    while(s<=e){
        if(s&1) ret=min(ret, ett[s]);
        if(~e&1) ret=min(ret, ett[e]);
        s=(s+1)/2; e=(e-1)/2;
    }
    return ret;
}

ll pntdist(ll a, ll b){
    ll l=app[a], r=app[b];
    if(l>r) swap(l, r);
    ll ret=MIN(l, r);
    return centdist[a]+centdist[b]-2*ret;
}

ll FIND(ll p){
    pii ret={-1, -1};
    forf(x, 1, 4){
        while(pq[p][x].size() && chk[pq[p][x].top()[1]])
            pq[p][x].pop();
        if(pq[p][x].size()==0) continue;
        ret=max(ret, pq[p][x].top());
    }
    ll pr=p, c=centparent[p];

    while(c!=-1){
        forf(x, 0, 4){
            if(x==cid[pr]) continue;
            while(pq[c][x].size() && chk[pq[c][x].top()[1]])
                pq[c][x].pop();
            if(pq[c][x].size()==0) continue;
            ret=max(ret, {pq[c][x].top()[0]+pntdist(c, p), pq[c][x].top()[1]});
        }
        pr=c; c=centparent[c];
    }
    chk[ret[1]]=true;
    return ret[1];
}

void pq_dfs(ll pnt){
    ll CNT=1;
    if(pnt<N){
        pq[pnt][0].push({0, pnt});
        plnk[pnt].pb(pnt);
    }
    for(ll i : cent_tree[pnt]){
        pq_dfs(i);
        while(plnk[i].size()){
            ll bck=plnk[i].back();
            pq[pnt][CNT].push({pntdist(bck, pnt), bck});
            plnk[pnt].pb(bck);
            plnk[i].pop_back();
        }
        cid[i]=CNT;
        CNT++;
    }
}

int main(){
    fastio;

    init();
    forf(i, 0, n) plnk[i].clear();

    forf(i, 0, n) centparent[i]=-1;
    decomp(0, -1);
    forf(i, 0, n){for(ll j : cent_tree[i]) centparent[j]=i;}
    forf(i, 0, n) if(centparent[i]==-1) the_cent=i;
    centparent[the_cent]=-1;

    parentfind(the_cent, -1, 0, 0);
    ett_dfs(the_cent, -1);
    seginit();

    pq_dfs(the_cent);
    plnk[the_cent].clear();

    forf(i, 0, n) cent_tree[i].pb(i);
    chk[0]=true;
    ll p=0;
    cout << "1 ";


    forf(i, 0, N-1){
        p=FIND(p);
        cout << p+1 << " ";
    }


    return 0;
}
