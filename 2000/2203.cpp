/*******************************
** coded by realpsdoingdamyoo **
*******************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef array<ll, 2> pii;
typedef vector<pii> vpii;
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define vcin; for(int i=0; i<n; i++) cin >> v[i];
#define forf(i, s, e) for(int i=s; i<e; i++)
#define forb(i, s, e) for(int i=s-1; i>=e; i--)
#define sortv(v) sort(v.begin(), v.end())
#define sortc(v, cmp) sort(v.begin(), v.end(), cmp)
#define repeat(n) for(int not_used_name=0; not_used_name<n; not_used_name++)
const int mod=1e9+7, MOD=998244353;
const int dir4[4][2]={{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
const int dir8[8][2]={{0, 1}, {1, 0}, {-1, 0}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
const ll inf=2147483647, linf=9223372036854775807;
ll gcd(ll a, ll b){return b?gcd(b, a%b):a;}


int main() {
    fastio;

    srand(time(0));

    ll n; cin >> n;
    vpii v(3*n);
    forf(i, 0, 3*n){
        cin >> v[i][0];
        v[i][1]=i+1;
    }

    sortv(v); reverse(v.begin(), v.end());

    ll s1=0, s2=0;
    forf(i, 0, n){
        s1+=v[i][0];
        s2+=v[i+n][0];
    }
    while((s1<=n*500 || s2<=n*500 )){
        ll a=rand()%n;
        ll b=rand()%n+n;
        //cout << a << " " << b << "\n";
        s1+=v[b][0]-v[a][0];
        s2+=v[a][0]-v[b][0];
        swap(v[a], v[b]);
        //cout << "_" << s1 << " " << s2 << "\n";
    }

    forf(i, 0, n*3) cout << v[i][1] << "\n";

    return 0;
}
