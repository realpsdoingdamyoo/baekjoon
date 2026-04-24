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

ll n;
V<vpii> lnk;
vi trsz;
ll D;

ll _dfs(ll pnt, ll pre){
    trsz[pnt]=1;
    for(pii i : lnk[pnt]){
        if(i[0]!=pre) trsz[pnt]+=_dfs(i[0], pnt);
    }
    return trsz[pnt];
}

void _dfsd(ll pnt, ll pre, ll dist){
    D+=dist;
    for(pii i : lnk[pnt]){
        if(i[0]!=pre) _dfsd(i[0], pnt, dist+i[1]);
    }
}

bool solve(){
    lnk.clear(); D=0;
    cin >> n; if(n==0) return 0;
    lnk.resize(n);
    trsz.resize(n);
    forf(i, 1, n){
        ll a, b, c; cin >> a >> b >> c;
        lnk[a].pb({b, c}); lnk[b].pb({a, c});
    }
    _dfs(0, -1);


    ll pnt=0, prev=-1;
    while(1){
        bool c=0;
        for(pii i : lnk[pnt]){
            if(i[0]!=prev && trsz[i[0]]>n/2){
                prev=pnt; pnt=i[0]; c=1; break;
            }
        }
        if(!c) break;
    }

    _dfsd(pnt, -1, 0);
    cout << D << "\n";
    return 1;
}

int main(){
    fastio;

    while(solve()){}



    return 0;
}
