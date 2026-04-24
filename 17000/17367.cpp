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

lf dp[1005][6][6][6];

lf R(ll a, ll b, ll c){
    a++; b++; c++;
    if(a==b && b==c) return 10000+1000*a;
    if(a==b|| b==c) return 1000+100*b;
    if(a==c) return 1000+100*a;
    return 100*max(a, max(b, c));
}

int main(){
    fastio;

    ll n; cin >> n;
    forf(i, 0, 6) forf(j, 0, 6) forf(k, 0, 6) dp[0][i][j][k]=R(i, j, k);

    forf(x, 1, n-2){
        forf(i, 0, 6) forf(j, 0, 6) forf(k, 0, 6){
            lf nxt=0;
            forf(l, 0, 6) nxt+=dp[x-1][j][k][l];
            dp[x][i][j][k]=max(R(i, j, k), nxt/6);
        }
    }

    lf ret=0;
    forf(i, 0, 6) forf(j, 0, 6) forf(k, 0, 6) ret+=dp[n-3][i][j][k];
    cout.precision(13);
    cout << ret/216;

    return 0;
}
