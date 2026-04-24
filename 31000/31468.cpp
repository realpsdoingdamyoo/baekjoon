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
#define cf cout.flush()

void solve(ll n){
    if(n==0) return;
    if(n%12==11 || n%12==2){
        solve(n-2);
        forf(i, 0, n/3) cout << "RBB"; cout << "R\n";
        forf(i, 0, n/3) cout << "RRB"; cout << "RR\n";
    }
    else if(n%12==0){
        solve(n-3);
        forf(i, 0, n/2-1) cout << "BB"; cout << "\n";
        forf(i, 0, n/2-1) cout << "RB"; cout << "R\n";
        forf(i, 0, n/2-1) cout << "RR"; cout << "RR\n";
    }
    else{
        solve(n-9);
        forf(i, 0, n/2-4) cout << "BB"; cout << "R\n";
        forf(i, 0, n/2-4) cout << "RB"; cout << "RR\n";
        forf(i, 0, n/2-4) cout << "RR"; cout << "RBB\n";
        forf(i, 0, n/2-4) cout << "BB"; cout << "RRBR\n";
        forf(i, 0, n/2-4) cout << "RB"; cout << "RBBRR\n";
        forf(i, 0, n/2-4) cout << "RR"; cout << "RRBBBR\n";
        forf(i, 0, n/2-4) cout << "BB"; cout << "BBBBBRR\n";
        forf(i, 0, n/2-4) cout << "RB"; cout << "RBRBRBBR\n";
        forf(i, 0, n/2-4) cout << "RR"; cout << "RRRRRRBRR\n";
    }
}

int main(){
    fastio;

    ll n; cin >> n;
    solve(n);

    return 0;
}
