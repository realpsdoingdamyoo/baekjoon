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
const ll inf=2147483647LL*100, linf=9223372036854775807;
const double pi=acos(-1), E=2.718281828459;
ll gcd(ll a, ll b){return b?gcd(b, a%b):a;}
#define cf; cout.flush();

int main(){
    fastio;

    ll n, k; cin >> n >> k;
    V<tii> v(n+1);
    forf(i, 0, n*3) cin >> v[i/3+1][i%3];

    V<V<array<ll, 8>>> dp(n+1);
    forf(i, 0, n+1) dp[i].resize(k+1);
    forf(i, 0, n+1) forf(j, 0, k+1) forf(l, 0, 8) dp[i][j][l]=-inf;
    dp[0][0][7]=0;

    forf(i, 1, n+1){
        forf(j, 0, k+1){
            //0
            if(i>0){
                ll rt=-inf;
                forf(l, 0, 8) rt=max(rt, dp[i-1][j][l]);
                dp[i][j][0]=rt;
            }
            if(j==0) continue;

            //1
            if(i>0){
                ll rt=-inf;
                forf(l, 0, 8) if((l&1)==0) rt=max(rt, dp[i-1][j-1][l]);
                dp[i][j][1]=rt+v[i][0]+v[i-1][0];
            }

            //2
            if(i>0){
                ll rt=-inf;
                forf(l, 0, 8) if((l&2)==0) rt=max(rt, dp[i-1][j-1][l]);
                dp[i][j][2]=rt+v[i][1]+v[i-1][1];
            }

            //4
            if(i>0){
                ll rt=-inf;
                forf(l, 0, 8) if((l&4)==0) rt=max(rt, dp[i-1][j-1][l]);
                dp[i][j][4]=rt+v[i][2]+v[i-1][2];
            }

            //3
            if(i>0 && j>=2){
                ll rt=-inf;
                forf(l, 0, 8) if((l&3)==0) rt=max(rt, dp[i-1][j-2][l]);
                dp[i][j][3]=rt+v[i][0]+v[i-1][0]+v[i][1]+v[i-1][1];
            }
            if(1){
                ll rt=-inf;
                forf(l, 0, 8) rt=max(rt, dp[i-1][j-1][l]);
                dp[i][j][3]=max(dp[i][j][3], rt+v[i][0]+v[i][1]);
            }

            //6
            if(i>0 && j>=2){
                ll rt=-inf;
                forf(l, 0, 8) if((l&6)==0) rt=max(rt, dp[i-1][j-2][l]);
                dp[i][j][6]=rt+v[i][1]+v[i-1][1]+v[i][2]+v[i-1][2];
            }
            if(1){
                ll rt=-inf;
                forf(l, 0, 8) rt=max(rt, dp[i-1][j-1][l]);
                dp[i][j][6]=max(dp[i][j][6], rt+v[i][1]+v[i][2]);
            }

            //5
            if(i>0 && j>=2){
                ll rt=-inf;
                forf(l, 0, 8) if((l&5)==0) rt=max(rt, dp[i-1][j-2][l]);
                dp[i][j][5]=rt+v[i][0]+v[i-1][0]+v[i][2]+v[i-1][2];
            }

            //7
            if(i>0 && j>=2){
                ll rt=-inf;
                forf(l, 0, 8) if((l&4)==0) rt=max(rt, dp[i-1][j-2][l]);
                dp[i][j][7]=rt+v[i][0]+v[i][1]+v[i][2]+v[i-1][2];
            }
            if(i>0 && j>=2){
                ll rt=-inf;
                forf(l, 0, 8) if((l&1)==0) rt=max(rt, dp[i-1][j-2][l]);
                dp[i][j][7]=max(dp[i][j][7], rt+v[i-1][0]+v[i][0]+v[i][1]+v[i][2]);
            }
            if(i>0 && j>=3){
                ll rt=-inf;
                forf(l, 0, 8) if((l&7)==0) rt=max(rt, dp[i-1][j-3][l]);
                dp[i][j][7]=max(dp[i][j][7], rt+v[i-1][0]+v[i][0]+v[i-1][1]+v[i][1]+v[i-1][2]+v[i][2]);
            }
        }

    }

    ll ret=0;
    forf(i, 0, 8) ret=max(ret, dp[n][k][i]);
    cout << ret;

    return 0;
}
