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

vi v(33);

int main() {
    fastio;

    ll n; cin >> n;
    repeat(n){
        ll k; cin >> k;
        forf(i, 0, 30) v[i]+=!!(k&(1<<i));
    }
    ll s=1;
    repeat(n){
        ll k=0;
        forf(i, 0, 30) k+=(v[i]-->0)<<i;
        s=s*k%mod;
    }
    cout << s << "\n";

    return 0;
}
