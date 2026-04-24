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
#define vcin; for(int i=0; i<v.size(); i++) cin >> v[i];
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

ll n, q;
vi v;

void shuffle(ll a, ll b){
    vi u;
    forf(i, b, n) u.pb(v[i]);
    forf(i, a, b) u.pb(v[i]);
    forf(i, 0, a) u.pb(v[i]);
    v=u;
}

int main() {
    fastio;

    cin >> n; v.resize(n); q=n-2;
    vi u(n); vpii ans;
    forf(i, 0, n) cin >> u[i];
    forf(i, 0, n) v[u[i]-1]=i+1;

    //cout << "\n";
    //forf(i, 0, n) cout << v[i] << " "; cout << "\n";

    while(q--){
        ll lst=v[n-1], lind=n-1;
        ll ind;
        forf(i, 0, n)if(v[i]==v[n-1]%n+1) ind=i;
        while(lind>ind && v[lind]==v[lind-1]%n+1) lind--;
        if(lind==0) continue;
        shuffle(ind, lind); ans.pb({ind, lind});
        //forf(i, 0, n) cout << v[i] << " "; cout << "\n";
    }

    if(v[n-1]!=n){
        ll ind;
        forf(i, 0, n)if(v[i]==1) ind=i;
        shuffle(0, ind); ans.pb({0, ind});
        //forf(i, 0, n) cout << v[i] << " "; cout << "\n";
    }

    cout << ans.size() << "\n";
    for(pii i : ans){
        if(i[0]==0) cout << "2 " << i[1] << "\n";
        else cout << "3 " << i[0] << " " << i[1] << "\n";
    }

    return 0;
 }
