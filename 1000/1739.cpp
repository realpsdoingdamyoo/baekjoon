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

ll n, m, e, N;
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

void SCC(){
    forf(i, 0, N) if(!vsd[i]) dfs(i);

    while(vseq.size()){
        ll vt=vseq[vseq.size()-1];
        if(rvsd[vt]){
            vseq.pop_back();
            continue;
        }
        scc.pb({});
        rdfs(vt);
    }
}

ll Not(ll p){
    if(p<2*n){
        return (p+n)%(2*n);
    }
    return (p-2*n+m)%(2*m)+2*n;
}

bool _2sat(){
    vi sccu(N);
    forf(i, 0, scc.size()){
        for(ll j : scc[i]){
            sccu[j]=i+1;
            if(sccu[j]==sccu[Not(j)]) return false;
        }
    }
    return true;
}

void CCSE(ll a, ll b){
    edge[Not(a)].pb(b);
    edge[Not(b)].pb(a);
}

int main(){
    fastio;

    ll t; cin >> t;
    while(t--){
        edge.clear(); redge.clear();
        vsd.clear(); rvsd.clear();
        vseq.clear(); scc.clear();

        cin >> n >> m >> e; N=2*(n+m);
        edge.resize(N); redge.resize(N);
        vsd.resize(N); rvsd.resize(N);

        forf(i, 0, e){
            ll a, b, c, d; cin >> a >> b >> c >> d;
            a--; b--; c--; d--; // 0~2n-1 / 2n~2n+2m-1
            if(a==c && b==d) continue;
            if(a==c){
                if(b<d) CCSE(a, a);
                else CCSE(a+n, a+n);
            }
            else if(b==d){
                if(a<c) CCSE(b+2*n, b+2*n);
                else CCSE(b+2*n+m, b+2*n+m);

            }
            else{
                ll P, Q, R, S;
                if(a<c){P=b+2*n; S=d+2*n;}
                else{P=b+2*n+m; S=d+2*n+m;}
                if(b<d){Q=c; R=a;}
                else{Q=c+n; R=a+n;}
                CCSE(P, R); CCSE(P, S);
                CCSE(Q, R); CCSE(Q, S);
            }
        }

        forf(i, 0, N){
            for(ll j : edge[i])
                redge[j].pb(i);
        }


        forf(i, 0, N){
            sortv(edge[i]);
            sortv(redge[i]);
        }
        SCC();
        cout << (_2sat()?"Yes":"No") << "\n";
    }

    return 0;
}
