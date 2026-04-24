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
const vpii dir4={{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
const vpii dir8={{0, 1}, {1, 0}, {-1, 0}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
const ll inf=2147483647, linf=9223372036854775807;
const double pi=acos(-1), E=2.718281828459;
ll gcd(ll a, ll b){return b?gcd(b, a%b):a;}
#define cf; cout.flush();


int main() {
    fastio;

    ll n, m; cin >> n >> m;
    if(n==m){cout << "0"; return 0;}

    queue<pair<ll, string>> q;
    q.push({n, ""});
    forf(rpd, 0, 50000){
        if(rpd==1 && n!=1) q.push({1, "/"});
        auto qq=q.front(); q.pop();
        if(qq.first==m){cout << qq.second; return 0;}

        if(qq.first<=4e4) q.push({qq.first*qq.first, qq.second+"*"});
        if(qq.first<=5e8) q.push({qq.first*2, qq.second+"+"});

    }
    cout << "-1";

    return 0;
}
