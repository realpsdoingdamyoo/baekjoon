#include <bits/stdc++.h>
using namespace std;
typedef __int128_t ll;
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
#define forf(i, s, e) for(int i=s; i<e; i++)
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

vvi lnk;

vi ar;

vi mul(vi a, vi b){
    vi ret(a.size()+b.size()-1);
    forf(i, 0, a.size()){
        forf(j, 0, b.size()){
            ret[i+j]+=a[i]*b[j];
        }
    }
    return ret;
}

void arp(vi x){
    forf(i, 0, min(ar.size(), x.size())) ar[i]+=x[i];
    if(ar.size()<x.size()) forf(i, ar.size(), x.size()) ar.pb(x[i]);
}

vi dfs(ll pnt, ll pre){
    vi ret; ret.pb(1);

    for(ll i : lnk[pnt])
        if(i!=pre) ret=mul(ret, dfs(i, pnt));
    arp(ret);
    ret.insert(ret.begin(), 1);

    return ret;
}

int main(){
    fastio;

    ll n, k; //cin >> n >> k;
    long long N, K; cin >> N >> K;
    n=N; k=K;
    lnk.resize(n);
    forf(i, 0, n-1){
        int a, b; cin >> a >> b;
        lnk[a-1].pb(b-1);
        lnk[b-1].pb(a-1);
    }

    dfs(0, -1);

    forf(i, 0, ar.size()){
        k-=ar[i];
        if(k<=0){cout << i+1; return 0;}
    }
    cout << "-1";

    return 0;
}
