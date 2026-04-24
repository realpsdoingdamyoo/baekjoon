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

pii seg[1<<21];
ll fib[1<<20]={1, 2};

int main(){
    fastio;

    ll n; cin >> n;
    forf(i, 2, 1<<20) fib[i]=(fib[i-1]+fib[i-2])%mod;

    ll q; cin >> q;
    forf(i, 1, q+1){
        ll a, b, A; cin >> a >> b;
        A=a; a+=1048575; b+=1048575;
        while(a<b){
            if(a%2==1) seg[a]={i, A};
            a=(a+1)/2;
            if(b%2==0) seg[b]={i, A};
            b=(b-1)/2;
        }
        if(a==b) seg[a]={i, A};
    }
    forf(i, 1<<20, (1<<20)+n){
        ll I=i, ii=i-(1<<20)+1;
        pii x={0, 0};
        while(I){
            if(x[0]<seg[I][0]) x=seg[I];
            I/=2;
        }
        if(!x[0]) cout << "0 ";
        else cout << fib[ii-x[1]] << " ";
    }

    return 0;
}
