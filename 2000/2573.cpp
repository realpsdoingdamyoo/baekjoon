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


ll n, m;
vvi v, vsd, u;
ll fld, cnt;

void dfs(ll x, ll y){
    if(x<0 || y<0 || x>=n || y>=m || vsd[x][y] || v[x][y]==0) return;
    cnt++; vsd[x][y]=1;

    forf(i, 0, 4) dfs(x+dir4[i][0], y+dir4[i][1]);
}

int main(){
    fastio;

    cin >> n >> m;
    v.resize(n); vsd.resize(n); u.resize(n);
    forf(i, 0, n){v[i].resize(m); vsd[i].resize(m); u[i].resize(m);}
    forf(i, 0, n) forf(j, 0, m) cin >> v[i][j];

    forf(t, 1, 500){
        fld=cnt=0;
        forf(i, 0, n) forf(j, 0, m){
            ll bing=0;
            forf(y, 0, 4){
                bing+=(i+dir4[y][0]>=0 && i+dir4[y][0]<n && j+dir4[y][1]>=0 && j+dir4[y][1]<m && v[i+dir4[y][0]][j+dir4[y][1]]==0);
            }
            if(bing) u[i][j]=max(0LL, v[i][j]-bing);
            else u[i][j]=v[i][j];
            fld+=!!u[i][j];
            vsd[i][j]=0;
        }
        v=u;

        ll c=0;
        forf(x, 0, n*m){
            ll i=x/m, j=x%m;
            if(v[i][j]){
                dfs(i, j);
                if(cnt<fld) c=1;
                break;
            }
        }

        /*forf(i, 0, n){
            forf(j, 0, m) cout << v[i][j] << " "; cout << "\n";
        }*/

        if(c) {cout << t << "\n"; return 0;}


    }
    cout << "0\n";

    return 0;
}
