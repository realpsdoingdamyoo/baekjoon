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

ll n, e;
vvi edge, redge;
V<bool> vsd, rvsd;
vi vseq;
vvi scc;

void dfs(ll pnt){
    vsd[pnt]=true;
    for(ll i : edge[pnt]){
        if(!vsd[i]) dfs(i);
    }
    vseq.pb(pnt);
}

void rdfs(ll pnt){
    rvsd[pnt]=true;
    for(ll i : redge[pnt]){
        if(!rvsd[i]) rdfs(i);
    }
    scc[scc.size()-1].pb(pnt);
}

bool cmp(vi a, vi b){
    return a[0]<b[0];
}

int main(){
    fastio;

    cin >> n >> e;
    edge.resize(n); redge.resize(n);
    vsd.resize(n); rvsd.resize(n);

    forf(i, 0, e){
        ll a, b; cin >> a >> b;
        edge[a-1].pb(b-1);
        redge[b-1].pb(a-1);
    }
    forf(i, 0, n){
        sortv(edge[i]);
        sortv(redge[i]);
    }

    forf(i, 0, n){
        if(!vsd[i]) dfs(i);
    }

    while(vseq.size()){
        ll vt=vseq[vseq.size()-1];
        if(rvsd[vt]){
            vseq.pop_back();
            continue;
        }

        scc.pb({});
        rdfs(vt);
        sortv(scc[scc.size()-1]);
    }

    sortc(scc, cmp);
    cout << (scc.size()==1?"Yes":"No");

    return 0;
}
