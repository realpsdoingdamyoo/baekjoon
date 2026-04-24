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

vpii ans;

void hanoi3(ll n, ll a, ll b, ll c){
    if(n==0) return;
    hanoi3(n-1, a, c, b);
    ans.pb({a, c});
    hanoi3(n-1, b, a, c);
}

void hanoi(ll n, ll a, ll b, ll c){
    if(n==0) return;
    if(n==1){
        ans.pb({a, 3});
        return;
    }

    hanoi3(n-2, a, b, c);

    ans.pb({a, b});
    ans.pb({a, 3});
    ans.pb({b, 3});
    hanoi(n-2, c, b, a);
}

int main(){
    fastio;

    ll n;
    cin >> n;

    hanoi(n, 0, 1, 2);

    cout << ans.size() << "\n";
    for(pii i : ans) cout << (char)('A'+i[0]) << " " << (char)('A'+i[1]) <<"\n";


    return 0;
}
