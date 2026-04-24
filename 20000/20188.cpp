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

const ll X=303030;
ll dis[X], sz[X];
vi lnk[X];

void dfs(ll pnt, ll pre){
    for(ll i : lnk[pnt]){
        if(i==pre) continue;
        dis[i]=dis[pnt]+1;
        dfs(i, pnt);
        sz[pnt]+=sz[i];
    }
    sz[pnt]++;
}

int main(){
    fastio;

    ll n; cin >> n;
    forf(i, 1, n){
        ll a, b; cin >> a >> b;
        lnk[a].pb(b);
        lnk[b].pb(a);
    }
    dfs(1, 23456789);

    ll ret=0;
    forf(i, 1, n+1){
        ret+=dis[i]*(n-1);

        ll sum=0, sqs=0;
        for(ll j : lnk[i]){
            if(sz[j]>sz[i]) continue;
            sum+=sz[j];
            sqs+=sz[j]*sz[j];
        }
        ret-=dis[i]*((sum*sum-sqs)/2+sum);
    }
    cout << (ll)ret;

    return 0;
}
