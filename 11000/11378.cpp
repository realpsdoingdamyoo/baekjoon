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
#define cf; cout.flush();

ll n, m, k;
vvi lnk;
vi match;
V<bool> cons;

bool dfs(ll pnt){
    for(ll i : lnk[pnt]){
        if(cons[i]) continue;
        cons[i]=true;
        if(match[i]==-1 || dfs(match[i])){
            match[i]=pnt; return true;
        }
    }
    return false;
}


ll two_minute(){
    queue<vi> q;
    ll c=0, d=0;
    forf(i, 0, n){
        forf(j, 0, m) cons[j]=false;
        if(dfs(i)) c++;
        q.push(lnk[i]);
    }
    while(q.size()){
        lnk.pb(q.front()); q.pop();
        forf(j, 0, m) cons[j]=false;
        if(dfs(lnk.size()-1)){c++; d++; q.push(lnk[lnk.size()-1]);}
        if(d>=k) break;
    }
    return c;
}

int main() {
    fastio;

    cin >> n >> m >> k;
    lnk.resize(n);
    match.resize(m);
    forf(i, 0, m) match[i]=-1;
    cons.resize(m);
    forf(i, 0, n){
        ll a; cin >> a;
        while(a--){
            ll b; cin >> b;
            lnk[i].pb(b-1);
        }
    }

    cout << two_minute();

    return 0;
}
