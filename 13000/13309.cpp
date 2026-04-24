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

ll n, q, cnt;
vi par(202020), bb[202020], dep(202020);
vpii se(202020);

const ll X=18;
vi seg(1<<X+1);

void dfs(ll p, ll d){
    dep[p]=d;
    for(ll i : bb[p]) dfs(i, d+1);
}

void euler(ll p){
    se[p][0]=++cnt;
    for(ll i : bb[p]) euler(i);
    se[p][1]=cnt;
}

ll deep(ll a, ll b){
    if(dep[a]<dep[b]) return b;
    return a;
}

void update(ll a, ll p){
    ll s=se[a][0]+(1<<X), e=se[a][1]+(1<<X);
    while(s<=e){
        if(s%2==1) seg[s]=deep(seg[s], p); s=(s+1)/2;
        if(e%2==0) seg[e]=deep(seg[e], p); e=(e-1)/2;
    }
}

ll unionfind(ll p){
    ll u=1; p=se[p][0]+(1<<X);
    while(p){
        if(seg[p]==u) continue;
        if(dep[seg[p]]>dep[u]) u=seg[p];
        p/=2;
    }
    return u;
}

int main(){
    fastio;

    cin >> n >> q;
    forf(i, 2, n+1){
        cin >> par[i];
        bb[par[i]].pb(i);
    }
    euler(1); dfs(1, 0);
    update(1, 1);

    forf(i, 2, q+2){
        ll b, c, d; cin >> b >> c >> d;
        if(d==0){
            ll bu=unionfind(b);
            ll cu=unionfind(c);
            if(bu==cu) cout << "YES\n";
            else cout << "NO\n";
        }
        else{
            ll bu=unionfind(b);
            ll cu=unionfind(c);
            if(bu==cu){
                cout << "YES\n";
                update(b, b);
            }
            else{
                cout << "NO\n";
                update(c, c);
            }
        }
    }

    return 0;
}
