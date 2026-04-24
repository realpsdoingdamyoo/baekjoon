#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef array<ll, 2> pii;
typedef vector<pii> vpii;
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define vcin; for(int i=0; i<n; i++) cin >> v[i];
#define forf(i, s, e) for(int i=s; i<e; i++)
#define forb(i, s, e) for(int i=s-1; i>=e; i--)
#define pb push_back
#define repeat(n) for(int not_used_name=0; not_used_name<n; not_used_name++)
const int mod=1e9+7, MOD=998244353;
const int dir[4][2]={{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
const ll inf=2147483647, linf=9223372036854775807;
ll gcd(ll a, ll b){return b?gcd(b, a%b):a;}

ll bmb[2003][2003], bmbn[2003][2003];

int main() {
    fastio;

    ll n, m; cin >> n >> m;
    forf(i, 0, n){
        forf(j, 0, n) cin >> bmb[i][j];
    }
    bmbn[0][0]=-bmb[0][0];
    forf(i, 1, n){
        bmbn[i][0]=-bmb[i][0]+bmb[i-1][0];
        bmbn[0][i]=-bmb[0][i]+bmb[0][i-1];
    }
    forf(i, 1, n-m+1){
        forf(j, 1, n-m+1){
            bmbn[i][j]=-bmb[i][j]+bmb[i][j-1]+bmb[i-1][j]-bmb[i-1][j-1];
        }
    }
    forf(i, 0, n){
        forf(j, 0, n){
            if(i<m/2 || j<m/2) cout << "0 ";
            else if(i>=n-m/2 || j>=n-m/2) cout << "0 ";
            else{
                cout << bmbn[i-m/2][j-m/2] << " ";
                ll x=bmbn[i-m/2][j-m/2];
                bmbn[i-m/2+m][j-m/2]+=x;
                bmbn[i-m/2][j-m/2+m]+=x;
                bmbn[i-m/2+m][j-m/2+m]-=x;
            }
        }
        cout << "\n";
    }
    return 0;
}
