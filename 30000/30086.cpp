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

vpii brid;
vi lnk[101010];
ll vsd[101010];
ll n, m;
vi dfstree[101010];
ll subt[101010];

ll dfs(ll pnt){
    vsd[pnt]=1;
    subt[pnt]=1;
    for(ll i : lnk[pnt]){
        if(!vsd[i]){
            dfstree[pnt].pb(i);
            subt[pnt]+=dfs(i);
        }
    }
    return subt[pnt];
}

int main() {
    fastio;

    cin >> n >> m;
    forf(i, 0, m){
        ll a, b; cin >> a >> b;
        lnk[a].pb(b);
        lnk[b].pb(a);
        brid.pb({a, b});
    }
    dfs(1);
    ll cent=1, prvc=1;
    while(subt[cent]>n){
        prvc=cent;
        ll mp=dfstree[cent][0];
        for(ll i : dfstree[cent]){
            if(subt[mp]<subt[i]) mp=i;
        }
        cent=mp;
    }
    //cout << prvc << " " << cent << "\n";
    forf(i, 0, m){
        if(brid[i][0]==prvc && brid[i][1]==cent)
            cout << i+1;
        if(brid[i][0]==cent && brid[i][1]==prvc)
            cout << i+1;

    }


    return 0;
}
