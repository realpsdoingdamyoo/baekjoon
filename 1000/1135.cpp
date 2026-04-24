#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef array<ll, 2> pii;
typedef vector<pii> vpii;
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define vcin; for(int i=0; i<n; i++) cin >> v[i];
#define forf(i, s, e) for(int i=s; i<e; i++)
#define forb(i, s, e) for(int i=s-1; i>=e; i--)
#define sortv(v) sort(v.begin(), v.end())
#define repeat(n) for(int not_used_name=0; not_used_name<n; not_used_name++)
const int mod=1e9+7, MOD=998244353;
const int dir4[4][2]={{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
const int dir8[8][2]={{0, 1}, {1, 0}, {-1, 0}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
const ll inf=2147483647, linf=9223372036854775807;
ll gcd(ll a, ll b){return b?gcd(b, a%b):a;}

ll n, k;
vi ss, dp;
vector<vi> bb;

void dpdp(ll i){
    if(bb[i].size()==0){dp[i]=0; return;}
    forf(j, 0, bb[i].size()){
        bb[i][j]=dp[bb[i][j]];
    }
    sortv(bb[i]);
    ll mx=0;
    forf(j, 0, bb[i].size()){
        ll nmx=bb[i][j]+bb[i].size()-1-j;
        mx=max(mx, nmx);
    }
    dp[i]=mx+1;
}

int main(void) {
    fastio;

    cin >> n >> k; bb.resize(n);
    ss.resize(n); dp.resize(n);
    forf(i, 1, n){
        cin >> ss[i];
        bb[ss[i]].push_back(i);
    }
    forb(i, n, 0) dpdp(i);
    cout << dp[0];

    return 0;
}
