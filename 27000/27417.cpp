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

ll x=23471982383;

ll sm(ll p){
    ll ret=0;
    while(p){ret+=p%10; p/=10;}
    return ret;
}

int main(){
    fastio;

    ll n, ret=0;
    cout << "query 0\n"; cf;
    cin >> n;

    forf(i, 0, 18){
        ll s=1, e=9;
        while(s<=e){
            ll m=(s+e+1)/2;
            cout << "query ";
            ll q=10-m;
            forf(j, 0, i) q*=10;
            cout << q << "\n"; cf;

            ll a=sm(x+q); cin >> a;
            if(a==n+10-m) e=m-1;
            else s=m+1;
        }

        forf(j, 0, i) e*=10;
        ret+=e;
    }
    cout << "answer " << ret;


    return 0;
}
