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
#define cf; cout.flush();

ll bp(ll n){
    ll ret=-1;
    for(ll i=2; i*i<=n; i++){
        while(n%i==0){
            n/=i; ret=i;
        }
    }
    return max(ret, n);
}

int main(){
    fastio;

    ll n, ret=1; cin >> n;

    while(n>1){
        ll p=bp(n);
        ll pc=0;
        while(n%p==0){
            n/=p; pc++;
        }
        if(pc%2==0 || n%(p-1)){
            cout << "-1";
            return 0;
        }

        n/=p-1;

        forf(i, 0, pc/2+1) ret*=p;
    }

    cout << ret;

    return 0;
}
