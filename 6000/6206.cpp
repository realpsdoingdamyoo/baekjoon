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

ll n, rpt;
vi s;
unordered_map<ll, ll> um;
ll b[2], h[2];
ll M[2]={mod, mod+2};
ll base=31;

bool hashing(ll len){
    um.clear();

    forf(i, 0, 2) b[i]=1, h[i]=s[0];
    forf(i, 1, len) forf(j, 0, 2){
        h[j]=(h[j]*base+s[i])%M[j];
        b[j]=b[j]*base%M[j];
    }

    um[h[0]<<32|h[1]]++;

    forf(i, len, n){
        forf(j, 0, 2){
            h[j]=(h[j]-s[i-len]*b[j]%M[j]+M[j])%M[j];
            h[j]=(h[j]*base+s[i])%M[j];
        }
        ll K=h[0]<<32|h[1];
        um[K]++;
        if(um[K]>=rpt) return true;
    }
    return false;
}

int main(){
    fastio;

    cin >> n >> rpt;
    s.resize(n);
    forf(i, 0, n) cin >> s[i];

    ll ss=0, e=n;
    while(ss<=e){
        ll m=(ss+e)/2;
        if(hashing(m)) ss=m+1;
        else e=m-1;
    }
    if(!e) e--;
    cout << e << "\n";

    return 0;
}
