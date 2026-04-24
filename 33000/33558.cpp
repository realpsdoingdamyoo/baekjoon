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
#define all(v) v.begin(), v.end()
const ll mod=1e9+7, MOD=998244353;
const ll dir4[4][2]={{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
const ll dir8[8][2]={{0, 1}, {1, 0}, {-1, 0}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
const ll inf=2147483647, linf=9223372036854775807;
const double pi=acos(-1), E=2.718281828459;
ll gcd(ll a, ll b){return b?gcd(b, a%b):a;}

int main(){
    fastio;

    ll n, m, u, v;
    cin >> n >> m >> u >> v;
    
    V<string> s(u);
    forf(i, 0, u) cin >> s[i];
    
    string p; cin >> p;
    
    forf(i, 0, n){
        forf(j, 0, m){
            if(p[0]=='c'){
                cout << s[min(i, u-1)][min(j, v-1)];
            }
            else if(p[0]=='r'){
                cout << s[i%u][j%v];
            }
            else{
                ll x=i%(2*u), y=j%(2*v);
                if(x>=u) x=2*u-1-x;
                if(y>=v) y=2*v-1-y;
                cout << s[x][y];
            }
        }
        cout << "\n";
    }

    return 0;
}
