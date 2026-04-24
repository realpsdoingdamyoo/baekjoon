#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
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

ll n, mx;
vvi v, dp;
vector<array<ll, 3>> va;

void dpf(ll x, ll y){
    dp[x][y]=1;
    if(x>0 && v[x-1][y]<v[x][y]) dp[x][y]=max(dp[x][y], dp[x-1][y]+1);
    if(y>0 && v[x][y-1]<v[x][y]) dp[x][y]=max(dp[x][y], dp[x][y-1]+1);
    if(x<n-1 && v[x+1][y]<v[x][y]) dp[x][y]=max(dp[x][y], dp[x+1][y]+1);
    if(y<n-1 && v[x][y+1]<v[x][y]) dp[x][y]=max(dp[x][y], dp[x][y+1]+1);
    mx=max(mx, dp[x][y]);
}

int main() {
    fastio;

    cin >> n;
    v.resize(n); dp.resize(n);

    forf(i, 0, n){
        v[i].resize(n); dp[i].resize(n);
        forf(j, 0, n){
            cin >> v[i][j];
            va.push_back({v[i][j], i, j});
        }
    }
    sortv(va);

    forf(i, 0, n*n) dpf(va[i][1], va[i][2]);
    cout << mx;

    return 0;
}
