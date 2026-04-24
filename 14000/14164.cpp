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

vpii v;
vvi pr;

bool cmpy(ll a, ll b){
    return v[a][1]<v[b][1];
}

bool left(pii a, pii b, pii p){
    if(a[1]==b[1]) return false;
    if((a[1]-p[1])*(p[1]-b[1])<0) return false;
    if(p[1]==max(a[1], b[1])) return false;
    lf abm=(a[0]*(b[1]-p[1])+b[0]*(p[1]-a[1])+0.0)/(b[1]-a[1]);
    if(p[0]<abm) return true;
    return false;
}

int main() {
    fastio;

    ll n; cin >> n; v.resize(n); pr.resize(n);
    forf(i, 0, n) cin >> v[i][0] >> v[i][1];
    forf(i, 0, n) pr[i].resize(n);

    forf(i, 0, n){
        forf(j, 0, n){
            if(i==j) continue;
            forf(k, 0, n) pr[i][j]+=left(v[i], v[j], v[k]);
        }
    }
    vi ans(n-2);
    forf(i, 0, n){
        forf(j, i+1, n){
            forf(k, j+1, n){
                vi p(3);
                p[0]=i; p[1]=j; p[2]=k;
                sortc(p, cmpy);
                if(!left(v[p[0]], v[p[2]], v[p[1]])){
                    ans[pr[p[1]][p[0]]+pr[p[1]][p[2]]-pr[p[2]][p[0]]]++;
                }
                else ans[pr[p[2]][p[0]]-pr[p[1]][p[2]]-pr[p[1]][p[0]]-1]++;
            }
        }
    }

    forf(i, 0, n-2) cout << ans[i] << "\n";


	return 0;
}
