#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef array<ll, 2> pii;
typedef vector<pii> vpii;
typedef double lf;
typedef priority_queue<ll> pqi;
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
const double pi=acos(-1), eu=2.718281828459;
ll gcd(ll a, ll b){return b?gcd(b, a%b):a;}

typedef array<lf, 3> tff;

lf dst(tff a, tff b){
    return sqrt(pow(a[0]-b[0], 2)+pow(a[1]-b[1], 2)+pow(a[2]-b[2], 2));
}

int main() {
    fastio;
    while(1){
    ll n; cin >> n; if(!n) break;
    vector<tff> v(n); tff c;
    forf(i, 0, 3*n) cin >> v[i/3][i%3];
    forf(i, 0, n){c[0]+=v[i][0]; c[1]+=v[i][1]; c[2]+=v[i][2];}
    c[0]/=n; c[1]/=n; c[2]/=n;
    lf err=10;
    
    while(1){
        ll ft=0; lf fd=0;
        forf(i, 0, n){
            if(fd<dst(c, v[i])){fd=dst(c, v[i]); ft=i;}
        }
        
        if(err<0.000001){
            printf("%.5lf\n", fd);
            break;
        }
        
        lf d[3];
        forf(i, 0, 3) d[i]=v[ft][i]-c[i];
        lf D=sqrt(d[0]*d[0]+d[1]*d[1]+d[2]*d[2]);
        if(D==0){
            printf("0.00000\n");
            break;
        }
        d[0]/=D; d[1]/=D; d[2]/=D;
        d[0]*=err; d[1]*=err; d[2]*=err;
        c[0]+=d[0]; c[1]+=d[1]; c[2]+=d[2];
        
        err*=0.999;
    }
    }

    return 0;
}
