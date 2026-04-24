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
ll dirn[8][2]={{1, 2}, {2, 1}, {-1, 2}, {2, -1}, {-2, 1}, {1, -2}, {-1, -2}, {-2, -1}};

ll n, k;
ll v[300005];

pii sum(pii a, pii b){
    return {a[0]+b[0], a[1]+b[1]};
}
pii best(pii a, pii b){
    if(a[0]>b[0]) return a;
    else if(a[0]==b[0] && a[1]<b[1]) return a;
    return b;
}

V<array<pii, 2>> dp(300005);

ll alien(ll pen){
    dp[0][0]={0, 0};
    dp[0][1]={-inf*30, 0};

    forf(i, 1, n+1){
        dp[i][0]=best(dp[i-1][0], dp[i-1][1]);
        dp[i][1]=best(sum(dp[i-1][0], {v[i]-pen, 1}), sum(dp[i-1][1], {v[i], 0}));
    }
    return best(dp[n][0], dp[n][1])[1];
}

int main() {
    fastio;

    cin >> n >> k;
    forf(i, 1, n+1) cin >> v[i];

    ll s=0, e=inf*30;
    while(s<e){
        ll m=(s+e)/2;
        if(alien(m)<=k) e=m;
        else s=m+1;
    }
    alien(e);

    cout << best(dp[n][0], dp[n][1])[0]+e*k;

	return 0;
}
