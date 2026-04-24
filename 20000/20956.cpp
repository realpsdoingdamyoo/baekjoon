#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef array<ll, 2> pii;
typedef array<ll, 3> tii;
typedef vector<pii> vpii;
typedef double lf;
typedef string S;
#define V vector
#define PQ priority_queue
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define vcin; for(int i=0; i<n; i++) cin >> v[i];
#define forf(i, s, e) for(ll i=s; i<e; i++)
#define forb(i, s, e) for(ll i=s-1; i>=e; i--)
#define pb push_back
#define sortv(v) sort(v.begin(), v.end())
#define sortc(v, cmp) sort(v.begin(), v.end(), cmp)
#define repeat(n) for(ll not_used_name=0; not_used_name<n; not_used_name++)
#define all(v) v.begin(), v.end()
const ll mod=1e9+7, MOD=998244353;
const ll dir4[4][2]={{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
const ll dir8[8][2]={{0, 1}, {1, 0}, {-1, 0}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
const ll inf=2147483647, linf=9223372036854775807;
const double PI=acos(-1), EU=2.718281828459;
ll gcd(ll a, ll b){return b?gcd(b, a%b):a;}


int main() {
    fastio;

    ll n, m; cin >> n >> m;
    vi v(n); vcin;
    vpii u(n);
    forf(i, 0, n) u.pb({-v[i], i}); sortv(u);
    ll k=1; vi x;
    forf(i, 1, n+1){
        if(i==n || u[i][0]!=u[i-1][0]){x.pb(k); k=0;}
        k++;
    }
    ll mnt=0, cnt=0;
    forf(i, 0, x.size()){
        ll s=cnt, e=cnt+x[i]-1;
        while(s<=e && m--){
            if(mnt==0){
                cout << u[s][1]+1 << "\n";
                mnt^=!(u[s][0]%7);
                s++;
            }
            else{
                cout << u[e][1]+1 << "\n";
                mnt^=!(u[e][0]%7);
                e--;
            }
        }
        cnt+=x[i];
    }

    return 0;
}
