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
    lf s=0;
    forf(i, 0, 3) s+=pow(a[i]-b[i], 2);
    return sqrt(s);
}

int main() {
    fastio;
    
    vector<tff> v(3); vector<lf> d;
    forf(i, 0, 9) cin >> v[i/3][i%3];
    forf(i, 0, 3) d.pb(dst(v[i], v[(i+1)%3]));
    sortv(d);
    if(d[0]*d[0]+d[0]*d[1]+d[1]*d[1]<=d[2]*d[2]){
        cout << d[0]+d[1] << "\n"; return 0;
    }
    
    lf x=d[0], y=d[1], z=d[2];
    
    lf q=(x*x-y*y)/2/z;
    lf h=sqrt(x*x-(z/2+q)*(z/2+q));
    lf a=sqrt(pow(h+sqrt(3)/2*z, 2)+q*q);
    cout.precision(8);
    cout << a << "\n";
    

    return 0;
}
