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
const double PI=acos(-1), EU=2.718281828459;
ll gcd(ll a, ll b){return b?gcd(b, a%b):a;}

vvi lnk;
vi vsd;
ll r;

void dfs(ll x){
    if(vsd[x]) return;
    vsd[x]=1; r++;
    for(ll i : lnk[x]) dfs(i);
}

int main() {
    fastio;

    ll n, c=0; cin >> n;
    lnk.resize(n); vsd.resize(n);
    forf(i, 0, n){
        string s; cin >> s;
        forf(j, 0, n){
            if(s[j]=='Y') {lnk[i].pb(j); c++;}
        }
    }
    ll t=0;
    forf(i, 0, n){
        if(!vsd[i]){
                r=0;
            dfs(i+0*t++);
            if(r==1 && n>1){cout << "-1\n"; return 0;}
        }
    }
    if(c/2>=n-1) cout << t-1 << "\n";
    else cout << "-1\n";

    return 0;
}
