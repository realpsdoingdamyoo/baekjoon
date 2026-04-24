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

ll n, t;
vi u;

ll tfind(ll d, ll x){
    vi v=u;
    ll ret=0;

    PQ<ll, vi, greater<ll>> pq, dpq;
    forf(i, 0, n) pq.push(v[i]+i*d);

    ll lb=inf;
    forf(i, 0, n){
        dpq.push(v[i]+i*d);

        ll vc=min(lb+i*d, pq.top()-i*d);
        vc=min(v[i], vc);

        ret+=v[i]-vc;
        v[i]=vc;
        lb=min(v[i]-i*d, lb);

        if(x) cout << v[i] << " ";

        while(dpq.size() && pq.top()==dpq.top()){
            pq.pop(); dpq.pop();
        }
    }
    return ret;
}

int main(){
    fastio;

    cin >> n >> t;
    forf(i, 0, n){
        ll a; cin >> a;
        u.pb(a);
    }

    ll s=0, e=inf;
    while(s<=e){
        ll m=(s+e)/2;
        if(tfind(m, 0)>t) s=m+1;
        else e=m-1;
    }
    tfind(s, 1);

    return 0;
}
