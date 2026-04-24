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


ll brd[500][500];
bool vsd[500][500];

int main(){
    fastio;

    forf(i, 0, 500){
        forf(j, 0, 500){
            brd[i][j]=(i+j+1)*(i+j)/2+j+1;
        }
    }

    ll k; cin >> k;
    k=min(k, 2401LL);

    ll x=0, y=0; vsd[0][0]=true;
    while(k--){
        ll nmx=0, nmy=0;
        for(ll i : {1, -1, 2, -2}){
            for(ll j : {1, -1, 2, -2}){
                if(i==j || i+j==0) continue;
                if(x+i<0 || y+j<0) continue;
                if(vsd[x+i][y+j]) continue;

                if(brd[x+i][y+j]<brd[nmx][nmy] || nmx+nmy==0){
                    nmx=x+i; nmy=y+j;
                }
            }
        }
        vsd[nmx][nmy]=true;
        x=nmx; y=nmy;
    }
    cout << brd[x][y] <<"\n";

    return 0;
}
