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
const ll inf=2147483647, linf=140737488355327;
const double pi=acos(-1), E=2.718281828459;
ll gcd(ll a, ll b){return b?gcd(b, a%b):a;}

void solve(){
    ll n, h; cin >> n >> h;

    vi dp;
    ll s, r=0, a; cin >> s;
    dp.pb(s-h); dp.pb(s+h);

    forf(i, 1, n-1){
        cin >> a;
        r+=abs(a-(s-i*h));
        dp.pb(max(s-i*h, min(s+i*h, a)));
        dp.pb(max(s-i*h, min(s+i*h, a)));
        sortv(dp);
        forf(j, 0, dp.size()/2) dp[j]-=h;
        forf(j, dp.size()/2, dp.size()) dp[j]+=h;
    }

    cin >> a;


    if(abs(a-s)>(n-1)*h){
        cout << "impossible\n";
        return;
    }

    ll m=1-n, e=s-(n-1)*h, l=e;
    forf(i, 0, dp.size()){
        r+=(min(dp[i], a)-l)*m;
        l=min(dp[i], a);
        m++;
    }
    cout << r << "\n";
}


int main(){
    fastio;

    ll t; cin >> t;
    while(t--) solve();

    return 0;
}
