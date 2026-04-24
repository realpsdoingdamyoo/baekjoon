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

ll n;
V<tii> v;

int main() {
    fastio;
    cin >> n;
    v.resize(n);
    forf(i, 0, 2*n) cin >> v[i/2][i%2];
    forf(i, 0, n) v[i][2]=i+1;

    sortv(v);
    lf mxd=0;
    pii ans={inf, inf}, nans;

    forf(i, 0, n-1){
        ll _d=fabs((v[i][1]-v[i+1][1]+0.0)/(v[i][0]-v[i+1][0]));
        if(mxd<_d) mxd=_d;
    }


    ll prev=0;
    forf(i, 1, n){
        ll _d=fabs((v[prev][1]-v[i][1]+0.0)/(v[prev][0]-v[i][0]));
        nans={min(v[prev][2], v[i][2]), max(v[prev][2], v[i][2])};
        if(mxd==_d){
            if(nans<ans) ans=nans;
            if(v[prev][2]>v[i][2]) prev=i;
        }
        else prev=i;
    }
    cout << ans[0] << " " << ans[1] << "\n";

    return 0;
}
