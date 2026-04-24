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

ll onenum(ll m, ll b){
    vi av;
    forf(i, 0, 10) if(m&(1<<i)) av.pb(i);
    if(av.size()==0) return b;
    if(av.size()==1){
        if(av[0]==0) return 10;
        return av[0];
    }
    if(av[0]==0) swap(av[0], av[1]);
    ll ret=0;
    for(ll i : av) ret=ret*10+i;
    return ret;
}

ll twonum_n9(ll f, ll s, ll b){
    ll ret=inf*123456;
    if(f==0 && s==0) return b;
    forf(i, 0, 9){
        ret=min(ret, onenum((f&~(1<<i))|(s&~(1<<i+1)), i==0 && (f&1))*10+i);
    }
    if(ret==0 && b) return 10;
    return ret;
}

ll twonum(ll f, ll s, ll b){
    return min(twonum_n9(f, s, b), twonum_n9(f&~(1<<9), s&~1, 0)*10+9);
}

ll ans(vi v, ll b){
    if(v.size()==1){
        return onenum(v[0], b);

    }
    else if(v.size()==2){
        return twonum(v[0], v[1], b);
    }

    vi u;
    ll ret=inf*123456;
    forf(i, 0, 10){
        u.clear();
        forf(j, 0, v.size()){
            if(u.size()<=(i+j)/10) u.pb(0);
            u.back()|=v[j]&~(1<<(j+i)%10);
        }
        ret=min(ret, ans(u, i==0 && (v[0]&1))*10+i);
    }

    return ret;
}


int main(){
    fastio;

    ll n; cin >> n;
    vi v(n);
    forf(i, 0, n){
        ll a; cin >> a;
        v[i]=1<<a;
    }

    cout << ans(v, 1);

    return 0;
}
