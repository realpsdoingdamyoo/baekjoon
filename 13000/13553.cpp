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

ll k, _k;
vi v;
V<tii> qr;

bool _cmp(tii a, tii b){
    if(a[0]/k==b[0]/k) return a[1]<b[1];
    return a[0]/k<b[0]/k;
}

const ll X=17;
ll segtree[1<<X];

void update(ll x, ll del){
    while(x<(1<<X)){
        segtree[x]+=del;
        x+=x&-x;
    }
}

ll __sum(ll idx){
    ll ret=0;
    while(idx>0){
        ret+=segtree[idx];
        idx-=idx&-idx;
    }
    return ret;
}

ll _sum(ll s, ll e){
    return __sum(e)-(s?__sum(s-1):0);
}

ll _mos(tii prev, tii q, ll ret){
    forf(i, prev[0], q[0]){
        update(v[i], -1);
        ret-=_sum(max(v[i]-_k, 0LL), min(v[i]+_k, (1LL<<X)-1));
    }
    forf(i, q[0], prev[0]){
        ret+=_sum(max(v[i]-_k, 0LL), min(v[i]+_k, (1LL<<X)-1));
        update(v[i], 1);
    }
    forf(i, prev[1]+1, q[1]+1){
        ret+=_sum(max(v[i]-_k, 0LL), min(v[i]+_k, (1LL<<X)-1));
        update(v[i], 1);
    }
    forf(i, q[1]+1, prev[1]+1){
        update(v[i], -1);
        ret-=_sum(max(v[i]-_k, 0LL), min(v[i]+_k, (1LL<<X)-1));
    }
    return ret;
}


int main(){
    fastio;

    ll n, q; cin >> n >> _k; k=(ll)sqrt(n);
    v.resize(n); vcin;
    cin >> q;
    forf(i, 0, q){
        ll a, b; cin >> a >> b;
        a--; b--;
        qr.pb({a, b, i});
    }
    sortc(qr, _cmp);

    vi ans(q);
    ll ret=ans[qr[0][2]]=_mos({qr[0][0], qr[0][0]-1, 0LL}, qr[0], 0);
    forf(i, 1, q) ret=ans[qr[i][2]]=_mos(qr[i-1], qr[i], ret);
    forf(i, 0, q) cout << ans[i] << "\n";

    return 0;
}
