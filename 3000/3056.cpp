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


ll n;
vector<double> bdp;
vector<bool> bdpvsd;
vvi v;

double bdpf(ll bit){
    if(bdpvsd[bit]) return bdp[bit];
    bdpvsd[bit]=1;

    ll s=0;
    forf(i, 0, n){
        s+=!!(bit&(1<<i));
    }

    forf(i, 0, n){
        if(bit&(1<<i)){
            bdp[bit]=max(bdpf(bit-(1<<i))*v[s-1][i]/100, bdp[bit]);
        }
    }
    return bdp[bit];
}

int main() {
    fastio;

    cin >> n;
    bdp.resize(1<<n); v.resize(n); bdpvsd.resize(1<<n);
    forf(i, 0, n){
        v[i].resize(n);
        forf(j, 0, n) cin >> v[i][j];
    }
    bdp[0]=1; bdpvsd[0]=1;
    printf("%.9lf", bdpf((1<<n)-1)*100);
    return 0;
}
