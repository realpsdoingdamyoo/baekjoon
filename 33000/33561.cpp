#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef array<ll, 2> pii;
typedef array<ll, 3> tii;
typedef vector<pii> vpii;
typedef __float128 lf;
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
#define cf cout.flush()

int main(){
    //fastio;

    ll n; cin >> n;
    vvi v(n), c(n);
    forf(i, 0, n){
        v[i].resize(n);
        c[i].resize(n);
        forf(j, 0, n) cin >> v[i][j];
        forf(j, 0, n) c[i][j]=!v[i][j];
    }

    forf(i, 0, n){
        forf(j, 1, n){
            v[i][j]+=v[i][j-1];
            c[i][j]+=c[i][j-1];
        }
    }
    forf(i, 1, n){
        forf(j, 0, n){
            v[i][j]+=v[i-1][j];
            c[i][j]+=c[i-1][j];
        }
    }

    ll k, ans=0; cin >> k;
    vi u(k);
    forf(i, 0, k) cin >> u[i];
    sortv(u); reverse(all(u));
    forf(i, 1, k) u[i]+=u[i-1];

    forf(i, 0, n){
        forf(j, i, n){
            forf(l, 0, n-j+i){
                ll m=l+j-i;


                ll ec=c[j][m];
                ll as=v[j][m];

                if(i){
                    ec-=c[i-1][m];
                    as-=v[i-1][m];
                }
                if(l){
                    ec-=c[j][l-1];
                    as-=v[j][l-1];
                }
                if(i&&l){
                    ec+=c[i-1][l-1];
                    as+=v[i-1][l-1];
                }
                if(ec>k) continue;
                if(ec) as+=u[ec-1];
                ans=max(ans, as);
            }
        }
    }

    cout <<ans;

    return 0;
}
