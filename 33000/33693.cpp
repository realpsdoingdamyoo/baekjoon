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
const vpii dir4={{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
const vpii dir8={{0, 1}, {1, 0}, {-1, 0}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
const ll inf=2147483647, linf=9223372036854775807;
const double pi=acos(-1), E=2.718281828459;
ll gcd(ll a, ll b){return b?gcd(b, a%b):a;}
#define cf cout.flush()

void solve(){
    string s; cin >> s;
    string p;

    ll n=s.length(), c=0, r=0;
    for(char i : s){
        if(i=='C') p+='(', c++;
        else{
            if(c) p+=')', c--;
            else p+='(', c++;
            r++;
        }
    }

    ll rr=0;
    forb(i, s.length(), 0){
        rr+=(p[i]==')')-(p[i]=='(');
        if(rr<0){
            p[i]=')'; rr+=2; r+=2;
        }
    }
    cout << r << "\n" << p << "\n";
}

int main(){
    fastio;

    ll t; cin >> t;
    while(t--) solve();


    return 0;
}
