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

V<string> mj;
ll n;

bool tst(ll r){
    map<string, ll> mp;
    forf(i, 0, r) if(++mp[mj[i]]==5) return true;
    forf(i, r, n){
        --mp[mj[i-r]];
        if(++mp[mj[i]]==5) return true;
    }
    return false;
}

int main(){
    fastio;

    cin >> n;
    forf(i, 0, n){string s; cin >> s; mj.pb(s);}
    ll s=0, e=n;
    while(s<=e){
        ll m=(s+e)/2;
        if(tst(m)) e=m-1;
        else s=m+1;
    }
    if(s==n+1) cout << "-1";
    else cout << s;


    return 0;
}
