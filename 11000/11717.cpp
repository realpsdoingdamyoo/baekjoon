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

ll n, m;
V<string> s;
ll sg[20][20][20][20];

ll dfs(ll xs, ll ys, ll xe, ll ye){
    if(xs>xe || ys>ye) return 0;
    if(sg[xs][ys][xe][ye]!=-1) return sg[xs][ys][xe][ye];
    if(xs==xe && ys==ye) return sg[xs][ys][xe][ye]=(s[xs][ys]=='.');

    vi mex; mex.pb(-1); mex.pb(inf);

    forf(i, xs, xe+1){
        forf(j, ys, ye+1){
            if(s[i][j]=='X') continue;
            ll nsg=0;
            nsg^=dfs(xs, ys, i-1, j-1);
            nsg^=dfs(xs, j+1, i-1, ye);
            nsg^=dfs(i+1, ys, xe, j-1);
            nsg^=dfs(i+1, j+1, xe, ye);
            mex.pb(nsg);
        }
    }

    sortv(mex);
    forf(i, 0, mex.size()-1)
        if(mex[i]+1<mex[i+1])
            return sg[xs][ys][xe][ye]=mex[i]+1;


}

int main() {
    fastio;

    cin >> n >> m;
    s.resize(n);
    forf(i, 0, n) cin >> s[i];

    forf(i, 0, 20) forf(j, 0, 20) forf(k, 0, 20) forf(l, 0, 20) sg[i][j][k][l]=-1;

    cout << (dfs(0, 0, n-1, m-1)?"First":"Second");



    return 0;
}
