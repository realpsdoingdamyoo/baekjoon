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
#define cf; cout.flush();

int main() {
    fastio;

    ll f[10], rf[10];
    forf(i, 0, 10){
        cin >> f[i]; rf[f[i]]=i;
    }
    ll a, b; cin >> a >> b;
    ll ra=0, rb=0, t, r=0;
    t=1; while(a){
        ra+=t*rf[a%10];
        t*=10; a/=10;
    }
    t=1; while(b){
        rb+=t*rf[b%10];
        t*=10; b/=10;
    }
    ll _=ra+rb;
    t=1; while(_){
        r+=t*f[_%10];
        t*=10; _/=10;
    }
    cout << r;

    return 0;
 }
