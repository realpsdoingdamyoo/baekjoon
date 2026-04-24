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
ll dirn[8][2]={{1, 2}, {2, 1}, {-1, 2}, {2, -1}, {-2, 1}, {1, -2}, {-1, -2}, {-2, -1}};

typedef array<lf, 2> pff;

ll dst(pff a, pff b){
    return (ll)(sqrt(pow(a[0]-b[0], 2)+pow(a[1]-b[1], 2))*1e7);
}

int main() {
    fastio;

    pff x, y;
    cin >> x[0] >> x[1] >> y[0] >> y[1];
    ll n; cin >> n; V<pff> p(n+2);
    forf(i, 1, n+1) cin >> p[i][0] >> p[i][1];
    p[0]=x; p[n+1]=y;

    V<vpii> lnk(n+2);

    forf(i, 1, n+2){
        lnk[0].pb({i, dst(p[0], p[i])/5});
    }
    forf(i, 1, n+1){
        lnk[i].pb({n+1, min((lf)dst(p[i], p[n+1])/5, abs(dst(p[i], p[n+1])-5e8)/5+2e7)});
    }
    forf(i, 1, n+1) forf(j, 1, n+1){
        lnk[i].pb({j, min((lf)dst(p[i], p[j])/5, abs(dst(p[i], p[j])-5e8)/5+2e7)});
        lnk[j].pb({i, min((lf)dst(p[i], p[j])/5, abs(dst(p[i], p[j])-5e8)/5+2e7)});
    }

    vi dist(n+2), vsd(n+2);
    forf(i, 1, n+2) dist[i]=inf*8000;

    PQ<pii> pq; pq.push({0, 0});

    while(pq.size()){
        ll pd=-pq.top()[0];
        ll pn=pq.top()[1];
        pq.pop();
        if(dist[pn]<pd) continue;

        for(pii l : lnk[pn]){
            ll nn=l[0], nd=pd+l[1];
            if(nd<dist[nn]){
                dist[nn]=nd;
                pq.push({-nd, nn});
            }
        }
    }
    cout.precision(9);
    cout << dist[n+1]/1e7;


	return 0;
}
