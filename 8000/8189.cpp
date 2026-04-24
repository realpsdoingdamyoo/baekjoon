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

vi v;
ll n, m, ans, mx, cen;
vi arr(1010101), val(1010101);
string s, t;

int main(){
    fastio;

    ll a, b, c, d, j, k, p, q;
    cin >> n >> s;
    forf(i, 1, n+1) arr[i*2-1]=s[i-1]-'0';
    n=2*n-1;

    for(ll i=2; i<n; i+=2){
        if(i<=mx) val[i]=min(val[2*cen-i], mx-i);
        else val[i]=-1;

        while(arr[i-val[i]-2]+arr[i+val[i]+2]==1 && 1<=i-val[i]-2 &&i+val[i]+2<=n) val[i]+=2;

        if(mx<i+val[i]){mx=i+val[i]; cen=i;}
        ans+=(val[i]+1)/2;
    }
    cout << ans;


}
