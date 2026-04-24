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

ll n, q;
vi par;
V<set<ll>> st;
vi un;
vvi uf;
vpii qr;

void ingcha(ll a, ll b){
    if(uf[a].size()<uf[b].size()) swap(a, b);

    while(st[b].size()){
        ll f=*st[b].begin();
        st[b].erase(st[b].begin());
        st[a].insert(f);
    }

    for(ll i : uf[b]){
        uf[a].pb(i);
        un[i]=a;
    }
    uf[b].clear();
}

int main(){
    //fastio;

    cin >> n >> q; q+=n-1;
    par.resize(n);
    st.resize(n);
    forf(i, 0, n){un.pb(i); uf.pb({i});}

    forf(i, 1, n){
        cin >> par[i];
        par[i]--;
    }

    forf(i, 0, n){
        ll a; cin >> a;
        st[i].insert(a);
    }

    while(q--){
        ll a, b; cin >> a >> b;
        qr.pb({a, b-1});
    }
    reverse(all(qr));
    vi ans;

    for(pii i : qr){
        if(i[0]==1) ingcha(un[i[1]], un[par[i[1]]]);
        else ans.pb(st[un[i[1]]].size());
    }

    reverse(all(ans));
    for(ll i : ans) cout << i << "\n";

    return 0;
}
