/*******************************
** coded by realpsdoingdamyoo **
*******************************/

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
#define sortc(v, cmp) sort(v.begin(), v.end(), cmp)
#define repeat(n) for(int not_used_name=0; not_used_name<n; not_used_name++)
const int mod=1e9+7, MOD=998244353;
const int dir4[4][2]={{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
const int dir8[8][2]={{0, 1}, {1, 0}, {-1, 0}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
const ll inf=2147483647, linf=9223372036854775807;
ll gcd(ll a, ll b){return b?gcd(b, a%b):a;}

vector<double> dp;
vi v;
double ans;
ll n;

double s(ll a, ll b, ll c){
    double p=(a+b+c)/2.0;
    if(p-a<0 || p-b<0 || p-c<0) return 0;
    return sqrt(p*(p-a)*(p-b)*(p-c));
}

double dpf(ll bit){
    //if(bit==0 || dp[bit]) return dp[bit];

    vi ones;
    forf(i, 0, n){
        if(bit&(1<<i)) ones.push_back(i);
    }

    if(ones.size()%3) return 0;
    forf(i, 0, ones.size()){
        forf(j, i+1, ones.size()){
            forf(k, j+1, ones.size()){
                dp[bit]=max(dp[bit], dp[bit-(1<<ones[i])-(1<<ones[j])-(1<<ones[k])]+s(v[ones[i]], v[ones[j]], v[ones[k]]));
            }
        }
    }
    ans=max(ans, dp[bit]);
    return dp[bit];
}

int main() {
    fastio;

    cin >> n; dp.resize(1<<n);
    v.resize(n); vcin;
    forf(i, 0, 1<<n) double x=dpf(i);
    printf("%.9lf", ans);

    return 0;
}
