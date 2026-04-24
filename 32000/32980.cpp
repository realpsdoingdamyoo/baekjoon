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
#define vcin; for(int i=0; i<v.size(); i++) cin >> v[i];
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


int main() {
    fastio;

    ll n, cst[400]={}, ans=0; cin >> n;
    V<string> s(n);
    forf(i, 0, n) cin >> s[i];
    cin >> cst['P'] >> cst['C'] >> cst['V'] >> cst['S'] >> cst['G'] >> cst['F'] >> cst['O'];
    forf(i, 0, n){
        char p=s[i][0]; ll e=0;
        for(char c : s[i]){
            if(c!=p) {ans+=cst['O']*s[i].length(); e=1; break;}
        }
        if(!e) ans+=s[i].length()*min(cst['O'], cst[p]);
    }
    cout << ans;

    return 0;
 }
