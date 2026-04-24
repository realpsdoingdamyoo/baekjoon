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

ll n, m, p;
vi uf;
vvi unions;
V<tii> edge;

bool cmp(tii a, tii b){return a[2]<b[2];}

void unionfind(ll a, ll b){
    a=uf[a]; b=uf[b];
    if(a==b) return;

    if(unions[a].size()<unions[b].size()) swap(a, b);
    p-=unions[a].size()*(unions[a].size()-1)/2;
    p-=unions[b].size()*(unions[b].size()-1)/2;

    for(ll i : unions[b]){
        unions[a].pb(i);
        uf[i]=a;
    }
    unions[b].clear();
    p+=unions[a].size()*(unions[a].size()-1)/2;

}

int main(){
    fastio;

    cin >> n >> m;
    uf.resize(n);
    unions.resize(n);
    edge.resize(m);

    forf(i, 0, n){
        uf[i]=i;
        unions[i].pb(i);
    }

    forf(i, 0, m){
        forf(j, 0, 3) cin >> edge[i][j];
        forf(j, 0, 2) edge[i][j]--;
    }

    sortc(edge, cmp);

    ll ans=0;
    while(edge.size()){
        tii e=edge.back(); edge.pop_back();
        unionfind(e[0], e[1]);
        ans+=p*e[2];
    }

    cout << ans%1000000000;

    return 0;
}
