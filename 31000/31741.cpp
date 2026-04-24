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
#define cf cout.flush()

int main(){
    fastio;

    ll n, s, e, ans=inf; cin >> n >> s >> e;
    vpii v(n);
    forf(i, 0, n) cin >> v[i][0] >> v[i][1];
    sortv(v);

    vi f, b;

    forf(i, 0, n){
        if(v[i][0]<=s && e<=v[i][1]){
            cout << "0";
            return 0;
        }
        if(v[i][0]<=s) f.pb(v[i][1]);
        if(e<=v[i][1]) b.pb(v[i][0]);
    }

    if(f.size()*b.size()==0){
        cout << "-1";
        return 0;
    }

    sortv(f); sortv(b);

    for(ll i : f){
        if(b.front()>i) continue;
        ll j=*prev(upper_bound(all(b), i));
        ans=min(ans, i-j);
    }

    for(pii i : v){
        if(f.back()<i[0]) continue;
        if(b.front()>i[1]) continue;
        ll jl=*lower_bound(all(f), i[0]);
        ll jr=*prev(upper_bound(all(b), i[1]));
        ans=min(ans, i[1]-jr+jl-i[0]);
    }
    if(ans==inf) cout << "-1";
    else cout << ans;


    return 0;
}
