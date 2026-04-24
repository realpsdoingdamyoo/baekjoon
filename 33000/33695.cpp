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
#define cf cout.flush()

ll n, m;
vi u, p;
vvi d;
vi val;

int main(){
    fastio;

    cin >> n >> m;
    d.resize(n);
    val.resize(n);

    forf(i, 0, m){
        ll a, b; cin >> a >> b;
        a--; b--;
        string s; cin >> s;
        if(s=="U") u.pb(a), u.pb(b);
        else if(s=="P") p.pb(a), p.pb(b);
        else{d[a].pb(b); d[b].pb(a);}
    }

    for(ll i : u) val[i]=2;
    for(ll i : p){
        if(val[i]==2){
            cout <<"0";
            return 0;
        }
        val[i]=3;
    }

    sortv(u);
    u.erase(unique(all(u)), u.end());
    sortv(p);
    p.erase(unique(all(p)), p.end());

    vi q, r;
    for(ll i : u) q.pb(i);
    for(ll i : p) q.pb(i);
    forf(i, 0, n) if(!val[i]) r.pb(i);


    ll ans=1;
    while(q.size() + r.size()){
        if(q.size()==0){
            ll p=r.back();
            q.pb(p); r.pop_back();
            val[p]=2; ans=ans*2%mod;
        }
        ll p=q.back(); q.pop_back();
        for(ll i : d[p]){
            if(val[i]==val[p]){
                cout << "0";
                return 0;
            }
            if(val[i]==0){
                val[i]=5-val[p];
                q.pb(i);
            }
        }
        while(r.size() && val[r.back()]) r.pop_back();
    }

    cout << ans;

    return 0;
}
