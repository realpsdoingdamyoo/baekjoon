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
const double pi=acos(-1), E=2.718281828459;
ll gcd(ll a, ll b){return b?gcd(b, a%b):a;}


int main(){
    fastio;

    ll n, a=0; cin >> n;

    if(n<3) {cout << "0\n"; return 0;}


    V<S> v(n); vcin;
    if(n==3){cout << v[0][0] << "\n"; return 0;}
    vvi jr(n);
    forf(i, 0, n) jr[i].resize(n);
    jr[1][1]=v[0][0]-'0';
    forf(i, 2, n-1){
        jr[1][i]=v[0][i-1]-'0'-jr[1][i-1]-jr[1][i-2];
    }
    forf(i, 2, n-1){
        jr[i][1]=v[i-1][0]-'0'-jr[i-1][1]-jr[i-2][1];
    }
    forf(i, 2, n-1){
        jr[n-2][i]=v[n-1][i-1]-'0'-jr[n-2][i-1]-jr[n-2][i-2];
    }
    forf(i, 2, n-1){
        jr[i][n-2]=v[i-1][n-1]-'0'-jr[i-1][n-2]-jr[i-2][n-2];
    }
    forf(i, 0, n){
        forf(j, 0, n) a+=jr[i][j];
    }

    a+=(n-4)*(n-4);

    cout << a << "\n";

    return 0;
}
