/*
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


    return 0;
}
*/


#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

vector<array<int, 2>> xy(100);
int n;

double width(int p, int q){
    int a=xy[p][1]-xy[q][1], b=xy[q][0]-xy[p][0];
    int c=-a*xy[p][0]-b*xy[p][1];
    int buho=0, m=0;
    for(int i=0; i<n; i++){
        int d=a*xy[i][0]+b*xy[i][1]+c;
        if(d==0) continue;
        if(d*buho<0) return 1000000.0;
        buho=d/abs(d);
        m=max(m, abs(d));
    }
    return m/sqrt(a*a+b*b);
}

int main(){
    fastio;
    cin >> n;
    for(int i=0; i<n; i++) cin >> xy[i][0] >> xy[i][1];
    double m=1000000;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            m=min(width(i, j), m);
        }
    }
    printf("%.9lf", m);
    return 0;
}
