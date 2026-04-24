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
#define all(v) v.begin(), v.end()
const ll mod=1e9+7, MOD=998244353;
const ll dir4[4][2]={{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
const ll dir8[8][2]={{0, 1}, {1, 0}, {-1, 0}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
const ll inf=2147483647, linf=9223372036854775807;
const double pi=acos(-1), E=2.718281828459;
ll gcd(ll a, ll b){return b?gcd(b, a%b):a;}

ll n, q;
vi par(202020), parout(202020), bb[202020];
vi uf(202020), uni[202020];
V<string> ans;
V<tii> qr;

void dfs(ll p, ll u, ll x){
    if(x==1 && parout[p]) return;
    uf[p]=u; uni[u].pb(p);
    for(ll i : bb[p]) dfs(i, u, 1);
}

void unionfind(ll a, ll b){
    a=uf[a]; b=uf[b];
    if(uni[a].size()<uni[b].size()) swap(a, b);

    for(ll i : uni[b]){
        uf[i]=a;
        uni[a].pb(i);
    }
    uni[b].clear();
}

int main(){
    fastio;

    cin >> n >> q; q+=n-1;
    forf(i, 2, n+1){
        cin >> par[i];
        bb[par[i]].pb(i);
    }
    forf(i, 0, q){
        ll a; cin >> a;
        if(a==0){
            ll b; cin >> b;
            qr.pb({0, b, b});
            parout[b]=1;
        }
        else{
            ll b, c; cin >> b >> c;
            qr.pb({1, b, c});
        }
    }

    forf(i, 1, n+1){
        if(uf[i]) continue;
        dfs(i, i, 0);
    }

    while(qr.size()){
        tii e=qr[qr.size()-1]; qr.pop_back();
        if(e[0]==0){
            unionfind(e[1], par[e[1]]);
        }
        else{
            if(uf[e[1]]==uf[e[2]]) ans.pb("YES\n");
            else ans.pb("NO\n");
        }
    }

    reverse(all(ans));
    for(string s : ans) cout << s;

    return 0;
}
