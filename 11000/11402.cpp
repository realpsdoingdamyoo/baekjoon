#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef array<ll, 2> pii;
typedef vector<pii> vpii;
typedef double lf;
typedef priority_queue<ll> pqi;
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define vcin; for(int i=0; i<n; i++) cin >> v[i];
#define forf(i, s, e) for(int i=s; i<e; i++)
#define forb(i, s, e) for(int i=s-1; i>=e; i--)
#define pb push_back
#define sortv(v) sort(v.begin(), v.end())
#define sortc(v, cmp) sort(v.begin(), v.end(), cmp)
#define repeat(n) for(int not_used_name=0; not_used_name<n; not_used_name++)
#define all(v) v.begin(), v.end()
const int mod=1e9+7, MOD=998244353;
const int dir4[4][2]={{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
const int dir8[8][2]={{0, 1}, {1, 0}, {-1, 0}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
const ll inf=2147483647, linf=9223372036854775807;
const double pi=acos(-1), eu=2.718281828459;
ll gcd(ll a, ll b){return b?gcd(b, a%b):a;}

vi fac;

pii fact(ll n, ll m){
    pii p={1, 0};
    while(n){
        ll q=n/m;
        p[0]=(m+1-q%2*2)*p[0]%m;
        p[1]+=q;
        p[0]=p[0]*fac[n%m]%m;
        n=q;
    }
    return p;
}

ll my(ll x, ll m){
    ll z=m-2, r=1;
    while(z){
        if(z%2) r=r*x%m;
        z/=2; x=x*x%m;
    }
    return r;
}

int main() {
    fastio;

    ll n, k, m; cin >> n >> k >> m;
    fac.resize(m); fac[0]=1;
    forf(i, 1, m) fac[i]=fac[i-1]*i%m;

    pii pn=fact(n, m), pk=fact(k, m), pnk=fact(n-k, m);
    if(pn[1]-pk[1]-pnk[1]) cout << "0\n";
    else{
        cout << pn[0]*my(pk[0], m)*my(pnk[0], m)%m << "\n";
    }

    return 0;
}
