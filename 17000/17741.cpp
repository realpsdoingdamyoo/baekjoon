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

int main(){
    //fastio;

    ll n; cin >> n;
    vpii v(n), u;
    vi ps;
    forf(i, 0, n) cin >> v[i][0] >> v[i][1];
    forf(i, 0, n) v[i][0]--;
    sortv(v);

    forf(i, 0, n){
        if(v[i][0]==-1) ps.pb(v[i][1]);
        else u.pb(v[i]);
    }
    ll N=ps.size(), M=u.size();
    reverse(all(ps));

    vi bag(N+1), nbag(N+1);
    forf(i, 1, N+1) bag[i]=-inf*20;

    forf(i, 0, M){
        nbag=bag;

        forb(j, N+1, 0){
            nbag[min(N, j+u[i][0])]=max(nbag[min(N, j+u[i][0])], bag[j]+u[i][1]);
        }
        bag=nbag;
    }
    forb(j, N, 0) bag[j]=max(bag[j], bag[j+1]);

    if(N==0){cout << bag[0]; return 0;}
    ll vs=0, ans=bag[0];
    forf(i, 0, N+1){
        vs+=ps[i];
        ans=max(ans, vs+bag[i]);
    }
    cout << ans;

    return 0;
}
