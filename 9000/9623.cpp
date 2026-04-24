#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef array<ll, 2> pii;
typedef array<ll, 3> tii;
typedef vector<pii> vpii;
typedef __float128 lf;
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
#define cf cout.flush()

ll n, x;
vi v;

bool chk(ll len){
    PQ<ll> pq, dpq;
    pq.push(0);

    forf(i, 1, n){
        if(pq.top()+v[i]>=x) return true;
        if(i>=len) dpq.push(-v[i-len]);
        pq.push(-v[i]);

        while(dpq.size() && pq.top()==dpq.top()){
            pq.pop(); dpq.pop();
        }
    }

    return false;
}

void solve(){
    cin >> n >> x; n++;
    v.resize(n);
    forf(i, 1, n){
        cin >> v[i];
        v[i]+=v[i-1];
    }

    ll s=1, e=n;

    while(s<=e){
        ll m=(s+e)/2;
        if(chk(m)) e=m-1;
        else s=m+1;
    }

    if(s<=n) cout << s << "\n";
    else cout << "-1\n";
}

int main(){
    fastio;

    ll t; cin >> t;
    while(t--) solve();

    return 0;
}
