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


int main(){
    //fastio;

    ll n, m; cin >> n >> m;
    V<tii> v(m);
    forf(i, 0, m) cin >> v[i][0] >> v[i][1];

    ll lft=n;
    forf(i, 0, m){
        if(v[i][0]+v[i][1]>n){
            cout << "NO";
            return 0;
        }


        ll x=n-v[i][0]-v[i][1];
        v[i][2]=min(x, lft);
        lft-=v[i][2];
        if(v[i][0]+v[i][1]+v[i][2]<n)
            v[i][0]=n-v[i][1]-v[i][2];
    }


    if(lft){
        cout << "NO";
        return 0;
    }

    V<string> s(n);
    forf(i, 0, n) forf(j, 0, m) s[i]+=".";

    cout << "YES\n";
    lft=0;
    forf(j, 0, m){
        ll x=v[j][2];
        forf(i, 0, n){
            if(v[j][2]){s[(i+lft)%n][j]='X'; v[j][2]--;}
            else if(v[j][1]){s[(i+lft)%n][j]='-'; v[j][1]--;}
            else if(v[j][0]){s[(i+lft)%n][j]='+'; v[j][0]--;}
        }
        lft+=x;
    }

    forf(i, 0, n) cout << s[i] << "\n";

    return 0;
}
