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

int main(){
    fastio;

    while(1){
        ll n, m; cin >> n >> m;
        if(n==0) break;
        ll dp[13][2048]={}, X=(1<<m)-1;
        vi met;

        forf(i, 0, 1<<m-1){
            if((i&(i<<1))==0) met.pb(i|(i<<1));
        }


        dp[0][(1<<m)-1]=1;

        forf(i, 1, n+2){
            forf(j, 0, 1<<m){
                for(ll mt : met){
                    if(j&mt) continue;
                    dp[i][j]+=dp[i-1][X-j-mt];
                }
            }
        }

        cout << dp[n+1][0] << "\n";
    }

    return 0;
}
