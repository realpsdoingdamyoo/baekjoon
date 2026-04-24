#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef array<ll, 2> pii;
typedef array<ll, 3> tii;
typedef vector<pii> vpii;
typedef double lf;
typedef priority_queue<ll> pqi;
#define V vector
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define vcin; for(int i=0; i<n; i++) cin >> v[i];
#define forf(i, s, e) for(ll i=s; i<e; i++)
#define forb(i, s, e) for(ll i=s-1; i>=e; i--)
#define pb push_back
#define sortv(v) sort(v.begin(), v.end())
#define sortc(v, cmp) sort(v.begin(), v.end(), cmp)
#define repeat(n) for(ll not_used_name=0; not_used_name<n; not_used_name++)
#define all(v) v.begin(), v.end()
const int mod=1e9+7, MOD=998244353;
const int dir4[4][2]={{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
const int dir8[8][2]={{0, 1}, {1, 0}, {-1, 0}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
const ll inf=2147483647, linf=9223372036854775807;
const double PI=acos(-1), EU=2.718281828459;
ll gcd(ll a, ll b){return b?gcd(b, a%b):a;}

vvi pan;
vvi vsd;
ll n, m, dfscnt, mxx;

ll avc(ll x, ll y){
    return 0<=x && x<n && 0<=y && y<m;
}

ll dfs(ll x, ll y){
    if(!avc(x, y) || vsd[x][y] || pan[x][y]==1) return 0;
    vsd[x][y]=1;
    ll ret=1; dfscnt+=pan[x][y]/2;
    forf(i, 0, 4) ret+=dfs(x+dir4[i][0], y+dir4[i][1]);
    return ret;
}

int main() {
    fastio;

    cin >> n >> m;
    pan.resize(n); vsd.resize(n);
    forf(i, 0, n){pan[i].resize(m); vsd[i].resize(m);}

    forf(i, 0, n){
        forf(j, 0, m) cin >> pan[i][j];
    }

    forf(d1, 0, n*m){
        if(pan[d1/m][d1%m]) continue;
        pan[d1/m][d1%m]=1;

        forf(d2, 0, n*m){
            if(pan[d2/m][d2%m]) continue;
            pan[d2/m][d2%m]=1;

            forf(i, 0, n){
                forf(j, 0, m) vsd[i][j]=0;
            }

            ll mx=0;
            forf(i, 0, n){
                forf(j, 0, m){
                    dfscnt=0;
                    ll df=dfs(i, j);
                    if(dfscnt==df) mx+=dfscnt;
                }
            }
            mxx=max(mxx, mx);

            pan[d2/m][d2%m]=0;
        }
        pan[d1/m][d1%m]=0;
    }

    cout << mxx;

    return 0;
}
