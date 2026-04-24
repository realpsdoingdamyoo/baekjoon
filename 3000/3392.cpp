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

const ll w=30303, X=17;

ll n;
V<pii> v[w][2];
vpii seg(1<<X+1);
vi sz(1<<X+1);

void up(ll p){
    if(p==0) return;

    seg[p][0]=max(seg[p][0]*!!seg[p][1], seg[p<<1][0]+seg[p<<1|1][0]);
    up(p>>1);
}

void P(ll p){
    seg[p][0]=sz[p];
    seg[p][1]++;
    up(p>>1);
}

void M(ll p){
    seg[p][1]--;
    if(seg[p][1]) seg[p][0]=sz[p];
    else if(p<(1<<X)) seg[p][0]=seg[p<<1][0]+seg[p<<1|1][0];
    else seg[p][0]=0;
    up(p>>1);
}

void updatep(ll s, ll e){
    s+=1<<X; e+=1<<X;
    while(s<=e){
        if(s&1) P(s);
        if(~e&1) P(e);
        s=s+1>>1; e=e-1>>1;
    }
}

void updatem(ll s, ll e){
    s+=1<<X; e+=1<<X;
    while(s<=e){
        if(s&1) M(s);
        if(~e&1) M(e);
        s=s+1>>1; e=e-1>>1;
    }
}

ll query(ll p){
    for(pii i : v[p][1]) updatem(i[0], i[1]);
    ll ret=seg[1][0];
    for(pii i : v[p][0]) updatep(i[0], i[1]);

    return ret;
}

int main(){
    fastio;

    forf(i, 0, X+1)
        forf(j, 1<<i, 1<<i+1)
            sz[j]=1<<X-i;

    cin >> n;
    forf(i, 0, n){
        ll a, b, c, d; cin >> a >> c >> b >> d;
        v[a][0].pb({c, d-1});
        v[b+1][1].pb({c, d-1});
    }

    ll ret=0;
    forf(i, 0, w) ret+=query(i);
    cout << ret;

    return 0;
}
