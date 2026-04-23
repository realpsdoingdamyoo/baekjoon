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

ll n;
bool vsd[670][670];
ll war[670][670];

void init(){
    forf(i, 1, n+1){
        forf(j, 1, n+1){
            for(ll I : {-2, -1, 1, 2}){
                for(ll J : {-2, -1, 1, 2}){
                    if(I==J || I+J==0) continue;
                    ll nx=I+i, ny=J+j;
                    if(nx<=0 || ny<=0 || nx>n || ny>n) continue;
                    war[i][j]++;
                }
            }
        }
    }
}

int main(){
    fastio;

    ll c=1;
    ll x, y; cin >> n >> x >> y;
    vsd[x][y]=true; init();
    vpii ans; ans.pb({x, y});

    while(c<n*n){
        ll X=x, Y=y;

        for(ll i : {-2, -1, 1, 2}){
            for(ll j : {-2, -1, 1, 2}){
                if(i==j || i+j==0) continue;
                ll nx=x+i, ny=y+j;
                if(nx<=0 || ny<=0 || nx>n || ny>n) continue;
                if(vsd[nx][ny]) continue;


                if(X==x && Y==y){
                    X=nx; Y=ny; continue;
                }

                if(war[X][Y]<war[nx][ny]) continue;
                if(war[X][Y]>war[nx][ny]){
                    X=nx; Y=ny; continue;
                }

                if(pow(n-2*nx, 2)+pow(n-2*ny, 2)>pow(n-2*X, 2)+pow(n-2*Y, 2)){
                    X=nx; Y=ny;
                }

            }
        }

        if(X==x && Y==y) break;

        x=X; y=Y;
        vsd[x][y]=true;

        for(ll i : {-2, -1, 1, 2}){
            for(ll j : {-2, -1, 1, 2}){
                if(i==j || i==-j) continue;
                ll nx=x+i, ny=y+j;
                if(nx<=0 || ny<=0 || nx>n || ny>n) continue;
                if(vsd[nx][ny]) continue;

                war[nx][ny]--;
            }
        }

        ans.pb({x, y});
        c++;
    }

    if(c==n*n){
        for(pii i : ans) cout << i[0] << " " << i[1] << "\n";
    }
    else cout << "-1 -1";
    return 0;
}
