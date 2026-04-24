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

const ll X=303030;
ll k, n, p;
vi dag[2][X];
ll dc[2][X];
ll ans[2][X];
ll ord[2][X];
PQ<ll, vi, greater<ll>> pq[2];

void dagdagdag(ll t){
    forf(i, 0, n) if(dc[t][i]==0) pq[t].push(i);

    forf(i, 0, n){
        ll tp=pq[t].top();
        ans[t][tp]=ord[t][i]; pq[t].pop();
        for(ll i : dag[t][tp]) if(!--dc[t][i]) pq[t].push(i);
    }
}

int main(){
    fastio;

    cin >> k >> n >> p;

    forf(i, 0, p){
        ll a, b; cin >> a >> b;
        dag[0][a].pb(b); dc[0][b]++;
        dag[1][b].pb(a); dc[1][a]++;
    }

    forf(i, 0, n) ord[0][i]=n-i-1;
    forf(i, 0, n) ord[1][i]=k-n+i;

    dagdagdag(0);
    dagdagdag(1);

    ll ret=0, q=1;

    forf(i, 0, n){
        ret=(q*((ans[1][i]-ans[0][i]+mod)%mod)%mod+ret)%mod;
        q=q*k%mod;
    }
    cout << ret;

    return 0;
}
