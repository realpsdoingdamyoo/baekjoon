#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef array<ll, 2> pii;
typedef vector<pii> vpii;
typedef priority_queue<ll> pqi;
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define vcin; for(int i=0; i<n; i++) cin >> v[i];
#define forf(i, s, e) for(int i=s; i<e; i++)
#define forb(i, s, e) for(int i=s-1; i>=e; i--)
#define sortv(v) sort(v.begin(), v.end())
#define sortc(v, c) sort(v.begin(), v.end(), c)
#define repeat(n) for(int not_used_name=0; not_used_name<n; not_used_name++)
const int mod=1e9+7, MOD=998244353;
const int dir4[4][2]={{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
const int dir8[8][2]={{0, 1}, {1, 0}, {-1, 0}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
const ll inf=2147483647, linf=9223372036854775807;
ll gcd(ll a, ll b){return b?gcd(b, a%b):a;}
bool issq(ll x){return (ll)sqrt(x)*(ll)sqrt(x)==x;}


int main(){
    fastio;
    
    ll n; cin >> n; n*=n;
    vi v1(n), v2(n); vpii u(n);
    repeat(n-1) forf(i, 0, n) cin >> v1[i];
    forf(i, 0, n) cin >> v2[i];
    forf(i, 0, n) u[v1[i]-1]={v2[i]-1, i};
    vi vsd(n);
    
    ll mnmx=0;
    forf(i, 0, n){
        ll j=u[i][0], mn=u[i][1];
        while(j-i){
            mn=min(mn, u[j][1]);
            j=u[j][0];
        }
        mnmx=max(mn, mnmx);
    }
    cout << n*(n-2)+mnmx+1;
    return 0;
}
