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

ll x[200][200];
string p;

void it(ll s, ll e, ll k){
    ll r=0;
    forf(i, s, s+k) forf(j, e, e+k) r+=x[i][j];
    if(r==0){
        p+="0";
        return;
    }
    if(r==k*k){
        p+="1";
        return;
    }
    p+="(";
    it(s, e, k/2);
    it(s, e+k/2, k/2);
    it(s+k/2, e, k/2);
    it(s+k/2, e+k/2, k/2);
    p+=")";
}

int main(){
    fastio;

    ll n; cin >> n;
    forf(i, 0, n){
        string k; cin >> k;
        forf(j, 0, n) x[i][j]=k[j]-'0';
    }
    it(0, 0, n);
    cout <<p;
    return 0;
}
