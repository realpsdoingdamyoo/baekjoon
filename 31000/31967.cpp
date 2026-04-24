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
vi v;
vi N;

const ll X=18;
pii seg[1<<X+1];
pii sp[X+1][1<<X];

void spm(){
    forf(j, 0, X){
        forf(i, 0, (1<<X)-(1<<j)){
            sp[j+1][i]=min(sp[j][i], sp[j][i+(1<<j)]);
        }
    }
}

pii mnm(ll s, ll e){
    ll w=(ll)log2(e-s+1);
    return min(sp[w][s], sp[w][e-(1<<w)+1]);
}

ll query(ll s, ll e, ll x){
    if(s>e) return 0;

    ll ret=0;
    pii m=mnm(s, e);
    ret+=(e-s+1)*(m[0]-x);
    ret+=query(s, m[1]-1, m[0]);

    return ret;
}

int main(){
    fastio;

    cin >> n >> q;
    v.resize(n); N.resize(n);
    forf(i, 0, n) cin >> v[i];
    ll s=0;
    forf(i, 1, n){
        ll x=-30;
        while(v[i-1]>v[i]*pow(2, x)) x++;
        s+=x; sp[0][i]={s, i};
        N[i]=N[i-1]+s;
    } spm();


    while(q--){
        ll a, b; cin >> a >> b;
        ll s=N[b-1]-(a==1?0:N[a-2]);
        cout << s-query(a-1, b-1, 0) << "\n";
    }


    return 0;
}
