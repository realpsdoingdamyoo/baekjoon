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

ll pct(ll x){
    ll s=0;
    while(x){s+=x&1; x>>=1;}
    return s;
}

int main(){
    fastio;

    ll n; cin >> n;
    vi v(n);
    forf(i, 0, n){
        forf(j, 0, n){
            ll a; cin >> a;
            v[i]=(v[i]<<1)|a;
        }
    }

    vi u;
    ll ret=inf;

    forf(b, 0, 1<<n){
        u=v;
        ll s=0;
        ll x=((b<<1)^b^(b>>1))&((1<<n)-1);
        s+=pct(b); u[0]^=x; u[1]^=b;

        forf(i, 1, n){
            s+=pct(u[i-1]);
            ll x=((u[i-1]<<1)^u[i-1]^(u[i-1]>>1))&((1<<n)-1);
            u[i]^=x;
            if(i<n-1) u[i+1]^=u[i-1];
            u[i-1]=0;
        }
        if(u[n-1]==0) ret=min(ret, s);
    }
    if(ret==inf) cout << -1;
    else cout << ret;

    return 0;
}
