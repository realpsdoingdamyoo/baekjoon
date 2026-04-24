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

ll n;
vpii v;

vi chk(pii c){
    vi dst;
    forf(i, 0, n){
        dst.pb(abs(v[i][0]-c[0])+abs(v[i][1]-c[1]));
    }
    sortv(dst);
    forf(i, 1, n) dst[i]+=dst[i-1];
    return dst;
}

int main(){
    fastio;

    cin >> n;
    v.resize(n);
    vi ret(n);
    forf(i, 0, n*2) cin >> v[i/2][i%2];
    forf(i, 0, n) ret[i]=inf;

    forf(i, 0, n){
        forf(j, 0, n){
            pii c={v[i][0], v[j][1]};
            vi cr=chk(c);
            forf(k, 0, n) ret[k]=min(ret[k], cr[k]);
        }
    }

    forf(i, 0, n) cout << ret[i] << " ";

    return 0;
}
