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

    ll n, p; cin >> n;
    vi par(2*n-1); par[2*n-2]=-1;
    V<tii> d;
    vvi lnk(2*n-1); p=n;

    forf(i, 0, n-1){
        ll a; cin >> a;
        d.pb({a, i, i+1});
    }

    while(d.size()){
        ll r=0;
        forf(i, 0, d.size()){
            if(d[i][0]==2){
                r=i;
                break;
            }
        }

        lnk[p].pb(d[r][1]);
        lnk[p].pb(d[r][2]);
        par[d[r][1]]=p; par[d[r][2]]=p;

        if(r>0){d[r-1][0]--; d[r-1][2]=p;}
        if(r<d.size()-1){d[r+1][0]--; d[r+1][1]=p;}
        d.erase(d.begin()+r);
        p++;
    }

    ll a, b; cin >> a >> b;
    a--; b--;

    ll ans=0;
    while(a>=0){
        ll B=b, bans=0;
        while(B>=0){
            if(B==a) break;
            B=par[B];
            bans++;
        }
        if(B>=0){
            cout << ans+bans;
            return 0;
        }

        a=par[a];
        ans++;
    }

    return 0;
}
