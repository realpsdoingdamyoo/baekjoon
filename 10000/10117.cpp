#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef array<ll, 2> pii;
typedef array<ll, 3> tii;
typedef vector<pii> vpii;
typedef double lf;
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

vvi v;

int main(){
    fastio;

    vi _v={0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1};
    do{
        v.pb(_v);
    }while(next_permutation(all(_v)));

    ll t; cin >> t;
    if(t==1){
        ll n; cin >> n; cin >> n;
        while(n--){
            ll a, b, r=0; cin >> a >> b;
            forf(i, 0, 12) if(v[a][i] && !v[b][i]) r=i;
            cout << r+1 << "\n";
        }
    }
    else{
        ll n; cin >> n; cin >> n;
        while(n--){
            ll a, b; cin >> a >> b;
            if(!v[a][b-1]) cout << "no\n";
            else cout << "yes\n";
        }
    }


    return 0;
}
