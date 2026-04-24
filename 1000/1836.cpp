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
#define cf; cout.flush();

ll tree[205][105];
ll njh[205][105];

int main() {
    fastio;

    tree[1][1]=njh[1][1]=1;
    ll n, k; cin >> n >> k;

    forf(i, 1, n+1){
        forf(j, 1, k+1){
            if(i+j>2){
                tree[i][j]=9901*9901;
                forf(l, 1, i-1){
                    tree[i][j]+=tree[l][j-1]*njh[i-1-l][j-1]*2;
                    tree[i][j]-=tree[l][j-1]*tree[i-1-l][j-1]%9901;
                }
                tree[i][j]%=9901;
                njh[i][j]=(njh[i][j-1]+tree[i][j])%9901;
            }
            //cout << tree[i][j] << " ";
        }
        //cout << "\n";
    } /*cout << "\n";

    forf(i, 1, n+1){
        forf(j, 1, k+1) cout << njh[i][j] << " ";
        cout << "\n";
    } cout << "\n";*/

    cout << tree[n][k];

    return 0;
 }
