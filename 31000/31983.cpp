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
const double pi=acos(-1), E=2.718281828459;
ll gcd(ll a, ll b){return b?gcd(b, a%b):a;}
#define cf; cout.flush();

ll go[1001][1001];
ll byunjaewoo_is_super_legend_gay;

int main() {
    fastio;

    ll n, rmx=0; cin >> n;
    forf(i, 0, n) forf(j, 0, n) cin >> go[i][j];
    forf(i, 0, n){
        ll r=0;
        forf(j, 0, n) r+=go[i][j];
        if(r==n-1){cout << "-1"; return 0;}
        if(r>rmx){
            byunjaewoo_is_super_legend_gay=i;
            rmx=r;
        }
    }
    cout << "3\n";
    forf(i, 0, n){
        forf(j, 0, n){
            if(go[i][j]==0) cout << "0 ";
            else{
                if(i==byunjaewoo_is_super_legend_gay || j==byunjaewoo_is_super_legend_gay){
                    if(i==byunjaewoo_is_super_legend_gay) cout << "1 ";
                    else cout << "2 ";
                }
                else{
                    if(go[byunjaewoo_is_super_legend_gay][i] && go[byunjaewoo_is_super_legend_gay][j]) cout << "1 ";
                    else if(go[byunjaewoo_is_super_legend_gay][i] && go[j][byunjaewoo_is_super_legend_gay]) cout << "3 ";
                    else if(go[i][byunjaewoo_is_super_legend_gay] && go[byunjaewoo_is_super_legend_gay][j]) cout << "2 ";
                    else cout << "1 ";
                }
            }
        }
        cout << "\n";
    }

    return 0;
}
