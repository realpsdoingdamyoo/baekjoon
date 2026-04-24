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

int main(){
    fastio;

    ll n, m, k, t, p; cin >> n >> m >> k >> t >> p;
    V<tii> v(k);
    forf(i, 0, k){
        cin >> v[i][0] >> v[i][1] >> v[i][2];
        v[i][0]--; v[i][1]--;
    } sortv(v);

    ll mx1=0;
    forf(i, 0, n){
        forf(j, 0, m){
            ll c=0;
            for(tii l : v){
                ll d=abs(i-l[0])+abs(j-l[1]);
                if(l[2]*d<=p) c++;
            }
            mx1=max(mx1, c);
        }
    }

    ll mx2=0;

    do{
        ll d=0, c=0;
        ll x=v[0][0], y=v[0][1];

        forf(i, 0, k){
            d+=abs(x-v[i][0])+abs(y-v[i][1]);
            if(d>t) break;
            x=v[i][0]; y=v[i][1];
            c++;
        }
        mx2=max(mx2, c);
    }while(next_permutation(all(v)));

    cout << mx2 << " " << mx1;

    return 0;
}
