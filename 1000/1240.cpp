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


V<vpii> lnk; ll n, m;
V<ll> vsd, dist;

void dfs(ll pnt){
    if(vsd[pnt]) return;
    //cout << "(" << pnt << " " << dist[pnt] << ")";
    vsd[pnt]=1;
    for(pii i : lnk[pnt]){
        if(!vsd[i[0]]){
            dist[i[0]]=dist[pnt]+i[1];
            dfs(i[0]);
        }
    }
    return;
}

int main(){
    fastio;

    cin >> n >> m;
    lnk.resize(n+1); vsd.resize(n+1); dist.resize(n+1);
    forf(i, 0, n-1){
        ll a, b, c; cin >> a >> b >> c;
        lnk[a].pb({b, c});
        lnk[b].pb({a, c});
    }

    while(m--){
        ll a, b; cin >> a >> b;
        forf(i, 0, n+1) vsd[i]=dist[i]=0;
        dfs(a);
        cout << dist[b] << "\n";
    }

    return 0;
}
