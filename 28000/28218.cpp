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


int main(){
    fastio;

    ll n, m, k;
    cin >> n >> m >> k;
    string s[301]={};
    forf(i, 0, n) cin >> s[i];
    ll dp[301][301]={}; dp[n-1][m-1]=1;
    forb(i, n, 0){
        forb(j, m, 0){
            dp[i][j]=1;
            if(i+j==n+m-2) continue;
            if(s[i][j]=='#'){dp[i][j]=0; continue;}

            forf(l, 1, min(min(n-1-i, m-1-j), k)+1){
                if(dp[i+l][j+l]) dp[i][j]=0;
            }
            if(i!=n-1) dp[i][j]=dp[i][j]&&!dp[i+1][j];
            if(j!=m-1) dp[i][j]=dp[i][j]&&!dp[i][j+1];
        }
    }

    /*forf(i, 0, n){
        forf(j, 0, m) cout << dp[i][j];
        cout << '\n';
    }*/

    ll q; cin >> q;
    forf(i, 0, q){
        ll a, b; cin >> a >> b;
        cout << (dp[a-1][b-1]==0?"First\n":"Second\n");
    }


    return 0;
}

/*
3 4 2
....
....
....
1
3 2
*/
