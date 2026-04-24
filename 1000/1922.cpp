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

vi team;
ll n;

bool tmst(ll s, ll e){
    ll cnt=0;
    forf(i, 0, n){
        if(team[i]==s) team[i]=e;
        cnt+=(team[i]==e);
    }
    return cnt==n;
}

int main() {
    fastio;

    ll m; cin >> n >> m;
    ll cst=0; team.resize(n);
    PQ<tii> pq;
    repeat(m){
        ll a, b, c; cin >> a >> b >> c;
        pq.push({-c, a-1, b-1});
    }
    forf(i, 0, n) team[i]=i;

    while(pq.size()){
        tii x=pq.top(); pq.pop();
        if(team[x[1]]!=team[x[2]]){
            cst-=x[0];
            if(tmst(team[x[1]], team[x[2]])) break;
        }
    }
    cout << cst;

    return 0;
}
