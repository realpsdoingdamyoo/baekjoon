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
#define cf cout.flush()

ll n, m, G;
V<vpii> lnk, ed;
V<bool> un;
V<tii> ln;

void mst(){
    PQ<tii> pq;
    un[0]=true;
    for(pii i : ed[0])
        pq.push({-i[1], 0, i[0]});

    while(pq.size()){
        tii tp=pq.top(); pq.pop();
        if(un[tp[2]]) continue;

        lnk[tp[1]].pb({tp[2], -tp[0]});
        lnk[tp[2]].pb({tp[1], -tp[0]});
        G-=tp[0];

        un[tp[2]]=true;

        for(pii i : ed[tp[2]])
            pq.push({-i[1], tp[2], i[0]});
    }
}

V<array<ll, 20>> up, spt;
vi dep;

void dfs(ll pnt, ll pre, ll mnv, ll d){
    up[pnt][0]=pre;
    spt[pnt][0]=mnv;
    dep[pnt]=d;
    for(pii i : lnk[pnt])
        if(i[0]!=pre) dfs(i[0], pnt, i[1], d+1);
}

void sparse(){
    dfs(0, 0, inf, 0);

    forf(i, 1, 20){
        forf(j, 0, n){
            up[j][i]=up[up[j][i-1]][i-1];
            spt[j][i]=max(spt[j][i-1], spt[up[j][i-1]][i-1]);
        }
    }
}

ll upmin(ll p, ll h){
    ll ret=0;
    forb(i, 20, 0){
        if((h&(1<<i))==0) continue;
        ret=max(ret, spt[p][i]);
        p=up[p][i];
    }
    return ret;
}

ll que(ll a, ll b){
    ll ret=0;

    if(dep[a]<dep[b]) swap(a, b);
    ll df=dep[a]-dep[b];

    ret=upmin(a, df);

    forb(i, 20, 0){
        if(df&(1<<i)) a=up[a][i];
    }

    if(a==b) return ret;

    forb(i, 20, 0){
        if(up[a][i]!=up[b][i]){
            ret=max(ret, spt[a][i]);
            ret=max(ret, spt[b][i]);

            a=up[a][i]; b=up[b][i];
        }
    }

    ret=max(ret, spt[a][0]);
    ret=max(ret, spt[b][0]);
    return ret;
}

int main(){
    fastio;
    cin >> n >> m;

    ed.resize(n);
    lnk.resize(n);
    un.resize(n);
    up.resize(n);
    spt.resize(n);
    dep.resize(n);

    forf(i, 0, m){
        ll a, b, c; cin >> a >> b >> c;
        a--; b--;
        ed[a].pb({b, c});
        ed[b].pb({a, c});
        ln.pb({a, b, c});
    }

    mst();
    sparse();

    for(tii i : ln){
        cout << G+i[2]-que(i[0], i[1]) << "\n";
    }

    return 0;
}
