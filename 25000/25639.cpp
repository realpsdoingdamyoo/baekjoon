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

ll n, q;
const ll X=17;
tii seg[1<<X+1];

tii M(tii l, tii r){
    tii s;
    s[0]=min(l[0], r[0]);
    s[1]=max(l[1], r[1]);
    s[2]=max(max(l[2], r[2]), r[1]-l[0]);
    return s;
}

void mrg(ll p){
    if(p==0) return;
    seg[p]=M(seg[p*2], seg[p*2+1]);
    mrg(p/2);
}

void update(ll p, ll x){
    p+=1<<X;
    seg[p]={x, x, 0};
    mrg(p/2);
}

tii Q(ll s, ll e){
    if(s>e) return {inf, -inf, 0};
    tii ret=Q((s+1)/2, (e-1)/2);
    if(s%2==1) ret=M(seg[s], ret);
    if(e%2==0) ret=M(ret, seg[e]);
    return ret;
}

ll query(ll s, ll e){
    tii q=Q(s+(1<<X), e+(1<<X));
    return q[2];
}

int main(){
    fastio;

    cin >> n;
    vi v(n);
    forf(i, 0, n){
        ll a; cin >> a;
        update(i, a);
    }
    forf(i, n, 1<<X){
        seg[i+(1<<X)]={inf, -inf, 0};
    }
    ll q; cin >> q;
    while(q--){
        ll a, b, c;
        cin >> a >> b >> c;
        if(a==1){
            update(b-1, c);
        }
        else{
            cout << query(b-1, c-1) <<"\n";
        }
    }

    return 0;
}
