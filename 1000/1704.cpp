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

ll b[15][15];
ll mb[15][15];
ll n, m;

void flip(ll x, ll y){
    mb[x][y]^=1;
    forf(i, 0, 4){
        if(0<=x+dir4[i][0] && x+dir4[i][0]<n && 0<=y+dir4[i][1] && y+dir4[i][1]<m)
            mb[x+dir4[i][0]][y+dir4[i][1]]^=1;
    }
}

int main(){
    fastio;
    
    cin >> n >> m;
    forf(i, 0, n) forf(j, 0, m) cin >> b[i][j];
    ll a=n*m*2, as;
    forf(i, 0, 1<<m){
        ll s=0;
        forf(j, 0, n*m) mb[j/m][j%m]=b[j/m][j%m];
        forf(j, 0, m) if(i&(1<<m-1-j)) {flip(0, j); s++;}
        
        forf(j, 1, n) forf(k, 0, m){
            if(mb[j-1][k]){
                flip(j, k); s++;
            }
        }
        ll chk=0;
        forf(j, 0, m) chk+=mb[n-1][j];
        
        if(!chk){
            if(s<a){a=s; as=i;}
        }
    }
    if(a>n*m){
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    
    forf(i, 0, n*m) mb[i/m][i%m]=b[i/m][i%m];
    
    forf(i, 0, m) cout << !!(as&(1<<m-1-i)) << " ";
    forf(i, 0, m) if(as&(1<<m-1-i)) flip(0, i);
    forf(i, 1, n){
        cout << "\n";
        forf(j, 0, m){
            cout << mb[i-1][j] << " ";
            if(mb[i-1][j]) flip(i, j);
        }
    }

    return 0;
}
