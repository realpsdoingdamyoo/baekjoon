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

int main(){
    fastio;

    ll n; cin >> n;
    vi v(n); vcin;

    ll s=0, e=0;
    forf(i, 0, n){
        if(abs(v[s])>abs(v[i])) s=e=i;
    }

    pii ret={inf, inf};
    while(0<=s && e<=n-1){
        if(s==0) e++;
        else if(e==n-1) s--;
        else{
            if(abs(v[s-1]+v[e])<abs(v[s]+v[e+1])) s--;
            else e++;
        }
        if(s<0 || e>=n) break;
        if(abs(ret[0]+ret[1])>abs(v[s]+v[e])) ret={v[s], v[e]};
    }

    cout << ret[0] << " " << ret[1];

    return 0;
}
