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

ll n, k, ip, sum;
V<vpii> lnk;
V<bool> imp;
vi dfso, lc, G;
pii fp[2];
vpii D;
V<bool> out;

void dfs(ll pnt, ll pre, ll dst, ll id){
    if(fp[id][1]<dst && imp[pnt]) fp[id]={pnt, dst};
    for(pii i : lnk[pnt])
        if(i[0]!=pre) dfs(i[0], pnt, dst+i[1], id);
}

void dfs2(ll pnt, ll pre, ll dst, ll id){
    D[pnt][id]=dst;
    for(pii i : lnk[pnt])
        if(i[0]!=pre) dfs2(i[0], pnt, dst+i[1], id);
}

void dfs3(ll pnt, ll pre, ll dst){
    G[pnt]=dst;
    for(pii i : lnk[pnt])
        if(i[0]!=pre) dfs3(i[0], pnt, out[i[0]]?dst+i[1]:0LL);
}

int main(){
    fastio;

    cin >> n >> k;
    lnk.resize(n);
    imp.resize(n);
    dfso.resize(n);
    D.resize(n);
    out.resize(n);
    G.resize(n);

    forf(i, 1, n){
        ll a, b, c; cin >> a >> b >> c;
        lnk[a-1].pb({b-1, c});
        lnk[b-1].pb({a-1, c});
        sum+=c;
    }

    forf(i, 0, k){
        ll a; cin >> a;
        imp[a-1]=true;
        ip=a-1;
    }

    dfs(ip, -1, 0, 0);
    dfs(fp[0][0], -1, 0, 1);

    dfs2(fp[0][0], -1, 0, 0);
    dfs2(fp[1][0], -1, 0, 1);

    lc.resize(n);
    vi wj;
    forf(i, 0, n){
        lc[i]=lnk[i].size();
        if(lc[i]==1 && !imp[i]) wj.pb(i);
    }
    while(wj.size()){
        ll bck=wj.back(); wj.pop_back();
        out[bck]=true;
        for(pii i : lnk[bck]){
            if(out[i[0]]) continue;
            lc[i[0]]--; sum-=i[1];
            if(lc[i[0]]==1 && !imp[i[0]]) wj.pb(i[0]);
        }
    }

    dfs3(ip, -1, 0);

    forf(i, 0, n) cout << sum*2+G[i]*2-max(D[i][0], D[i][1]) << "\n";

    return 0;
}
