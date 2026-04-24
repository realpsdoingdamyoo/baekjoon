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

ll fac[200008]={1};
ll rfac[200008];


ll rvs(ll N){
    ll r=1, x=mod-2;
    while(x){
        if(x&1) r=r*N%mod;
        N=N*N%mod; x>>=1;
    }
    return r;
}

ll ncr(ll N, ll r){
    return fac[N]*rfac[N-r]%mod*rfac[r]%mod;
}

ll det(vvi v){
    ll n=v.size();
    forf(i, 0, n){
        if(v[i][i]==0){
            forf(j, 0, n){
                if(v[j][i]==0) continue;
                else{swap(v[i], v[j]); break;}
            }
            if(v[i][i]==0) return 0;
        }

        forf(j, i+1, n){
            if(v[j][i]==0) continue;
            //cout << "(" << rvs(v[j][i]) << ")";
            ll d=rvs(v[i][i])*v[j][i]%mod;
            forf(k, i, n) v[j][k]=(v[j][k]-v[i][k]*d%mod+mod)%mod;
        }
    }

    /*forf(i, 0, n){
        forf(j, 0, n) cout << v[i][j] << " ";
        cout << "\n";
    } cout << "\n";*/

    ll ret=1;
    forf(i, 0, n) ret=ret*v[i][i]%mod;
    return ret;
}

void solve(){
    ll x, n; cin >> x >> n;

    vi v(n), u(n);
    forf(i, 0, n) cin >> v[i];
    forf(i, 0, n) cin >> u[i];

    vvi mat(n); forf(i, 0, n) mat[i].resize(n);

    forf(i, 0, n){
        forf(j, 0, n){
            if(u[i]-v[j]>=0) mat[i][j]=ncr(u[i]-v[j]+x-1, x-1);
            else mat[i][j]=0;
        }
    }

    /*forf(i, 0, n){
        forf(j, 0, n) cout << mat[i][j] << " ";
        cout << "\n";
    } cout << "\n";*/

    cout << det(mat) << "\n";

}

int main(){
    fastio;

    forf(i, 1, 200008) fac[i]=fac[i-1]*i%mod;
    forf(i, 0, 200008) rfac[i]=rvs(fac[i]);

    ll T; cin >> T;
    while(T--) solve();


    return 0;
}
