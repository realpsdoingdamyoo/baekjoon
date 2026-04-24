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
const double PI=acos(-1), E=2.718281828459;
ll gcd(ll a, ll b){return b?gcd(b, a%b):a;}

int main(){
    fastio;

    ll n, m, k; cin >> n >> m >> k;
    vi v(n); vpii u(n, {-inf*80808, -inf*80808});

    for(ll i=0, a; i<m; i++){cin >> a; v[a-1]=1;}

    ll c=m+k-1>>1, L=c+1, R=m+k-c-1;

    ll Li=0, Ls=0, Lc=0, Lj=0;
    queue<ll> Lq;

    for(; Li<L; Li++){
        if(v[Li]==0) Ls+=Lq.size(), Lj++;
        Lq.push(Li);
    } u[Li-1][0]=Ls;

    while(Li<n){
        if(v[Li]==0) Ls+=Lq.size()+Lc, Lj++;
        Lq.push(Li);

        while(Lq.size() && Lc+Lq.size()>L){
            ll t=Lq.front(); Lq.pop();
            if(v[t]==0) Lj--, Ls-=Lc+Lj;
            else Lc++;
        }

        if(Lc+Lq.size()>L) break;
        u[Li][0]=Ls; Li++;
    }

    ll Ri=n-1, Rs=0, Rc=0, Rj=0;
    queue<ll> Rq;

    for(; Ri>=n-R; Ri--){
        if(v[Ri]==0) Rs+=Rq.size(), Rj++;
        Rq.push(Ri);
    } u[Ri+1][1]=Rs;

    while(Ri>=0){
        if(v[Ri]==0) Rs+=Rq.size()+Rc, Rj++;
        Rq.push(Ri);

        while(Rq.size() && Rc+Rq.size()>R){
            ll t=Rq.front(); Rq.pop();
            if(v[t]==0) Rj--, Rs-=Rc+Rj;
            else Rc++;
        }

        if(Rc+Rq.size()>R) break;
        u[Ri][1]=Rs; Ri--;
    }

    //for(ll i=0; i<n; i++) cout << u[i][0] << " "; cout << "\n";
    //for(ll i=0; i<n; i++) cout << u[i][1] << " "; cout << "\n";

    ll ret=0;
    for(ll i=0; i<n-1; i++) ret=max(ret, u[i][0]+u[i+1][1]);
    cout << (2*m+k-1)*k/2-ret*2;

    return 0;
}
