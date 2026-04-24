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

int main(){
    fastio;

    ll n, m; cin >> n >> m;
    ll a, b; cin >> a >> b;
    if(n>m+1){cout << "-1"; return 0;}
    ll mna=n*(n-1)/2; ll mxa=m*n-mna, lft=b;
    if(mna>a || mxa<a){cout << "-1"; return 0;}
    vi v(n); forf(i, 0, n) v[i]=i, lft-=i;
    //forf(i, 0, n) cout << v[i] << ' '; cout << "\n";

    ll pl=min(m-v[n-1], lft);
    v[n-1]+=pl; lft-=pl;
    forb(i, n-1, 0){
        ll pl=min(v[i+1]-1-v[i], lft);
        v[i]+=pl; lft-=pl;
        //cout << lft << "_";
    }
    forf(i, 0, n){
        forf(j, 0, v[i]) cout << "9 ";
        forf(j, v[i], m) cout << "1 ";
        cout << "\n";
    }

    return 0;
}
