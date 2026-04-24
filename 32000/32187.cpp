#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef array<ll, 2> pii;
typedef array<ll, 3> tii;
typedef vector<pii> vpii;
typedef double lf;
typedef priority_queue<ll> pqi;
#define V vector
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define vcin; for(int i=0; i<n; i++) cin >> v[i];
#define forf(i, s, e) for(ll i=s; i<e; i++)
#define forb(i, s, e) for(ll i=s-1; i>=e; i--)
#define pb push_back
#define sortv(v) sort(v.begin(), v.end())
#define sortc(v, cmp) sort(v.begin(), v.end(), cmp)
#define repeat(n) for(ll not_used_name=0; not_used_name<n; not_used_name++)
#define all(v) v.begin(), v.end()
const int mod=1e9+7, MOD=998244353;
const int dir4[4][2]={{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
const int dir8[8][2]={{0, 1}, {1, 0}, {-1, 0}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
const ll inf=2147483647, linf=9223372036854775807;
const double PI=acos(-1), EU=2.718281828459;
ll gcd(ll a, ll b){return b?gcd(b, a%b):a;}


int main() {
    fastio;

    ll n, m, s=0; cin >> n >> m;
    V<vpii> v(n);
    forf(i, 0, m){
        ll x; cin >> x;
        forf(j, 0, x){
            ll a, b; cin >> a >> b;
            v[a-1].pb({i, b});
        }
    }
    /*
    forf(i, 0, n){
        forf(j, 0, v[i].size()){
            cout << v[i][j][0] << "_" << v[i][j][1] << " ";
        }
        cout << "\n";
    }
    */
    forf(i, 0, n){
        if(v[i].size()==0) continue;
        vpii dp(v[i].size());
        dp[0][0]=0; dp[0][1]=v[i][0][1];
        forf(j, 1, v[i].size()){
            dp[j][0]=max(dp[j-1][0], dp[j-1][1]);
            dp[j][1]=dp[j-1][0]+v[i][j][1];
            if(v[i][j][0]-v[i][j-1][0]!=1) dp[j][1]=max(dp[j][1], dp[j-1][1]+v[i][j][1]);
        }
        s+=max(dp[v[i].size()-1][0], dp[v[i].size()-1][1]);
        //cout << max(dp[v[i].size()-1][0], dp[v[i].size()-1][1]) << " ";
    }

    cout << s;

    return 0;
}
