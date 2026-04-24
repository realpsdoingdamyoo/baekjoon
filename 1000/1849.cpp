#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef array<ll, 2> pii;
typedef array<ll, 3> tii;
typedef vector<pii> vpii;
typedef __float128 lf;
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
const ll X=18;
ll seg[1<<X+1];

void update(ll p){
    p+=1<<X;
    while(p){seg[p]++; p>>=1;}
}

ll sum(ll e){
    ll s=1<<X, r=0; e+=1<<X;
    while(s<=e){
        if(~e&1) r+=seg[e];
        s=s>>1; e=(e-1)>>1;
    }
    return r;
}

ll fnd(ll c){
    ll s=0, e=n-1;
    while(s<=e){
        ll m=(s+e)>>1;
        if(m+1-sum(m)<=c) s=m+1;
        else e=m-1;
    }
    return s;
}

int main(){
    fastio;

    cin >> n;
    vi v(n);

    forf(i, 0, n){
        ll a; cin >> a;
        ll f=fnd(a);
        v[f]=i+1;
        update(f);
    }

    forf(i, 0, n) cout <<v[i] <<"\n";

    return 0;
}
