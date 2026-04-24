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

    ll n; cin >> n;
    vi v(n), u; vcin; sortv(v);
    u.pb(v[0]);

    if(v[0]==v[1]){
        cout << "No";
        return 0;
    }

    ll pe=v[1], pd=v[1]-v[0], qe=v[0], qd=0;

    forf(i, 2, n){
        if(pe+pd==v[i]) pe+=pd;
        else u.pb(v[i]);
    }


    forf(i, 0, u.size()-1) qd=gcd(qd, u[i+1]-u[i]);
    reverse(all(u));
    while((pe-u[0])%pd==0 && pe>u[0]) pe-=pd;

    forf(i, 0, u.size()-1){
        if(u[i]-u[i+1]==qd) continue;
        while(u[i]-pe==qd && pe>u[i+1]){
            u[i]=pe; pe-=pd;
        }
        if(u[i]!=u[i+1]+qd){
            cout << "No";
            return 0;
        }
    }

    cout << "Yes";

    return 0;
}
