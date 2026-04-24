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

ll n;
vi v, st;
vpii p;

const ll X=19;
tii seg[1<<X+1];

V<vpii> qrs;

tii mrg(tii a, tii b){
    return {max(a[0], b[0]), max(a[1], b[1]), max(max(a[2], b[2]), a[0]+b[1])};
}

void update(ll p, ll x){
    seg[p+(1<<X)]=max(seg[p+(1<<X)], {x, v[p], x+v[p]});
    p+=1<<X; p>>=1;

    while(p){
        seg[p]=mrg(seg[p<<1], seg[p<<1|1]);
        p>>=1;
    }
}

ll mxq(ll s, ll e){
    tii ret={0, 0, 0};
    V<tii> sv, ev;

    s+=1<<X; e+=1<<X;
    while(s<=e){
        if(s&1) sv.pb(seg[s]);
        if(~e&1) ev.pb(seg[e]);
        s=s+1>>1; e=e-1>>1;
    }

    for(tii i : sv) ret=mrg(ret, i);
    reverse(all(ev));
    for(tii i : ev) ret=mrg(ret, i);

    return ret[2];
}

int main(){
    fastio;

    cin >> n;
    v.resize(n); qrs.resize(n);
    forf(i, 0, n) cin >> v[i];

    forf(i, 0, n){
        while(st.size() && v[st.back()]<v[i]){
            p.pb({st.back(), i}); st.pop_back();
        }
        if(st.size()) p.pb({st.back(), i});
        st.pb(i);
    }
    sortv(p);

    ll q; cin >> q;
    vi ans(q);
    forf(i, 0, q){
        ll a, b; cin >> a >> b;
        qrs[a-1].pb({b-1, i});
    }

    forf(i, 0, n) update(i, 0);

    forb(i, n, 0){
        while(p.size() && p.back()[0]==i){
            pii b=p.back(); p.pop_back();
            if(n-1<b[1]*2-b[0]) continue;
            update(b[1]*2-b[0], v[b[0]]+v[b[1]]);
        }
        for(pii j : qrs[i]){
            ans[j[1]]=mxq(i, j[0]);
        }

    }

    for(ll i : ans) cout << i << "\n";

    return 0;
}
