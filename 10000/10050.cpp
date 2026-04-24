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
#define cf; cout.flush();

void sol(int n, int s){
	if(n==3){
        cout << s+1 << " to " << s-2 << "\n";
        cout << s+4 << " to " << s+1 << "\n";
        cout << s+2 << " to " << s-4 << "\n";
	}
	else if(n==4){
        cout << s+5 << " to " << s-2 << "\n";
        cout << s+2 << " to " << s+5 << "\n";
        cout << s-1 << " to " << s+2 << "\n";
        cout << s+6 << " to " << s-1 << "\n";
	}
	else if(n==5){
        cout << s+7 << " to " << s-2 << "\n";
        cout << s+2 << " to " << s+7 << "\n";
        cout << s+5 << " to " << s+2 << "\n";
        cout << s-1 << " to " << s+5 << "\n";
        cout << s+8 << " to " << s-1 << "\n";
	}
	else if(n==6){
        cout << s+9 << " to " << s-2 << "\n";
        cout << s+6 << " to " << s+9 << "\n";
        cout << s+1 << " to " << s+6 << "\n";
        cout << s+5 << " to " << s+1 << "\n";
        cout << s-1 << " to " << s+5 << "\n";
        cout << s+10 << " to " << s-1 << "\n";
	}
	else if(n==7){
	    cout << s+7 << " to " << s-2 << "\n";
        cout << s+4 << " to " << s+7 << "\n";
        cout << s+11 << " to " << s+4 << "\n";
        cout << s+2 << " to " << s+11 << "\n";
        cout << s+8 << " to " << s+2 << "\n";
        cout << s-1 << " to " << s+8 << "\n";
        cout << s+12 << " to " << s-1 << "\n";
	}

	else{
        cout << s+2*n-3 << " to " << s-2 << "\n";
        cout << s+2 << " to " << s+2*n-3 << "\n";
		sol(n-4, s+4);
        cout << s-1 << " to " << s+2*n-6 << "\n";
        cout << s+2*n-2 << " to " << s-1 << "\n";
	}
}

int main() {
    fastio;
	ll n; cin >> n;
	sol(n, 1);
    return 0;
}
