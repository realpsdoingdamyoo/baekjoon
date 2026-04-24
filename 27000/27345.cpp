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
const ll inf=2147483647, linf=140737488355327;
const double pi=acos(-1), E=2.718281828459;
ll gcd(ll a, ll b){return b?gcd(b, a%b):a;}

ll n, x, y, z, ans;
ll lazyn, lazyp; // lazyp>0, lazyn<0
deque<ll> P, N; // N : ~-1 / P : 0~
vi v;

void PtoN(){
    if(P.size()==0) P.push_front(y-lazyp);
    ll t=P.front()+lazyp; P.pop_front();

    t=min(t, y);
    ans+=t;
    N.push_back(t-lazyn);
}

void NtoP(){
    if(N.size()==0) N.push_back(-x-lazyn);
    ll t=N.back()+lazyn; N.pop_back();

    t=max(t, -x);
    ans-=t;
    P.push_front(t-lazyp);
}

int main(){
    fastio;

    cin >> n;
    x=linf; y=0; z=1;
    forf(i, 0, n){
        ll a, b; cin >> a >> b;
        v.pb(a-b);
    }

    forf(i, 0, n){
        forf(j, 0, v[i]) PtoN();
        forf(j, 0, -v[i]) NtoP();
        lazyp+=z; lazyn-=z;
    }
    cout << ans;

    return 0;
}
