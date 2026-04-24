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


ll n, k;
V<vpii> lnk;
vvi cent_tree;
vi sz, centout;
ll centroid=-1;

ll dfs_getsize(ll pnt, ll pre){
    sz[pnt]=1;
    for(pii i : lnk[pnt])
        if(i[0]!=pre && !centout[i[0]])
            sz[pnt]+=dfs_getsize(i[0], pnt);
    return sz[pnt];
}

ll dfs_getcent(ll pnt, ll pre, ll siz){
    for(pii i : lnk[pnt])
        if(i[0]!=pre && !centout[i[0]] && sz[i[0]]>siz/2)
            return dfs_getcent(i[0], pnt, siz);
    return pnt;
}

void cent_find(ll stt, ll par){
    ll siz=dfs_getsize(stt, -1);
    ll centpnt=dfs_getcent(stt, -1, siz);
    if(centroid==-1) centroid=centpnt;
    centout[centpnt]=1;
    if(par!=-1) cent_tree[par].pb(centpnt);
    for(pii i : lnk[centpnt])
        if(i[0]!=par && !centout[i[0]])
            cent_find(i[0], centpnt);
}


vi centcheck;
map<ll, ll> mpnt;
vpii cur_mpnt;
ll best_path=inf;

void dfs_wayfind(ll pnt, ll pre, ll dist, ll depth){
    cur_mpnt.pb({dist, depth});
    for(pii i : lnk[pnt])
        if(i[0]!=pre && !centcheck[i[0]])
            dfs_wayfind(i[0], pnt, dist+i[1], depth+1);
}

void wayfind(ll pnt){
    mpnt.clear();
    mpnt[0]=0;
    for(pii i : lnk[pnt]){
        if(!centcheck[i[0]])
            dfs_wayfind(i[0], pnt, i[1], 1);
        for(pii p : cur_mpnt){
            if(mpnt[k-p[0]] || k==p[0]){
                best_path=min(best_path, mpnt[k-p[0]]+p[1]);
            }
        }
        for(pii p : cur_mpnt){
            if(mpnt[p[0]]) mpnt[p[0]]=min(mpnt[p[0]], p[1]);
            else mpnt[p[0]]=p[1];
        }
        cur_mpnt.clear();
    }
    centcheck[pnt]=1;
    for(ll i : cent_tree[pnt]) wayfind(i);
}

int main(){
    fastio;

    cin >> n >> k;
    lnk.resize(n); cent_tree.resize(n);
    sz.resize(n); centout.resize(n);
    centcheck.resize(n);
    forf(i, 0, n-1){
        ll a, b, c; cin >> a >> b >> c;
        lnk[a].pb({b, c});
        lnk[b].pb({a, c});
    }

    cent_find(0, -1);
    wayfind(centroid);


    if(best_path==inf) best_path=-1;
    cout << best_path << "\n";

    return 0;
}
