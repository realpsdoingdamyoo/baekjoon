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

ll dp[100][20000];
ll pw[100];

int main(){
    fastio;

    ll t; cin >> t;
    while(t--){
        ll n, X=100;
        cin >> n;

        pw[0]=1;
        dp[0][0]=dp[0][1]=1;

        forf(i, 1, X){
            pw[i]=pw[i-1]*10%n;
            forf(j, 0, n){
                dp[i][j]=dp[i-1][j]+dp[i-1][(j-pw[i]+n)%n];
                dp[i][j]=min(dp[i][j], 2LL);
            }
        }
        ll x=0, chk=0;
        forb(i, X, 0){
            if(i==0){
                cout << x;
            }
            else if(dp[i-1][x]==2 || dp[i-1][(x-pw[i]+n)%n]==0){
                if(chk) cout << "0";
            }
            else{
                cout << "1";
                x=(x-pw[i]+n)%n;
                chk=1;
            }
        }
        cout << "\n";
    }

    return 0;
}
