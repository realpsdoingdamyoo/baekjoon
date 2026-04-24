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

ll n, X;
vi v;

bool canmake(ll a){
    vi u=v;
    forf(i, a, X){
        u[0]+=u[i];
        u[i]=0;
    }

    ll need=1;
    forb(i, a, 1){
        if(need<u[i]){
            u[0]+=u[i]-need;
            u[i]=need;
        }
        else{
            need+=need-u[i];
            u[i]=need;
        }
        if(need>n) return false;
    }

    if(u[0]<need) return false;
    return true;
}

int main(){
    fastio;

    cin >> n; X=n+10;
    v.resize(X);
    forf(i, 0, n){
        ll a; cin >> a;
        v[a]++;
    }

    ll s=0, e=n;

    while(s<=e){
        ll m=(s+e)/2;
        if(canmake(m)) s=m+1;
        else e=m-1;
    }
    cout << e;


    return 0;
}
