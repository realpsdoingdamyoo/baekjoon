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
const vpii dir4={{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
const vpii dir8={{0, 1}, {1, 0}, {-1, 0}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
const ll inf=2147483647, linf=9223372036854775807;
const double pi=acos(-1), E=2.718281828459;
ll gcd(ll a, ll b){return b?gcd(b, a%b):a;}
#define cf cout.flush()

const ll BI=inf*8282828;
ll n, m;

ll v[5][101010];
ll u[5][101010];
V<array<ll, 4>> Q;
vi A;

void dijk(ll s, ll e, ll x, ll y){
    for(ll i=0; i<n; i++) for(ll j=s; j<=e; j++) u[i][j]=BI;
    u[x][y]=v[x][y];

    PQ<tii, V<tii>, greater<tii>> pq;
    pq.push({v[x][y], x, y});

    while(pq.size()){
        ll d=pq.top()[0];
        ll p=pq.top()[1];
        ll q=pq.top()[2];
        pq.pop();

        if(u[p][q]<d) continue;

        for(pii i : dir4){
            ll np=p+i[0], nq=q+i[1];
            if(np<0 || np>=n || nq<s || nq>e) continue;
            ll nd=d+v[np][nq];

            if(u[np][nq]<=nd) continue;

            pq.push({nd, np, nq});
            u[np][nq]=nd;
        }
    }
}

void dnc_dijk(ll s, ll e, vi qs){
    if(s>e) return;
    ll mid=s+e>>1;

    forf(i, 0, n){
        dijk(s, e, i, mid);
        for(ll j : qs){
            ll sx=Q[j][0], sy=Q[j][1], ex=Q[j][2], ey=Q[j][3];
            ll d=u[sx][sy]+u[ex][ey]-v[i][mid];
            A[j]=min(A[j], d);
        }
    }

    vi L, R;
    for(ll i : qs){
        if(Q[i][3]<mid) L.pb(i);
        if(Q[i][1]>mid) R.pb(i);
    }

    dnc_dijk(s, mid-1, L);
    dnc_dijk(mid+1, e, R);
}

int main(){
    fastio;

    cin >> n >> m;

    forf(i, 0, n) forf(j, 0, m) cin >> v[i][j];

    ll q; cin >> q;
    vi __all;
    forf(i, 0, q) __all.pb(i);
    forf(i, 0, q){
        ll sx, sy, ex, ey;
        cin >> sx >> sy >> ex >> ey;
        if(sy>ey){
            swap(sy, ey);
            swap(sx, ex);
        }
        Q.pb({sx-1, sy-1, ex-1, ey-1});
        A.pb(BI);
    }

    dnc_dijk(0, m-1, __all);

    for(ll i : A) cout <<i << "\n";

    return 0;
}
