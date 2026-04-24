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

ll n, m, e;
vvi lnk, rlnk;
vvi scc;
V<bool> vsd, rvsd;
vi vseq;
vpii lnkp;

void dfs(ll pnt){
    vsd[pnt]=true;
    for(ll i : lnk[pnt]) if(!vsd[i]) dfs(i);
    vseq.pb(pnt);
}

void rdfs(ll pnt){
    rvsd[pnt]=true;
    for(ll i : rlnk[pnt]) if(!rvsd[i]) rdfs(i);
    scc.back().pb(pnt);
}

int main(){
    fastio;

    cin >> n >> e;
    lnk.resize(n); rlnk.resize(n);
    vsd.resize(n); rvsd.resize(n);
    forf(i, 0, e){
        ll a, b; cin >> a >> b;
        lnk[a-1].pb(b-1);
        rlnk[b-1].pb(a-1);
        lnkp.pb({a-1, b-1});
    }

    forf(i, 0, n){
        if(!vsd[i]) dfs(i);
    }

    while(vseq.size()){
        ll vt=vseq.back();
        if(rvsd[vt]){
            vseq.pop_back();
            continue;
        }

        scc.pb({});
        rdfs(vt);
    }

    m=scc.size();
    vi sccw(n), arr(m), fam(m);
    vvi nlnk(m);
    forf(i, 0, m) for(ll j : scc[i]) sccw[j]=i;
    map<pii, bool> lnkpc;

    for(pii i : lnkp){
        i={sccw[i[0]], sccw[i[1]]};
        if(i[0]==i[1]) continue;
        if(lnkpc[i]) continue;
        lnkpc[i]=true;
        nlnk[i[0]].pb(i[1]);
        arr[i[1]]++;
    }

    queue<ll> q;
    forf(i, 0, m){
        if(arr[i]==0) q.push(i);
        fam[i]=scc[i].size();
    }

    ll ans=0;

    while(q.size()){
        ll t=q.front(); q.pop();

        if(fam[t]==n) ans+=scc[t].size();

        for(ll i : nlnk[t]){
            fam[i]+=fam[t];
            arr[i]--;
            if(arr[i]==0) q.push(i);
        }
    }

    cout << ans;

    return 0;
}
