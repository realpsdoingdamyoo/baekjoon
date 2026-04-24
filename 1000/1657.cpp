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

ll dp[200][20000];

ll scr(char a, char b){
    if(a>b) swap(a, b);
    if(b=='X') return 0;
    if(a=='A'){
        if(b=='A') return 10;
        if(b=='B') return 8;
        if(b=='C') return 7;
        if(b=='D') return 5;
        return 1;
    }
    if(a=='B'){
        if(b=='B') return 6;
        if(b=='C') return 4;
        if(b=='D') return 3;
        return 1;
    }
    if(a=='C'){
        if(b=='C') return 3;
        if(b=='D') return 2;
        return 1;
    }
    if(a=='D'){
        if(b=='D') return 2;
        return 1;
    }
    return 0;
}

int main(){
    fastio;

    ll n, m; cin >> n >> m;
    V<string> s(n); forf(i, 0, n) cin >> s[i];
    if(n<m){
        forf(i, n, m){
            s.pb("");
            s.back()+="X";
        }
        n=m;
    }
    else{
        forf(i, 0, n){
            forf(j, m, n) s[i]+="X";
        }
    }

    forf(i, 0, 1<<n-1){
        if(i&(i<<1)) continue;
        forf(j, 0, n-1) if(i&(1<<j)) dp[0][i|(i<<1)]+=scr(s[0][j], s[0][j+1]);
    }

    ll X=(1<<n)-1, ans=0;

    forf(i, 1, n*(n-1)+1){
        forf(j, 0, 1<<n){
            if((j&(1<<n-1))==0){
                dp[i][j]=max(dp[i-1][(j<<1)], dp[i-1][(j<<1)+1]);
                //cout << "(" << (j<<1) << " " << dp[i-1][(j<<1)] << ' ' << dp[i-1][(j<<1)+1] << ")";
            }
            else{
                dp[i][j]=dp[i-1][(j<<1)&X]+scr(s[(i-1)/n+1][(i-1)%n], s[(i-1)/n][(i-1)%n]);
                if(i%n!=1 && (j&(1<<n-2))) dp[i][j]=max(dp[i][j], max(dp[i-1][(j<<1)&(X>>1)], dp[i-1][((j<<1)&(X>>1))+1])+scr(s[(i-1)/n+1][(i-1)%n], s[(i-1)/n+1][(i-2)%n]));
            }
            ans=max(ans, dp[i][j]);
            //cout << dp[i][j] << " ";
        }
        //cout << "\n";
    }
    cout << ans;


    return 0;
}
