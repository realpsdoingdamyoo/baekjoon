#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef array<ll, 2> pii;
typedef array<ll, 3> tii;
typedef vector<pii> vpii;
typedef double lf;
typedef priority_queue<ll> pqi;
#define V vector
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define vcin; for(int i=0; i<n; i++) cin >> v[i];
#define forf(i, s, e) for(ll i=s; i<e; i++)
#define forb(i, s, e) for(ll i=s-1; i>=e; i--)
#define pb push_back
#define sortv(v) sort(v.begin(), v.end())
#define sortc(v, cmp) sort(v.begin(), v.end(), cmp)
#define repeat(n) for(ll not_used_name=0; not_used_name<n; not_used_name++)
#define all(v) v.begin(), v.end()
const int mod=1e9+7, MOD=998244353;
const int dir4[4][2]={{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
const int dir8[8][2]={{0, 1}, {1, 0}, {-1, 0}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
const ll inf=2147483647, linf=9223372036854775807;
const double PI=acos(-1), EU=2.718281828459;
ll gcd(ll a, ll b){return b?gcd(b, a%b):a;}

V<tii> v;
vi vsd;
ll cnt, n;
queue<ll> q;

bool O(tii a, tii b){
    ll dis=(a[0]-b[0])*(a[0]-b[0])+(a[1]-b[1])*(a[1]-b[1]);
    ll rr=(a[2]+b[2])*(a[2]+b[2]);
    return rr>=dis;
}

void dfs(ll x){
    q.push(x);
    while(!q.empty()){
        ll qf=q.front(); q.pop();
        if(vsd[qf]) continue;
        vsd[qf]=1;

        forf(j, 0, n){
            if(!vsd[j] && O(v[qf], v[j])) q.push(j);
        }
    }
    cnt++;
    return;
}

int main() {
    fastio;
    ll t; cin >> t;
    while(t--){
        cin >> n; cnt=0;
        v.resize(n); vsd.resize(n);
        forf(i, 0, n) vsd[i]=0;
        forf(i, 0, 3*n) cin >> v[i/3][i%3];
        forf(i, 0, n){
            if(!vsd[i]) dfs(i);
        }
        cout << cnt << "\n";
    }
    return 0;
}
