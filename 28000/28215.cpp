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

ll n, k;
pii loc[50];
vi sel;
ll ans=inf;

ll dist(pii a, pii b){
    return abs(a[0]-b[0])+abs(a[1]-b[1]);
}

void simulate(){

    ll _s=0;
    forf(i, 0, n){
        ll _md=inf;
        forf(j, 0, k)
            _md=min(_md, dist(loc[i], loc[sel[j]]));
        _s=max(_s, _md);
    }
    ans=min(ans, _s);
}

void JG(ll e){
    if(sel.size()==k) simulate();
    else{
        forf(i, e+1, n){
            sel.pb(i);
            JG(i);
            sel.pop_back();
        }
    }
}

int main(){
    fastio;

    cin >> n >> k;
    forf(i, 0, n) cin >> loc[i][0] >> loc[i][1];
    JG(-1);
    cout << ans;

    return 0;
}
