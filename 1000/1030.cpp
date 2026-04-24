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
#define forf(i, s, e) for(int i=s; i<e; i++)
#define forb(i, s, e) for(int i=s-1; i>=e; i--)
#define pb push_back
#define sortv(v) sort(v.begin(), v.end())
#define sortc(v, cmp) sort(v.begin(), v.end(), cmp)
#define repeat(n) for(int not_used_name=0; not_used_name<n; not_used_name++)
const int mod=1e9+7, MOD=998244353;
const int dir4[4][2]={{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
const int dir8[8][2]={{0, 1}, {1, 0}, {-1, 0}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
const ll inf=2147483647, linf=9223372036854775807;
const double pi=acos(-1), eu=2.718281828459;
ll gcd(ll a, ll b){return b?gcd(b, a%b):a;}

bool colored(ll s, ll n, ll k, ll r, ll c){
    while(s){
        ll px=pow(n, --s);
        if((n-k)/2<=r/px && r/px<n-(n-k)/2 && (n-k)/2<=c/px && c/px<n-(n-k)/2) return true;
        r%=px; c%=px;
    }
    return false;
}

int main(){
    fastio;

    ll s, n, k, r1, r2, c1, c2;
    cin >> s >> n >> k >> r1 >> r2 >> c1 >> c2;
    forf(i, r1, r2+1){
        forf(j, c1, c2+1) cout << colored(s, n, k, i, j);
        cout << "\n";
    }

    return 0;
}
