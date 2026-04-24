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

bool ccw(pii a, pii b, pii c){
    ll s=a[0]*b[1]+b[0]*c[1]+c[0]*a[1]-a[1]*b[0]-b[1]*c[0]-c[1]*a[0];
    return s==0;
}

int main() {
    fastio;

    srand(time(0));
    ll n, p; cin >> n >> p;
    if(n==1){cout << "possible"; return 0;}
    vpii v(n);
    forf(i, 0, n*2) cin >> v[i/2][i%2];
    forf(x, 0, 1000){
        ll cnt=0, q;
        pii p1=v[rand()%n], p2=p1;
        while(p1==p2) p2=v[rand()%n];
        forf(i, 0, n) if(ccw(p1, p2, v[i])) cnt++;
        if(cnt*100>=p*n){
            cout << "possible";
            return 0;
        }
    }
    cout << "impossible";

    return 0;
}
