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

int main(){
    fastio;

    ll n; cin >> n;
    vi app(n*2+1);
    vi toc(n*2+1);
    vpii loc(n*2+1);
    vvi v(n); forf(i, 0, n) v[i].resize(n);
    forf(i, 0, n) forf(j, 0, n) cin >> v[i][j];

    forf(i, 0, n) forf(j, 0, n){
        app[v[i][j]]++;
        loc[v[i][j]]={i, j};
    }

    ll one1=0, one2=0;
    forf(i, 2, n*2+1){
        if(app[i]==1){
            if(!one1) one1=i;
            else one2=i;
        }
    }

    ll x1=loc[one1][1], x2=loc[one2][1];

    forf(i, 0, n){
        toc[v[i][x1]]=app[v[i][x1]]+1;
        toc[v[i][x2]]=n*2+1-app[v[i][x2]];
    }

    forf(i, 0, n) forf(j, 0, n) v[i][j]=toc[v[i][j]];

    if(n>1 && (v[0][0]>n+1 || (v[0][0]==n+1 && v[0][1]>n+1))){

        forf(i, 0, n) forf(j, 0, n) v[i][j]=n*2+2-v[i][j];

    }


    forf(i, 0, n){
        forf(j, 0, n){
            cout << v[i][j];
            if(j<n-1) cout << " ";
        }
        if(i<n-1) cout << "\n";
    }

    return 0;
}
