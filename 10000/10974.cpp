#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef array<ll, 2> pii;
typedef vector<pii> vpii;
typedef double lf;
typedef priority_queue<ll> pql;
#define fastio; cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define vcin; for(int i=0; i<n; i++) cin >> v[i];
#define forf(i, s, e) for(int i=s; i<e; i++)
#define forb(i, s, e) for(int i=s-1; i>=e; i--)
#define pb push_back
#define sortv(v) sort(v.begin(), v.end())
#define sortc(v, cmp) sort(v.begin(), v.end(), cmp)
#define repeat(n) for(int not_used_name=0; not_used_name<n; not_used_name++)
const int mod=1e9+7, MOD=998244353;
const int dir4[4][2]={{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
const int dir8[8][2]={{0, 1}, {1, 0}, {-1, 0}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
const ll inf=2147483647, linf=9223372036854775807;
const double pi=acos(-1), eu=2.718281828459;
ll gcd(ll a, ll b){return b?gcd(b, a%b):a;}

vi v; ll n;

bool npm(){

    ll i=n-1;
    while(i && v[i]<v[i-1]) i--;
    if(i==0) return false; i--;
    ll x=v[i], ind=i;
    forf(j, i+1, n){
        if((v[j]<v[i] || v[i]==x) && v[j]>x) ind=j;
    }
    swap(v[i], v[ind]);
    reverse(v.begin()+i+1, v.end());
    return true;
}

int main() {
	fastio;

	cin >> n;
	v.resize(n);
	forf(i, 0, n) v[i]=i+1;
	do{
        forf(i, 0, n) cout << v[i] << " ";
        cout << "\n";
	}while(npm());


	return 0;
}
